#include <bits/stdc++.h>
using namespace std;
bool isprime(long long n) {
  if (n <= 1) return false;
  if (n <= 3) return true;
  if (n % 2 == 0 || n % 3 == 0) return false;
  for (long long i = 5; i * i <= n; i += 6) {
    if (n % i == 0 || n % (i + 2) == 0) return false;
  }
  return true;
}
long long modexp(long long a, long long b, long long m) {
  long long r = 1;
  a = a % m;
  while (b > 0) {
    if (b & 1) r = (r * a) % m;
    b = b >> 1;
    a = (a * a) % m;
  }
  return r % m;
}
struct CustomCompare {
  bool operator()(const int& lhs, const int& rhs) { return lhs < rhs; }
};
bool comp(pair<long long, long long> a, pair<long long, long long> b) {
  return a.first >= b.first;
}
long long builtin_popcount(long long x) {
  long long cnt = 0;
  for (long long i = 60; i >= 0; i--) {
    if ((1LL << i) & x) cnt++;
  }
  return cnt;
}
long long addmod(long long a, long long b) {
  a %= 1000000007;
  b %= 1000000007;
  return (a + b) % 1000000007;
}
long long mulmod(long long a, long long b) {
  a %= 1000000007;
  b %= 1000000007;
  return (a * b) % 1000000007;
}
const long long mxn = 105;
long long dp[mxn][mxn];
long long cnt[mxn][mxn][mxn];
vector<pair<long long, long long> > interval[mxn];
long long which[mxn][mxn];
long long n, m;
void fix(long long l, long long r) {
  vector<long long> temp(m + 2);
  for (int i = 1; i < n + 1; i++) {
    if (l != 1) {
      long long k = which[i][l - 1];
      long long x = interval[i][k].second;
      temp[x + 1]++;
    } else
      temp[1]++;
    if (r != m) {
      long long k = which[i][r + 1];
      long long x = interval[i][k].first;
      temp[x]--;
    } else
      temp[m + 1]--;
  }
  long long res = 0;
  for (int i = l; i < r + 1; i++) {
    res += temp[i];
    cnt[i][l][r] = res;
  }
}
long long solve(long long l, long long r) {
  if (dp[l][r] != -1) return dp[l][r];
  if (l > r) return 0;
  long long ans = 0;
  for (int i = l; i < r + 1; i++) {
    ans = max(ans,
              cnt[i][l][r] * cnt[i][l][r] + solve(l, i - 1) + solve(i + 1, r));
  }
  dp[l][r] = ans;
  return dp[l][r];
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m;
  for (int i = 1; i < n + 1; i++) {
    for (int j = 1; j < m + 1; j++) dp[i][j] = -1;
  }
  for (int i = 1; i < n + 1; i++) {
    long long k;
    cin >> k;
    for (int j = 0; j < k; j++) {
      long long l, r;
      cin >> l >> r;
      interval[i].push_back({l, r});
      for (int p = l; p < r + 1; p++) which[i][p] = j;
    }
  }
  for (int i = 1; i < m + 1; i++) {
    for (int j = i; j < m + 1; j++) fix(i, j);
  }
  cout << solve(1, m) << endl;
  return 0;
}
