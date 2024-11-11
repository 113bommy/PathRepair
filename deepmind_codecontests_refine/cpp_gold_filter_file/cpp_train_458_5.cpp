#include <bits/stdc++.h>
using namespace std;
const int MAXN = 412345;
const int MAXINT = 2047483098;
const long long int MOD = 998244353;
const int MAX = 1e4;
const long double pi = 2 * acosl(0);
const long double EPS = 1e-10;
int gcd(int a, int b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
bool comp(pair<long long int, long long int> &a,
          pair<long long int, long long int> &b) {
  return a.second < b.second;
}
long long power(long long a, long long b, long long m = MOD) {
  a %= m;
  long long res = 1;
  while (b > 0) {
    if (b & 1) res = res * a % m;
    a = a * a % m;
    b >>= 1;
  }
  return res;
}
long long int val(long long int n) { return n / 2 + (n % 2 ? 1 : 0); }
void solve() {
  map<long long int, long long int> mp;
  long long int n, m;
  cin >> n >> m;
  long long int dp[n + 1][m + 1];
  dp[0][0] = 0;
  for (int i = 1; i <= n; i++) {
    dp[i][1] = i / 2 + (i % 2 ? 1 : 0);
  }
  for (int i = 1; i <= m; i++) {
    dp[1][i] = i / 2 + (i % 2 ? 1 : 0);
  }
  for (int i = 0; i <= n; i++) dp[i][0] = 0;
  for (int i = 0; i <= m; i++) dp[0][i] = 0;
  for (int i = 2; i <= n; i++) {
    for (int j = 2; j <= m; j++) {
      dp[i][j] = 2 * j + (i - 2) * 2;
      dp[i][j] /= 2;
    }
  }
  int v = 1;
  int x = n, y = m;
  while (x > 0 && y > 0) {
    mp[v] = dp[x][y];
    v++;
    x -= 2, y -= 2;
  }
  long long int p;
  cin >> p;
  if (mp.count(p))
    cout << mp[p];
  else
    cout << "0";
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int T = 1;
  while (T--) {
    solve();
    cout << '\n';
  }
  return 0;
}
