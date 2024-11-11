#include <bits/stdc++.h>
using namespace std;
const int N = 5e3 + 5;
const int MOD = 998244353;
int ADD(int x, int y) { return x + y >= MOD ? x + y - MOD : x + y; }
int TIME(int x, int y) { return (int)(1ll * x * y % MOD); }
int ksm(int x, int k = MOD - 2) {
  int res = 1;
  for (; k; k >>= 1, x = TIME(x, x))
    if (k & 1) res = TIME(res, x);
  return res;
}
int n, m = 0, k, a[N], b[N];
int fact[N], ifact[N];
int C(int n, int m) {
  if (n < 0 || m < 0 || n - m < 0) return 0;
  return TIME(fact[n], TIME(ifact[m], ifact[n - m]));
}
struct Seg {
  int l, r, data;
};
bool operator<(Seg a, Seg b) { return a.l > b.l; }
priority_queue<Seg> q;
int main() {
  cin >> n >> k;
  fact[0] = 1;
  for (int i = 1; i <= n; ++i) fact[i] = TIME(fact[i - 1], i);
  ifact[n] = ksm(fact[n]);
  for (int i = n; i >= 1; --i) ifact[i - 1] = TIME(ifact[i], i);
  a[0] = a[n + 1] = 1;
  for (int i = 1; i <= n; ++i) scanf("%1d", &a[i]), b[i] = b[i - 1] + a[i];
  for (int i = 1; i <= n; ++i) {
    for (int j = i, cnt = a[i]; j <= n; ++j, cnt += a[j])
      if (cnt == k && a[i - 1] == 1 && a[j + 1] == 1)
        q.push((Seg){i, j, C(j - i + 1, k)});
  }
  if (!k || q.empty()) return printf("1\n"), 0;
  while (q.size() > 1) {
    Seg f = q.top();
    q.pop();
    Seg g = q.top();
    q.pop();
    Seg h = (Seg){
        f.l, g.r,
        ADD(ADD(f.data, g.data), MOD - C(f.r - g.l + 1, b[f.r] - b[g.l - 1]))};
    q.push(h);
  }
  return printf("%d\n", q.top().data), 0;
}
