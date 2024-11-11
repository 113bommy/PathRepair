#include <bits/stdc++.h>
using namespace std;
void dfs(int u, const vector<vector<pair<int, int>>> &a, vector<bool> &was,
         vector<int> &exit_t, vector<int> &ordered, int &time) {
  was[u] = true;
  for (auto v : a[u]) {
    if (!was[v.first]) {
      dfs(v.first, a, was, exit_t, ordered, time);
    }
  }
  exit_t[u] = time;
  ordered[time] = u;
  time++;
}
void topsort(const vector<vector<pair<int, int>>> &a, int n, vector<int> &skill,
             vector<int> &ordered) {
  int time = 0;
  vector<bool> was(n, false);
  for (int i = 0; i < n; ++i) {
    if (!was[i]) {
      dfs(i, a, was, skill, ordered, time);
    }
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, m;
  cin >> n >> m;
  vector<vector<pair<int, int>>> a(n);
  for (int i = 0; i < m; ++i) {
    int u, v;
    cin >> u >> v;
    u--;
    v--;
    a[u].push_back(make_pair(v, i));
  }
  vector<int> skill(n);
  vector<int> ordered(n);
  topsort(a, n, skill, ordered);
  vector<int> d(n);
  int ans = 0;
  for (int i = 1; i < n; ++i) {
    int u = ordered[i];
    int curmin = m + 10;
    for (auto p : a[u]) {
      if (p.first == ordered[i - 1]) {
        curmin = min(curmin, p.second + 1);
      }
    }
    if (curmin == m + 10) {
      ans = -1;
      break;
    }
    ans = max(ans, curmin);
  }
  cout << ans << endl;
  return 0;
}
