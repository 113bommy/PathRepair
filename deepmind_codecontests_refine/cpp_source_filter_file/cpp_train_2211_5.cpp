#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-9;
const int inf = 2000000000;
const long long infLL = 9000000000000000000;
template <typename first, typename second>
ostream& operator<<(ostream& os, const pair<first, second>& p) {
  return os << "(" << p.first << ", " << p.second << ")";
}
template <typename T>
ostream& operator<<(ostream& os, const vector<T>& v) {
  os << "{";
  for (auto it = v.begin(); it != v.end(); ++it) {
    if (it != v.begin()) os << ", ";
    os << *it;
  }
  return os << "}";
}
template <typename T>
ostream& operator<<(ostream& os, const set<T>& v) {
  os << "[";
  for (auto it = v.begin(); it != v.end(); ++it) {
    if (it != v.begin()) os << ",";
    os << *it;
  }
  return os << "]";
}
template <typename T>
ostream& operator<<(ostream& os, const multiset<T>& v) {
  os << "[";
  for (auto it = v.begin(); it != v.end(); ++it) {
    if (it != v.begin()) os << ", ";
    os << *it;
  }
  return os << "]";
}
template <typename first, typename second>
ostream& operator<<(ostream& os, const map<first, second>& v) {
  os << "[";
  for (auto it = v.begin(); it != v.end(); ++it) {
    if (it != v.begin()) os << ", ";
    os << it->first << " = " << it->second;
  }
  return os << "]";
}
void faltu() { cerr << '\n'; }
template <typename T>
void faltu(T a[], int n) {
  for (int i = 0; i < n; ++i) cerr << a[i] << ' ';
  cerr << '\n';
}
template <typename T, typename... hello>
void faltu(T arg, const hello&... rest) {
  cerr << arg << ' ';
  faltu(rest...);
}
const int mx = 1e5 + 5;
int n;
vector<int> adjlist[mx];
int dp[mx][2];
int ans;
void dfs(int u, int par) {
  dp[u][0] = 1;
  vector<int> black, white;
  for (auto v : adjlist[u]) {
    if (v == par) continue;
    dfs(v, u);
    black.push_back(dp[v][1]);
    white.push_back(max(dp[v][0], dp[v][1]));
  }
  sort(black.begin(), black.end(), greater<int>());
  sort(white.begin(), white.end(), greater<int>());
  for (int i = 0; i < 1 && i < (int)black.size(); ++i) dp[u][0] += black[i];
  for (int i = 0; i < 1 && i < (int)white.size(); ++i) dp[u][1] += white[i];
  if ((int)white.size() > 1) dp[u][1] += (int)white.size() - 1;
  int ret1 = 0, ret2 = 0;
  for (int i = 0; i < 2 && i < (int)black.size(); ++i) ret1 += black[i];
  for (int i = 0; i < 2 && i < (int)white.size(); ++i) ret2 += white[i];
  if ((int)white.size() > 2) ret2 += (int)white.size() - 2;
  if (par) ++ret2;
  ans = max(ans, max(ret1, ret2));
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  cin >> n;
  for (int i = 0; i < n - 1; ++i) {
    int a, b;
    cin >> a >> b;
    adjlist[a].push_back(b);
    adjlist[b].push_back(a);
  }
  dfs(1, 0);
  cout << ans << '\n';
}
