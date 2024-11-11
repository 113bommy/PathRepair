#include <bits/stdc++.h>
using namespace std;
template <typename T>
inline T qmin(const T &a, const T &b) {
  return a < b ? a : b;
}
template <typename T>
inline T qmax(const T &a, const T &b) {
  return a > b ? a : b;
}
template <typename T>
inline void getmin(T &a, const T &b) {
  if (a > b) a = b;
}
template <typename T>
inline void getmax(T &a, const T &b) {
  if (a < b) a = b;
}
inline void fileio(string s) {
  freopen((s + ".in").c_str(), "r", stdin);
  freopen((s + ".out").c_str(), "w", stdout);
}
const int inf = (int)1e9 + 7;
const long long linf = (long long)1e17 + 7;
const int N = 4e5 + 7, logN = 21, Node = N * logN;
int sum[Node], lch[Node], rch[Node], node;
inline int newnode(int &u) {
  int v = ++node;
  sum[v] = sum[u];
  lch[v] = lch[u];
  rch[v] = rch[u];
  return v;
}
inline void ins(int &u, int l, int r, int p) {
  u = newnode(u);
  ++sum[u];
  if (l == r) return;
  int mid = l + r >> 1;
  if (p <= mid)
    ins(lch[u], l, mid, p);
  else
    ins(rch[u], mid + 1, r, p);
}
inline int qsum(int u, int l, int r, int l1, int r1) {
  if (l1 > r1) return 0;
  if (!u || l1 <= l && r <= r1) return sum[u];
  int mid = l + r >> 1, ans = 0;
  if (l1 <= mid) ans += qsum(lch[u], l, mid, l1, r1);
  if (r1 > mid) ans += qsum(rch[u], mid + 1, r, l1, r1);
  return ans;
}
inline long long c2(long long x) { return x * (x - 1) / 2; }
int p[N], rt[N], n, q;
int main() {
  scanf("%d%d", &n, &q);
  for (register int i = (1); i <= (n); ++i) {
    rt[i] = rt[i - 1];
    scanf("%d", p + i);
    ins(rt[i], 1, n, p[i]);
  }
  while (q--) {
    int l, r, d, u;
    scanf("%d%d%d%d", &l, &d, &r, &u);
    long long ans = c2(n);
    long long tot1 = qsum(rt[n], 1, n, u + 1, n),
              tot2 = qsum(rt[n], 1, n, 1, d - 1);
    long long s1 = qsum(rt[l - 1], 1, n, u + 1, n);
    long long s2 = tot1 - qsum(rt[r], 1, n, u + 1, n);
    long long s3 = qsum(rt[l - 1], 1, n, 1, d - 1);
    long long s4 = tot2 - qsum(rt[r], 1, n, 1, d - 1);
    ans -= c2(l - 1) + c2(n - r) + c2(tot1) + c2(tot2) - c2(s1) - c2(s2) -
           c2(s3) - c2(s4);
    printf("%lld\n", ans);
  }
  return 0;
}
