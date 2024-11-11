#include <bits/stdc++.h>
using namespace std;
const int inf = 1e9 + 7;
template <class T>
void dbs(string str, T t) {
  cout << str << " : " << t << endl;
}
template <class T, class... second>
void dbs(string str, T t, second... s) {
  int idx = str.find(',');
  cout << str.substr(0, idx) << " : " << t << ",";
  dbs(str.substr(idx + 1), s...);
}
template <class second, class T>
ostream& operator<<(ostream& os, const pair<second, T>& p) {
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
template <class second, class T>
ostream& operator<<(ostream& os, const map<second, T>& p) {
  os << "[ ";
  for (auto& it : p) os << it << " ";
  return os << "]";
}
template <class T>
void prc(T a, T b) {
  cout << "[";
  for (T i = a; i != b; ++i) {
    if (i != a) cout << ", ";
    cout << *i;
  }
  cout << "]";
  cout << endl;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  int ea[n];
  memset(ea, 0, sizeof ea);
  long long a[n];
  for (auto i = (0); i <= (n - 1); ++i) {
    cin >> a[i];
    while (!(a[i] & 1)) a[i] >>= 1, ++ea[i];
  }
  int dp[n];
  int ans = 1;
  for (auto i = (0); i <= (n - 1); ++i) {
    dp[i] = 1;
    for (auto j = (0); j <= (i - 1); ++j) {
      if (a[j] % a[i] == 0 and
          (ea[i] - (i - j) <= -1 or ea[j] == ea[i] - (i - j)))
        dp[i] = max(dp[i], 1 + dp[j]);
    }
    ans = max(ans, dp[i]);
  }
  cout << n - ans << "\n";
  return 0;
}
