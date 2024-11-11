#include <bits/stdc++.h>
using namespace std;
template <typename T>
std::ostream &operator<<(std::ostream &out, vector<T> &v) {
  for (typename vector<T>::size_type i = 0; i < v.size(); ++i)
    out << v[i] << " ";
  out << "\n";
  return out;
}
template <typename T>
std::ostream &operator<<(std::ostream &out, set<T> &s) {
  for (auto e : s) out << e << " ";
  out << "\n";
  return out;
}
template <typename T, typename N>
std::ostream &operator<<(std::ostream &out, pair<T, N> &p) {
  out << "(" << p.first << ", " << p.second << ") ";
  return out;
}
template <typename T, typename N>
std::ostream &operator<<(std::ostream &out, vector<pair<T, N> > &v) {
  for (size_t i = 0; i < v.size(); ++i) cout << v[i];
  out << "\n";
  return out;
}
template <typename T>
std::ostream &operator<<(std::ostream &out, vector<vector<T> > &v) {
  for (size_t i = 0; i < v.size(); ++i) {
    for (size_t j = 0; j < v[i].size(); ++j) {
      out << v[i][j] << " ";
    }
    out << "\n";
  }
  return out;
}
template <typename T>
std::ostream &operator<<(std::ostream &out, vector<set<T> > &v) {
  for (size_t i = 0; i < v.size(); ++i) {
    out << v[i];
  }
  out << "\n";
  return out;
}
void solve() {
  int n;
  cin >> n;
  vector<int> a(n + 1);
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  vector<int> suffix_sum(n + 2);
  for (int i = n; i > 0; --i) {
    suffix_sum[i] = suffix_sum[i + 1] + a[i];
  }
  vector<int> dp(n + 1);
  dp[n] = suffix_sum[n];
  for (int i = n - 1; i > 0; --i) {
    dp[i] = max(dp[i + 1], suffix_sum[i + 1] - dp[i + 1] + a[i]);
  }
  cout << suffix_sum[1] - dp[1] << " " << dp[1] << "\n";
  return;
}
int main() {
  std::ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t;
  t = 1;
  while (t--) {
    solve();
  }
  return 0;
}
