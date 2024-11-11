#include <bits/stdc++.h>
using namespace std;
template <class T>
void dbs(string str, T t) {
  cerr << str << " : " << t << "\n";
}
template <class T, class... S>
void dbs(string str, T t, S... s) {
  int idx = str.find(',');
  cerr << str.substr(0, idx) << " : " << t << ", ";
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
const int N = 5007;
vector<vector<int> > pos(N, vector<int>(N, 0));
vector<vector<int> > dp(N, vector<int>(N, -1));
vector<int> values(N);
int n, m;
int solve(int x, int mn) {
  if (mn > m || x > n) return 0;
  if (dp[x][mn] != -1) return dp[x][mn];
  if (pos[mn][n] - pos[mn][x - 1] == 0) {
    dp[x][mn] = solve(x, mn + 1);
    return dp[x][mn];
  }
  if (values[x] <= mn) {
    dp[x][mn] = solve(x + 1, mn);
    return dp[x][mn];
  } else {
    int val = pos[mn][n] - pos[mn][x - 1];
    dp[x][mn] = min(solve(x + 1, mn) + 1, solve(x, mn + 1) + val);
    return dp[x][mn];
  }
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t, i, j, k, q;
  int x, y, l, r;
  cin >> n >> m;
  double z;
  for (i = 1; i <= n; i++) {
    cin >> values[i] >> z;
    pos[values[i]][i]++;
  }
  for (i = 1; i <= m; i++) {
    for (j = 1; j <= n; j++) pos[i][j] += pos[i][j - 1];
  }
  cout << solve(1, 1) << endl;
  return 0;
}
