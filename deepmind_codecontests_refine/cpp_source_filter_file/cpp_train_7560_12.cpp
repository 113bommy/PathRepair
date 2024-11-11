#include <bits/stdc++.h>
using namespace std;
template <class T>
void dbs(string str, T t) {
  cerr << str << " : " << t << "\n";
}
template <class T, class... S>
void dbs(string str, T t, S... s) {
  int idx = str.find(',');
  cerr << str.substr(0, idx) << " : " << t << ",";
  dbs(str.substr(idx + 1), s...);
}
template <class S, class T>
ostream& operator<<(ostream& os, const pair<S, T>& p) {
  return os << "(" << p.first << ", " << p.second << ")";
}
template <class T>
ostream& operator<<(ostream& os, const vector<T>& p) {
  os << "[ ";
  for (auto& it : p) os << it << " ";
  return os << "]";
}
template <class T>
ostream& operator<<(ostream& os, const set<T>& p) {
  os << "[ ";
  for (auto& it : p) os << it << " ";
  return os << "]";
}
template <class S, class T>
ostream& operator<<(ostream& os, const map<S, T>& p) {
  os << "[ ";
  for (auto& it : p) os << it << " ";
  return os << "]";
}
template <class T>
void prc(T a, T b) {
  cerr << "[";
  for (T i = a; i != b; ++i) {
    if (i != a) cerr << ", ";
    cerr << *i;
  }
  cerr << "]\n";
}
const int N = 100000;
set<int> S[2][2];
int questionCount[N + 1];
pair<int, int> dp[N + 1];
int main() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  int m;
  cin >> m;
  for (int i = (int)(0); i <= (int)(n - 1); i++) {
    if (s[i] == '?') continue;
    S[s[i] - 'a'][i % 2].insert(i);
  }
  for (int i = (int)(1); i <= (int)(n); i++) {
    questionCount[i] = questionCount[i - 1];
    if (s[i - 1] == '?') questionCount[i]++;
  }
  dp[0] = make_pair(0, 0);
  for (int i = (int)(1); i <= (int)(n); i++) {
    dp[i] = dp[i - 1];
    if (i < m) continue;
    bool bad = false;
    int temp = i - m;
    temp %= 2;
    auto it = S[0][temp ^ 2].lower_bound(i);
    if (it != S[0][temp ^ 2].begin()) {
      it--;
      if (*it >= i - m) bad = true;
    }
    it = S[1][temp].lower_bound(i);
    if (it != S[1][temp].begin()) {
      it--;
      if (*it >= i - m) bad = true;
    }
    if (!bad) {
      if (dp[i - m].first + 1 > dp[i].first) {
        dp[i] =
            make_pair(dp[i - m].first + 1, dp[i - m].second + questionCount[i] -
                                               questionCount[i - m]);
      } else if (dp[i - m].first + 1 == dp[i].first and
                 dp[i - m].second + questionCount[i] - questionCount[i - m] <
                     dp[i].second) {
        dp[i] =
            make_pair(dp[i - m].first + 1, dp[i - m].second + questionCount[i] -
                                               questionCount[i - m]);
      }
    }
  }
  cout << dp[n].second << "\n";
  return 0;
}
