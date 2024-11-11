#include <bits/stdc++.h>
using namespace std;
const int inf = 1000000007;
const long long linf = 1000000000000000000LL;
const double pi = 3.14159265358979323846;
template <class T>
T abs(T k) {
  return k >= 0 ? k : -k;
}
template <class T>
T sqr(T n) {
  return n * n;
}
template <class T>
T gcd(T a, T b) {
  return b ? gcd(b, a % b) : a;
}
template <class T>
T mod(T a, T b) {
  return (a % b + b) % b;
}
template <class T>
void mode(T &a, T b) {
  a = mod(a, b);
}
template <class T>
void maxe(T &a, T b) {
  a = max(a, b);
}
template <class T>
void mine(T &a, T b) {
  a = min(a, b);
}
void fileio_in_out() {
  freopen(".in", "r", stdin);
  freopen(".out", "w", stdout);
}
void fileio_txt() {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
}
int n, q, t, x, y;
int a[333], f[333], e[333][333], d[333], dp[111111];
int ans() {
  for (int k = 1; k <= n; k++)
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= n; j++)
        if (e[i][k] && e[k][j]) e[i][k] = 1;
  for (int i = 1; i <= n; i++)
    if (e[i][i]) return 0;
  for (int k = 1; k <= n; k++)
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= n; j++)
        if (e[i][j]) maxe(d[i], d[j] + 1);
  for (int i = 1; i <= n; i++) {
    t -= a[i] * d[i];
    if (t < 0) return 0;
  }
  for (int i = 1; i <= n; i++) f[i] = a[i];
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++)
      if (e[i][j]) f[j] += a[i];
  dp[0] = 1;
  for (int i = 1; i <= n; i++)
    for (int j = f[i]; j <= t; j++) dp[j] = (dp[j] + dp[j - f[i]]) % inf;
  return dp[t];
}
int main() {
  scanf("%d%d%d", &n, &q, &t);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  while (q--) {
    scanf("%d%d", &x, &y);
    e[x][y] = 1;
  }
  printf("%d\n", ans());
  return 0;
}
