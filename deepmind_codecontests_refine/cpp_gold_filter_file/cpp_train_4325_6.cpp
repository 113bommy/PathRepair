#include <bits/stdc++.h>
using namespace std;
template <class T>
bool chmax(T &a, const T &b) {
  if (a < b) {
    a = b;
    return 1;
  }
  return 0;
}
template <class T>
bool chmin(T &a, const T &b) {
  if (a > b) {
    a = b;
    return 1;
  }
  return 0;
}
template <class T>
ostream &operator<<(ostream &os, const vector<T> &t) {
  os << "[";
  for (__typeof((t).begin()) it = (t).begin(); it != (t).end(); it++) {
    if (it != t.begin()) os << ",";
    os << *it;
  }
  os << "]";
  return os;
}
template <class T>
ostream &operator<<(ostream &os, const set<T> &t) {
  os << "{";
  for (__typeof((t).begin()) it = (t).begin(); it != (t).end(); it++) {
    if (it != t.begin()) os << ",";
    os << *it;
  }
  os << "}";
  return os;
}
template <class S, class T>
ostream &operator<<(ostream &os, const pair<S, T> &t) {
  return os << "(" << t.first << "," << t.second << ")";
}
template <class S, class T>
pair<S, T> operator+(const pair<S, T> &s, const pair<S, T> &t) {
  return pair<S, T>(s.first + t.first, s.second + t.second);
}
template <class S, class T>
pair<S, T> operator-(const pair<S, T> &s, const pair<S, T> &t) {
  return pair<S, T>(s.first - t.first, s.second - t.second);
}
const int INF = 1 << 28;
const double EPS = 1e-8;
const int MOD = 1000000007;
int n, m;
string s;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> s;
  reverse((s).begin(), (s).end());
  for (int i = 0; i < (int)(5); i++) s.pop_back();
  n = s.size();
  vector<int> dp(n + 1, 0);
  dp[0] = 1;
  set<string> ans;
  for (int i = 0; i < (int)(n); i++)
    if (dp[i]) {
      for (int j = 2; j <= 3; j++)
        if (i + j <= n) {
          string t = s.substr(i, j);
          int k = 5 - j;
          if (i - k >= 0 && dp[i - k]) {
          } else if (i - j >= 0 && s.substr(i - j, j) == t)
            continue;
          reverse((t).begin(), (t).end());
          ans.insert(t);
          dp[i + j] = 1;
        }
    }
  cout << ans.size() << endl;
  for (string s : ans) cout << s << endl;
  return 0;
}
