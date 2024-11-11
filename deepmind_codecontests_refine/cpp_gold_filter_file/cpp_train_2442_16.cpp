#include <bits/stdc++.h>
using namespace std;
template <class A, class B>
ostream &operator<<(ostream &out, const pair<A, B> &a) {
  return out << "(" << a.first << "," << a.second << ")";
}
template <class A>
ostream &operator<<(ostream &out, const vector<A> &a) {
  for (const A &it : a) out << it << " ";
  return out;
}
template <class A, class B>
istream &operator>>(istream &in, pair<A, B> &a) {
  return in >> a.first >> a.second;
}
template <class A>
istream &operator>>(istream &in, vector<A> &a) {
  for (A &i : a) in >> i;
  return in;
}
long long poww(const long long &a, long long b,
               const long long &m = 1000000007) {
  if (b == 0) return 1;
  long long x = poww(a, b / 2, m);
  x = x * x % m;
  if (b & 1) x = x * a % m;
  return x;
}
long long ceil(const long long &a, const long long &b) {
  return (a + b - 1) / b;
}
long long n, k;
long long v[6][1001];
long long id[6][1001];
long long dp[1001][1001];
long long f(long long i, long long lst) {
  if (i > n) return 0;
  long long &ans = dp[i][lst];
  if (ans != -(1e18)) return ans;
  ans = f(i + 1, lst);
  bool ok = 1;
  for (long long j = 1; j <= k; j++) ok &= (id[j][v[1][lst]] <= id[j][v[1][i]]);
  if (ok) ans = max(ans, 1 + f(i + 1, i));
  return ans;
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  for (long long i = 0; i < 1001; i++)
    for (long long j = 0; j < 1001; j++) dp[i][j] = -(1e18);
  cin >> n >> k;
  for (long long i = 1; i <= k; i++) {
    for (long long j = 1; j <= n; j++) {
      cin >> v[i][j];
      id[i][v[i][j]] = j;
    }
  }
  cout << f(1, 0);
}
