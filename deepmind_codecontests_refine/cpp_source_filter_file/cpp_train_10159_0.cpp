#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using vl = vector<long long>;
using pii = pair<int, int>;
using vpii = vector<pair<int, int>>;
template <class T>
inline bool ckmin(T& a, T b) {
  return b < a ? a = b, 1 : 0;
}
template <class T>
inline bool ckmax(T& a, T b) {
  return b > a ? a = b, 1 : 0;
}
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const char nl = '\n';
const int mxN = 2e5 + 10;
const int MOD = 1e9 + 7;
const long long infLL = 1e18;
int n;
vector<string> a;
string second;
vector<vector<int>> can;
vector<int> dp;
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  a.resize(n);
  for (auto& A : a) cin >> A;
  cin >> second;
  can.resize((int)second.size(), vector<int>(n));
  dp.resize((int)second.size() + 1, MOD);
  for (int i = (0); i < ((int)second.size()); i++) {
    for (int j = (0); j < (n); j++) {
      int I = i;
      for (int k = (0); k < ((int)a[j].size()); k++) {
        if (I > (int)second.size()) break;
        if (a[j][k] == second[I]) {
          I++;
        }
      }
      can[i][j] = I - i;
    }
  }
  dp[0] = 0;
  for (int i = (0); i < ((int)second.size()); i++) {
    for (int j = (0); j < (n); j++) {
      ckmin(dp[i + can[i][j]], dp[i] + 1);
    }
  }
  if (dp[(int)second.size()] > n)
    cout << -1 << nl;
  else
    cout << dp[(int)second.size()] << nl;
  return 0;
}
