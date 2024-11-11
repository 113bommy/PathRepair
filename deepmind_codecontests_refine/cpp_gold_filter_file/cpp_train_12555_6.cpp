#include <bits/stdc++.h>
using namespace std;
const int N = 50000;
int parent[N];
int pos[N];
int sum = 0;
int from[N];
int cap[N];
int result[N];
vector<pair<int, int> > g[N];
void dfs(int i, int p = -1) {
  for (auto x : g[i])
    if (x.first != p)
      parent[x.first] = i, cap[x.first] = x.second, dfs(x.first, i);
}
int main() {
  ::ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n;
  scanf("%d", &n);
  vector<pair<int, int> > v;
  for (int i = 0; i < n; ++i) {
    int a;
    scanf("%d", &a);
    v.push_back({a, i});
    pos[i] = i;
  }
  sort(v.begin(), v.end());
  for (int i = 0; i < n - 1; ++i) {
    int a, b, w;
    scanf("%d %d %d", &a, &b, &w);
    --a, --b;
    g[a].push_back({b, w});
    g[b].push_back({a, w});
  }
  dfs(0);
  int timer = 0;
  while (sum < n) {
    for (int j = 0; j < n; ++j) {
      int i = v[j].second;
      if (pos[i] != 0) {
        if (from[pos[i]] != cap[pos[i]]) {
          ++from[pos[i]];
          pos[i] = parent[pos[i]];
        }
      } else if (pos[i] == 0) {
        result[i] = timer, pos[i] = -1, ++sum;
      }
    }
    for (int j = 0; j < n; ++j) from[j] = 0;
    ++timer;
  }
  for (int i = 0; i < n; ++i) cout << result[i] << " ";
  return 0;
}
