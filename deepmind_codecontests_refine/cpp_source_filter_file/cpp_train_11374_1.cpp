#include <bits/stdc++.h>
using namespace std;
const long double EPS = 10e-9;
const int INF = 1e9 + 5;
const long long INFLL = (long long)INF * (long long)INF;
const long long MOD = 1e9 + 7;
const long double PI = 3.14159265358979323846;
struct HASH {
  size_t operator()(const pair<int, int>& x) const {
    return hash<long long>()(((long long)x.first) ^
                             (((long long)x.second) << 32));
  }
};
template <typename T>
ostream& operator<<(ostream& os, const vector<T>& v) {
  os << "[";
  for (int i = 0; i < (int)v.size(); ++i) {
    os << v[i];
    if (i != (int)v.size() - 1) os << ", ";
  }
  os << "]\n";
  return os;
}
template <typename T>
ostream& operator<<(ostream& os, const set<T>& v) {
  os << "{";
  for (const auto& it : v) {
    os << it;
    if (it != *v.rbegin()) os << ", ";
  }
  os << "}\n";
  return os;
}
template <typename T>
ostream& operator<<(ostream& os, const unordered_set<T>& v) {
  os << "{";
  for (const auto& it : v) {
    os << it;
    if (it != *v.rbegin()) os << ", ";
  }
  os << "}\n";
  return os;
}
template <typename T, typename S>
ostream& operator<<(ostream& os, const map<T, S>& v) {
  os << "{";
  for (const auto& it : v) {
    os << it.first << " : " << it.second;
    if (it != *v.rbegin()) os << ", ";
  }
  os << "}\n";
  return os;
}
template <typename T, typename S>
ostream& operator<<(ostream& os, const unordered_map<T, S>& v) {
  os << "{";
  for (const auto& it : v) {
    os << it.first << " : " << it.second;
    if (it != *v.rbegin()) os << ", ";
  }
  os << "}\n";
  return os;
}
template <typename T, typename S>
ostream& operator<<(ostream& os, const pair<T, S>& v) {
  os << "(";
  os << v.first << ", " << v.second << ")";
  os << "\n";
  return os;
}
template <typename Arg1>
void __f(const char* name, Arg1&& arg1) {
  cerr << name << " : " << arg1;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
  const char* comma = strchr(names + 1, ',');
  cerr.write(names, comma - names) << " : " << arg1 << " | ";
  __f(comma + 1, args...);
}
void solve() {
  int n, m;
  cin >> n >> m;
  vector<vector<int>> mat(n, vector<int>(m, 0));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> mat[i][j];
    }
  }
  int answer = 0;
  int lim = (n + m - 1) / 2 - 1;
  for (int diag = 0; diag <= lim; diag++) {
    int len = min({diag + 1, n, m});
    int s1 = 0;
    int i = 0;
    if (diag < m) {
      for (int j = diag; j >= 0; j--) {
        if (i < n && j < m) s1 += mat[i][j];
        i++;
      }
    } else {
      i = diag - m;
      for (int j = m - 1; j >= 0; j--) {
        if (i >= 0 && i < n && j < m) s1 += mat[i][j];
        i++;
      }
    }
    int s2 = 0;
    i = n - 1;
    if (diag < m) {
      for (int j = m - 1 - diag; j < m; j++) {
        if (i >= 0 && j >= 0) s2 += mat[i][j];
        i--;
      }
    } else {
      int sub = diag - m;
      i = n - 1 - sub;
      for (int j = 0; j < m; j++) {
        if (i < n && i >= 0 && j >= 0) s2 += mat[i][j];
        i--;
      }
    }
    answer += min(s1 + s2, 2 * len - (s1 + s2));
  }
  cout << answer << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
