#include <bits/stdc++.h>
using namespace std;
const long long INF_LL = 1e18;
const int INF = 1e9 + 100;
const int MOD = 998244353;
const long double EPS = 1e-10;
const int BLOCK = 550;
const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, 1, 0, -1};
mt19937 rnd(chrono::system_clock::now().time_since_epoch().count());
void open_file() {}
const int maxN = 6e5 + 100;
void sol() {
  int n, m;
  cin >> n >> m;
  vector<int> L(n), R(n);
  for (int i = 0; i < n; i++) cin >> L[i] >> R[i];
  auto calc = [&](int x) {
    for (int i = 0; i < n; i++) {
      int a = (L[i] + x - 1) / x;
      int b = R[i] / x;
      if (a > b || b == 0) return 0;
    }
    int nm = m / x;
    vector<int> dp(nm + 1, 0);
    dp[0] = 1;
    for (int i = 0; i < n; i++) {
      int a = (L[i] + x - 1) / x;
      int b = R[i] / x;
      if (a > b) return 0;
      vector<int> n_dp(nm + 1, 0);
      for (int j = 0; j + a <= nm; j++) {
        int na = j + a;
        int nb = j + b;
        n_dp[na] = (n_dp[na] + dp[j]) % MOD;
        if (nb < nm) n_dp[nb + 1] = (n_dp[nb + 1] - dp[j] + MOD) % MOD;
      }
      swap(n_dp, dp);
      for (int i = 1; i <= nm; i++) dp[i] = (dp[i - 1] + dp[i]) % MOD;
      if (*max_element(dp.begin(), dp.end()) == 0) return 0;
    }
    int ans = 0;
    for (int i = 0; i <= nm; i++) ans = (ans + dp[i]) % MOD;
    return ans;
  };
  vector<int> F(m + 1);
  for (int i = 1; i <= m; i++) F[i] = calc(i);
  for (int i = m; i >= 1; i--) {
    for (int j = i + i; j <= m; j += i) F[i] = (F[i] - F[j] + MOD) % MOD;
  }
  cout << F[1];
}
void solve() {
  int T = 1;
  int TestCase = 0;
  while (T--) {
    TestCase += 1;
    sol();
  }
}
int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);
  cout.tie(nullptr);
  open_file();
  solve();
  return 0;
}
