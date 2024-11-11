#include <bits/stdc++.h>
using namespace std;
template <class A, class B>
ostream& operator<<(ostream& out, const pair<A, B>& a) {
  return out << "(" << a.first << "," << a.second << ")";
}
template <class A>
ostream& operator<<(ostream& out, const vector<A>& a) {
  out << "";
  for (auto it = a.begin(); it != a.end(); it++) {
    if (it != a.begin()) out << " ";
    out << *it;
  }
  out << "";
  return out;
}
template <class A, class B>
istream& operator>>(istream& in, pair<A, B>& a) {
  in >> a.first >> a.second;
  return in;
}
template <class A>
istream& operator>>(istream& in, vector<A>& a) {
  for (A& i : a) in >> i;
  return in;
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long n, d;
  cin >> n >> d;
  string s;
  cin >> s;
  vector<long long> dp(n, INT_MAX);
  for (long long i = 1; i <= d; i++) {
    if (s[i] == '1') dp[i] = 1;
  }
  for (long long i = d + 1; i < n; i++) {
    if (s[i] == '1')
      for (long long j = 1; j <= d; j++) {
        if (s[i - j] == '1') dp[i] = min(dp[i - j] + 1, dp[i]);
      }
  }
  if (dp[n - 1] != INT_MAX)
    cout << dp[n - 1];
  else
    cout << -1;
}
