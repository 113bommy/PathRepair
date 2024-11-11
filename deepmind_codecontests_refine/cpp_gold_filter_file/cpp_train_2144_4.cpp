#include <bits/stdc++.h>
using namespace std;
template <class T>
inline T bigmod(T p, T e, T M) {
  long long int ret = 1;
  for (; e > 0; e >>= 1) {
    if (e & 1) ret = (ret * p) % M;
    p = (p * p) % M;
  }
  return (T)ret;
}
template <class T>
inline T bpow(T p, T e) {
  unsigned long long int ret = 1;
  for (; e > 0; e >>= 1) {
    if (e & 1) ret = (ret * p);
    p = (p * p);
  }
  return (T)ret;
}
template <class T>
inline T gcd(T a, T b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
template <class T>
inline T modinverse(T a, T M) {
  return bigmod(a, M - 2, M);
}
int toInt(string s) {
  int sm;
  stringstream ss(s);
  ss >> sm;
  return sm;
}
int toLlint(string s) {
  long long int sm;
  stringstream ss(s);
  ss >> sm;
  return sm;
}
int ts, kk = 1;
int n, m;
int ds[82][82];
int p[2][82][82][82];
bool vs[2][82][82][82];
int dp(bool g, int l, int r, int rq) {
  if (rq == 0) return 0;
  int &pr = p[g][l][r][rq];
  if (vs[g][l][r][rq]) return pr;
  vs[g][l][r][rq] = 1;
  pr = (1 << 25);
  int mn, mx;
  mn = (g == 0) ? l + 1 : l;
  mx = (g == 1) ? r - 1 : r;
  int u = (g == 0) ? l : r;
  for (int j = mn; j <= mx; j++) {
    if (ds[u][j] == (1 << 25)) continue;
    pr = min(pr, dp(1, mn, j, rq - 1) + ds[u][j]);
    pr = min(pr, dp(0, j, mx, rq - 1) + ds[u][j]);
  }
  return pr;
}
int main() {
  int t, i, j, k;
  scanf("%d%d", &n, &m);
  for (i = 0; i < n; i++)
    for (j = 0; j < n; j++) ds[i][j] = ((i == j) ? 0 : (1 << 25));
  scanf("%d", &ts);
  while (ts--) {
    scanf("%d%d%d", &j, &k, &t);
    j--, k--;
    ds[j][k] = min(ds[j][k], t);
  }
  t = (1 << 25);
  for (i = 0; i < n; i++) {
    t = min(t, dp(1, 0, i, m - 1));
    t = min(t, dp(0, i, n - 1, m - 1));
  }
  if (t >= (1 << 25)) t = -1;
  printf("%d\n", t);
  return 0;
}
