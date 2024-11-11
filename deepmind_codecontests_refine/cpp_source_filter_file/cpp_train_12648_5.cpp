#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int gi() {
  int x = 0, o = 1;
  char ch = getchar();
  while (!isdigit(ch) && ch != '-') ch = getchar();
  if (ch == '-') o = -1, ch = getchar();
  while (isdigit(ch)) x = x * 10 + ch - '0', ch = getchar();
  return x * o;
}
int n, key[N], siz[N], ls[N], rs[N], tt = 0, rt;
long long dp[N], tag_k[N], tag_b[N];
int newnode(long long v) {
  ++tt;
  key[tt] = rand();
  siz[tt] = 1;
  dp[tt] = v;
  return tt;
}
void pushup(int x) { siz[x] = siz[ls[x]] + siz[rs[x]] + 1; }
void modify(int x, long long k, long long b) {
  if (!x) return;
  dp[x] += k * (siz[ls[x]] + 1) + b;
  tag_k[x] += k, tag_b[x] += b;
}
void pushdown(int x) {
  if (tag_k[x] || tag_b[x]) {
    modify(ls[x], tag_k[x], tag_b[x]);
    modify(rs[x], tag_k[x], tag_b[x] + tag_k[x] * (siz[ls[x]] + 1));
    tag_k[x] = tag_b[x] = 0;
  }
}
int merge(int a, int b) {
  if (!a || !b) return a | b;
  if (key[a] < key[b]) {
    pushdown(a);
    rs[a] = merge(rs[a], b);
    pushup(a);
    return a;
  } else {
    pushdown(b);
    ls[b] = merge(a, ls[b]);
    pushup(b);
    return b;
  }
}
pair<int, int> split(int x, int k) {
  if (!x) return make_pair(0, 0);
  pair<int, int> y;
  pushdown(x);
  if (siz[ls[x]] >= k) {
    y = split(ls[x], k);
    ls[x] = y.second;
    pushup(x);
    y.second = x;
  } else {
    y = split(rs[x], k - siz[ls[x]] - 1);
    rs[x] = y.first;
    pushup(x);
    y.first = x;
  }
  return y;
}
long long getdp(int k) {
  pair<int, int> x = split(rt, k);
  pair<int, int> y = split(x.second, 1);
  long long ret = dp[y.first];
  rt = merge(merge(x.first, y.first), y.second);
  return ret;
}
int main() {
  cin >> n;
  rt = newnode(0);
  for (int i = 1, a; i <= n; i++) {
    a = gi();
    int l = 0, r = i - 1;
    while (l < r) {
      int mid = (l + r + 1) >> 1;
      if (!mid || getdp(mid) > getdp(mid - 1) + mid * a)
        l = mid;
      else
        r = mid - 1;
    }
    pair<int, int> x = split(rt, l + 1);
    pair<int, int> y = split(x.first, l);
    int z = newnode(dp[y.second]);
    x.second = merge(z, x.second);
    modify(x.second, a, 1ll * l * a);
    rt = merge(merge(y.first, y.second), x.second);
  }
  long long ans = 0;
  for (int i = 0; i <= n; i++) ans = max(ans, getdp(i));
  cout << ans;
  return 0;
}
