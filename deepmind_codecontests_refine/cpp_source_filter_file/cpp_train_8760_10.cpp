#include <bits/stdc++.h>
using namespace std;
const long long INF = 1e18;
template <typename T>
inline T read() {
  register T sum = 0;
  register char cc = getchar();
  int sym = 1;
  while (cc != '-' && (cc > '9' || cc < '0')) cc = getchar();
  if (cc == '-') sym = -1, cc = getchar();
  sum = sum * 10 + cc - '0';
  cc = getchar();
  while (cc >= '0' && cc <= '9') sum = sum * 10 + cc - '0', cc = getchar();
  return sym * sum;
}
template <typename T>
inline T read(T &a) {
  a = read<T>();
  return a;
}
template <typename T, typename... Others>
inline void read(T &a, Others &...b) {
  a = read(a);
  read(b...);
}
struct Node {
  int len;
  long long sum;
  vector<long long> v;
} node[1000010 << 2];
int n, m, p, a[1000010];
void merge(int k) {
  for (int x = 0, y = 0; x <= node[k << 1].len; x++) {
    if (y) y -= 1;
    while (y <= node[k << 1 | 1].len) {
      if (node[k << 1].v[x + 1] - 1 - 1ll * x * p + node[k << 1].sum <
          node[k << 1 | 1].v[y]) {
        if (y) y -= 1;
        break;
      }
      long long t = node[k << 1 | 1].v[y] + 1ll * x * p - node[k << 1].sum;
      node[k].v[x + y] = min(node[k].v[x + y], max(node[k << 1].v[x], t));
      y += 1;
    }
  }
}
void build(int k, int l, int r) {
  node[k].len = r - l + 1;
  node[k].v.resize(r - l + 2, INF);
  node[k].v[0] = -INF;
  if (l == r) {
    node[k].sum = a[l];
    node[k].v[1] = p - a[l];
    return;
  }
  int mid = (l + r) >> 1;
  build(k << 1, l, mid);
  build(k << 1 | 1, mid + 1, r);
  node[k].sum = node[k << 1].sum + node[k << 1 | 1].sum;
  merge(k);
}
void query(int k, int l, int r, int x, int y, long long &ans) {
  if (l >= x && r <= y) {
    int t = upper_bound(node[k].v.begin(), node[k].v.end(), ans) -
            node[k].v.begin() - 1;
    ans += node[k].sum - 1ll * t * p;
    return;
  }
  int mid = (l + r) >> 1;
  if (y <= mid) return query(k << 1, l, mid, x, y, ans);
  if (x > mid) return query(k << 1 | 1, mid + 1, r, x, y, ans);
  query(k << 1, l, mid, x, y, ans);
  query(k << 1 | 1, mid + 1, r, x, y, ans);
}
int main() {
  read(n, m, p);
  for (int i = 1; i <= n; i++) read(a[i]);
  build(1, 1, n);
  for (int i = 1; i <= m; i++) {
    int l, r;
    read(l, r);
    long long ans = 0;
    query(1, 1, n, l, r, ans);
    printf("%lld\n", ans);
  }
  return 0;
}
