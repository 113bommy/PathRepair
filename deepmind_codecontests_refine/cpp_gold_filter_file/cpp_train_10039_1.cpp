#include <bits/stdc++.h>
using namespace std;
const long long INF = 1LL << 60;
long long powmod(long long a, long long b) {
  long long res = 1;
  a %= 1000000007;
  for (; b; b >>= 1) {
    if (b & 1) res = res * a % 1000000007;
    a = a * a % 1000000007;
  }
  return res;
}
template <typename T>
inline bool chkmin(T &a, const T &b) {
  return a > b ? a = b, 1 : 0;
}
template <typename T>
inline bool chkmax(T &a, const T &b) {
  return a < b ? a = b, 1 : 0;
}
int read() {
  int x = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return x * f;
}
map<int, int> vis;
int a[210000], mx[210000];
int a1[210000], a2[210000];
long long mi[210000 << 2], val[210000 << 2];
int n;
struct node {
  int l, r, v;
};
stack<node> s1, s2;
void update(int rt, int ll, int rr, int l, int r, long long v) {
  if (ll == l && rr == r) {
    val[rt] += v;
    mi[rt] += v;
    return;
  }
  if (r <= ((ll + rr) / 2))
    update((rt << 1), ll, ((ll + rr) / 2), l, r, v);
  else if (l > ((ll + rr) / 2))
    update(((rt << 1) | 1), ((ll + rr) / 2) + 1, rr, l, r, v);
  else
    update((rt << 1), ll, ((ll + rr) / 2), l, ((ll + rr) / 2), v),
        update(((rt << 1) | 1), ((ll + rr) / 2) + 1, rr, ((ll + rr) / 2) + 1, r,
               v);
  mi[rt] = min(mi[(rt << 1)], mi[((rt << 1) | 1)]) + val[rt];
}
int query(int rt, int ll, int rr, int v) {
  if (ll == rr) return ll;
  v -= val[rt];
  if (mi[((rt << 1) | 1)] <= v)
    return query(((rt << 1) | 1), ((ll + rr) / 2) + 1, rr, v);
  return query((rt << 1), ll, ((ll + rr) / 2), v);
}
int main() {
  n = read();
  int k = read(), d = read();
  for (int i = 1; i <= n; i++) {
    a[i] = read() + 1e9 + 1;
    if (d != 0) {
      a1[i] = a[i] / d;
      a2[i] = a[i] % d;
    }
  }
  if (d == 0) {
    int ans = 0;
    int L, R;
    for (int l = 1, r = 1; l <= n; l = r) {
      for (; r <= n; r++)
        if (a[l] != a[r]) break;
      if (r - l > ans) {
        ans = r - l;
        L = l;
        R = r - 1;
      }
    }
    cout << L << " " << R << endl;
    return 0;
  }
  int l = 1, r = 1;
  for (; l <= n; l++) {
    for (; r <= n; r++)
      if (vis[a1[r]] == 1)
        break;
      else
        vis[a1[r]] = 1;
    mx[l] = r - 1;
    vis[a1[l]] = 0;
  }
  for (l = 1, r = 1; l <= n;) {
    for (; r <= n; r++)
      if (a2[l] != a2[r]) break;
    for (; l < r; l++) chkmin(mx[l], r - 1);
  }
  int ans = 0;
  int L, R;
  update(1, 1, n, 1, n, 210000);
  int xx = n;
  for (int i = n; i; i--) {
    node now = (node){i, i, a1[i]};
    if (mx[i] < xx) {
      update(1, 1, n, mx[i] + 1, xx, INF), xx = mx[i];
    }
    while (!s1.empty()) {
      node tmp = s1.top();
      if (tmp.v >= a1[i])
        break;
      else {
        now.r = tmp.r;
        if (now.v - tmp.v) update(1, 1, n, tmp.l, tmp.r, now.v - tmp.v);
        s1.pop();
      }
    }
    s1.push(now);
    now = (node){i, i, a1[i]};
    while (!s2.empty()) {
      node tmp = s2.top();
      if (tmp.v <= a1[i])
        break;
      else {
        now.r = tmp.r;
        if (tmp.v - now.v) update(1, 1, n, tmp.l, tmp.r, tmp.v - now.v);
        s2.pop();
      }
    }
    s2.push(now);
    update(1, 1, n, i, i, -i - 210000);
    int rr = query(1, 1, n, k - i);
    if (rr - i + 1 >= ans) {
      ans = rr - i + 1;
      L = i;
      R = rr;
    }
  }
  cout << L << " " << R << endl;
  return 0;
}
