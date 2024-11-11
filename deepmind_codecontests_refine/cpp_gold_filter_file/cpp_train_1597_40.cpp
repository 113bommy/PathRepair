#include <bits/stdc++.h>
using namespace std;
const int Nmax = 201, MOD = 1e9 + 7;
ifstream infile;
ofstream outfile;
template <class T>
void inline Scan(vector<T> &arr) {
  for (auto &i : arr) cin >> i;
}
template <class T>
void inline Print(vector<T> &arr, char c) {
  for (auto &i : arr) cout << fixed << setprecision(7) << i << c;
}
template <class T>
istream &operator>>(istream &in, pair<T, T> &p) {
  in >> p.first >> p.second;
  return in;
}
template <class T>
ostream &operator<<(ostream &out, pair<T, T> &p) {
  out << p.first << ' ' << p.second;
  return out;
}
template <class T>
void swap(pair<T, T> &p) {
  swap(p.first, p.second);
}
template <class T>
T gcd(T a, T b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
long long power(long long x, int y) {
  long long ans = 1;
  while (y) {
    if (y % 2 == 1) ans = (ans * x) % MOD;
    x = (x * x) % MOD;
    y = y / 2;
  }
  return ans;
}
template <class T>
T solve() {
  int n, l, K;
  cin >> n >> l >> K;
  vector<double> p(n);
  vector<int> a(n);
  double dp[n + 1][Nmax + 1][Nmax + 1];
  for (auto &i : p) {
    cin >> i;
    i *= 0.01;
  }
  for (auto &i : a) cin >> i;
  for (auto i = 0; i != n + 1; i++)
    for (auto j = 0; j != Nmax + 1; j++)
      for (auto k = 0; k != Nmax + 1; k++) dp[i][j][k] = 0.0;
  dp[0][0][K] = 1.0;
  for (auto i = 0; i != n; i++)
    for (auto j = 0; j != Nmax; j++)
      for (auto k = 0; k != Nmax; k++) {
        dp[i + 1][j][k] += dp[i][j][k] * (1 - p[i]);
        if (a[i] != -1) {
          dp[i + 1][j + 1][min(Nmax - 1, k + a[i] + 1)] += dp[i][j][k] * p[i];
        } else
          dp[i + 1][j + 1][k] += dp[i][j][k] * p[i];
      }
  double ans = 0;
  for (auto j = l; j != Nmax; j++)
    for (auto k = j; k != Nmax; k++) ans += dp[n][j][k];
  cout << fixed << setprecision(12) << ans;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int T = 1;
  vector<int> ans(T);
  for (auto t = 0; t != T; t++) {
    solve<void>();
  }
  return 0;
}
