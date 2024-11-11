#include <bits/stdc++.h>
using namespace std;
template <class T>
inline bool chmax(T &a, T b) {
  if (a < b) {
    a = b;
    return true;
  }
  return false;
}
template <class T>
inline bool chmin(T &a, T b) {
  if (a > b) {
    a = b;
    return true;
  }
  return false;
}
const long double EPS = 1e-10;
const long long INF = 1e18;
const long double PI = acos(-1.0L);
int dp[405];
string S, T;
bool f(int s) {
  for (int i = 0; i <= 402; i++) {
    dp[i] = -1e9;
  }
  dp[0] = 0;
  for (int i = 0; i < S.size(); i++) {
    for (int j = s; j >= 0; j--) {
      if (dp[j] == -1e9) continue;
      if (j < s) {
        if (S[i] == T[j]) {
          chmax(dp[j + 1], dp[j]);
        }
      }
      if (j + dp[i] < T.size()) {
        if (S[i] == T[j + dp[i]]) {
          dp[j]++;
        }
      }
    }
  }
  if (dp[s] == T.size() - s) return true;
  return false;
}
void solve() {
  cin >> S >> T;
  for (int i = 0; i < S.size(); i++) {
    if (f(i)) {
      cout << "YES" << endl;
      return;
    }
  }
  cout << "NO" << endl;
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) solve();
  return 0;
}
