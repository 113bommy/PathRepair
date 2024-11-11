#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
int debug;
int const MAXN = 1e3 + 5;
int const MAXA = 2e5 + 3;
int const INF = 1e9;
ll const LLINF = 1e17;
ll const MOD = 1e9 + 9;
double const EPS = 1e-9;
bool TESTS = false;
class Matrix {
 public:
  int n;
  vector<vector<ll>> M;
  Matrix(int nn) {
    M.assign(nn, vector<ll>(nn));
    n = nn;
  }
  vector<ll> &operator[](int n) { return M[n]; }
};
Matrix operator*(Matrix A, Matrix B) {
  int n = A.n;
  Matrix C(n);
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      for (int k = 0; k < n; k++)
        C[i][j] = (C[i][j] + (A[i][k] * B[k][j]) % MOD) % MOD;
  return C;
}
Matrix binPow(Matrix A, ll k) {
  int n = A.n;
  Matrix B(n);
  for (int i = 0; i < n; i++) B[i][i] = 1;
  while (k > 0) {
    if (k & 1) B = B * A;
    A = A * A;
    k /= 2;
  }
  return B;
}
int c(char c) { return (c < 'a' ? c - 'A' + 26 : c - 'a'); }
void solve() {
  int n, m, k;
  cin >> n >> m >> k;
  Matrix dp(m);
  for (int i = 0; i < m; i++)
    for (int j = 0; j < m; j++) dp[i][j] = 1;
  for (int i = 0; i < k; i++) {
    string s;
    cin >> s;
    dp[c(s[0])][c(s[1])] = 0;
  }
  if (n == 1) {
    cout << m << endl;
    return;
  }
  dp = binPow(dp, n - 1);
  ll ans = 0;
  for (int i = 0; i < m; i++)
    for (int j = 0; j < m; j++) ans = (ans + dp[i][j]) % MOD;
  cout << ans << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cout.tie(0);
  cin.tie(0);
  int t = 1;
  if (TESTS) cin >> t;
  while (t-- > 0) solve();
  return 0;
}
