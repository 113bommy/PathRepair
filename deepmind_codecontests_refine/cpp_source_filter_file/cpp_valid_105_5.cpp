#include <bits/stdc++.h>
using namespace std;
template <class T>
ostream& operator<<(ostream& out, vector<T>& v) {
  out << "[";
  for (auto k : v) out << k << ",";
  out << "]"
      << "\n";
  return out;
}
template <class T>
ostream& operator<<(ostream& out, set<T> s) {
  out << "{";
  for (auto k : s) out << k << ",";
  out << "}"
      << "\n";
  return out;
}
template <class T, class U>
ostream& operator<<(ostream& out, pair<T, U> p) {
  out << "[ " << p.first << " , " << p.second << " ] ";
  return out;
}
template <class T, class U>
istream& operator>>(istream& in, pair<T, U>& p) {
  in >> p.first >> p.second;
  return in;
}
vector<int> app[(int)1e4];
int dp[3500][3500];
int a[4000];
int DP(int i, int j) {
  if (i >= j) return 0;
  if (dp[i][j] != -1) return dp[i][j];
  dp[i][j] = DP(i + 1, j);
  for (auto k : app[a[i]]) {
    if (k > i and k <= j)
      dp[i][j] = max(dp[i][j], 1 + DP(i + 1, k - 1) + DP(k, j));
  }
  return dp[i][j];
}
int main() {
  cin.tie(0);
  cin.sync_with_stdio(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    for (int i = 0; i < int(n); i++) {
      app[i].clear();
      for (int j = 0; j < int(n); j++) dp[i][j] = -1;
      cin >> a[i];
    }
    for (int i = 0; i < int(n); i++) app[a[i]].push_back(i);
    cout << n - 1 - DP(0, n - 1) << '\n';
  }
}
