#include <bits/stdc++.h>
using namespace std;
long long mod = 998244353;
int inf = 1e9;
double eps = 1e-2;
ifstream in("input.txt");
ofstream out("output.txt");
vector<vector<int>> g;
vector<int> a, b;
vector<int> ans;
bool dfs(int v) {
  ans.push_back(v % 4);
  if (g[v].size() == 0) {
    return 1;
  }
  bool bl = 0;
  for (int i = 0; i < g[v].size(); i++) {
    int to = g[v][i];
    if (((v % 4) | (to % 4)) == a[v / 4] && ((v % 4) & (to % 4)) == b[v / 4]) {
      bl |= dfs(to);
    }
  }
  if (bl) return 1;
  ans.pop_back();
  return 0;
}
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n - 1; i++) {
    int t;
    cin >> t;
    a.push_back(t);
  }
  for (int i = 0; i < n - 1; i++) {
    int t;
    cin >> t;
    b.push_back(t);
  }
  g.resize(4 * n);
  for (int i = 0; i < n - 1; i++) {
    g[i * 4].push_back((i + 1) * 4);
    g[i * 4].push_back((i + 1) * 4 + 1);
    g[i * 4].push_back((i + 1) * 4 + 2);
    g[i * 4].push_back((i + 1) * 4 + 3);
    g[i * 4 + 1].push_back((i + 1) * 4);
    g[i * 4 + 1].push_back((i + 1) * 4 + 1);
    g[i * 4 + 1].push_back((i + 1) * 4 + 2);
    g[i * 4 + 1].push_back((i + 1) * 4 + 3);
    g[i * 4 + 2].push_back((i + 1) * 4);
    g[i * 4 + 2].push_back((i + 1) * 4 + 1);
    g[i * 4 + 2].push_back((i + 1) * 4 + 2);
    g[i * 4 + 2].push_back((i + 1) * 4 + 3);
    g[i * 4 + 3].push_back((i + 1) * 4);
    g[i * 4 + 3].push_back((i + 1) * 4 + 1);
    g[i * 4 + 3].push_back((i + 1) * 4 + 2);
    g[i * 4 + 3].push_back((i + 1) * 4 + 3);
  }
  if (dfs(0)) {
    cout << "YES" << endl;
    for (int i = 0; i < n; i++) {
      cout << ans[i];
    }
    return 0;
  }
  if (dfs(1)) {
    cout << "YES" << endl;
    for (int i = 0; i < n; i++) {
      cout << ans[i] << " ";
    }
    return 0;
  }
  if (dfs(2)) {
    cout << "YES" << endl;
    for (int i = 0; i < n; i++) {
      cout << ans[i] << " ";
    }
    return 0;
  }
  if (dfs(3)) {
    cout << "YES" << endl;
    for (int i = 0; i < n; i++) {
      cout << ans[i] << " ";
    }
    return 0;
  }
  cout << "NO";
  return 0;
}
