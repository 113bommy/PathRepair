#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using ull = unsigned long long;
using pii = pair<int, int>;
using C = complex<double>;
const double PI = 3.14159265;
const double eps = 1e-8;
const int N = 1e6 + 10;
const int M = 998244353;
const int inf = 1e9 + 7;
const ll INF = 1e18;
ll pw(ll a, ll b) {
  ll t = 1;
  a %= M;
  for (; b; b >>= 1) {
    if (b & 1) {
      t = t * a % M;
    }
    a = a * a % M;
  }
  return t;
}
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
int n;
int p[N];
ll dp[N][3];
ll add(ll a, ll b) { return (a + b) % M; }
ll mul(ll a, ll b) { return a * b % M; }
vector<int> g[N];
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n;
  int x;
  for (int i = 2; i <= n; i++) {
    cin >> x;
    g[x].push_back(i);
  }
  ll a[3];
  for (int i = n; i >= 1; i--) {
    if (!((int)(g[i].size()))) {
      dp[i][2] = 1;
    } else {
      dp[i][0] = 1;
      for (int j : g[i]) {
        a[0] = a[1] = a[2] = 0;
        a[0] = add(a[0], mul(dp[i][0], dp[j][0]));
        a[1] = add(a[1], mul(dp[i][0], dp[j][1]));
        a[0] = add(a[0], mul(dp[i][0], dp[j][2]));
        a[1] = add(a[1], mul(dp[i][0], dp[j][2]));
        a[1] = add(a[1], mul(dp[i][1], dp[j][0]));
        a[2] = add(a[2], mul(dp[i][1], dp[j][1]));
        a[1] = add(a[1], mul(dp[i][1], dp[j][2]));
        a[2] = add(a[2], mul(dp[i][1], dp[j][2]));
        a[2] = add(a[2], mul(dp[i][2], dp[j][0]));
        a[2] = add(a[2], mul(dp[i][2], dp[j][1]));
        a[2] = add(a[2], mul(dp[i][2], dp[j][2]));
        a[2] = add(a[2], mul(dp[i][2], dp[j][2]));
        for (int j = 0; j < 3; j++) dp[i][j] = a[j];
      }
    }
  }
  cout << (dp[1][0] + dp[1][2]) % M << "\n";
}
