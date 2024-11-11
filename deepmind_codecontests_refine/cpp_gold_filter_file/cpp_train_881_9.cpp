#include <bits/stdc++.h>
const int inf = 1000000007;
using namespace std;
vector<vector<pair<int, int>>> a;
vector<int> used;
void stop() {
  puts("0");
  exit(0);
}
void dfs(int v) {
  for (int i = 0; i < a[v].size(); i++) {
    if (used[a[v][i].first] == -1) {
      if (a[v][i].second)
        used[a[v][i].first] = used[v];
      else
        used[a[v][i].first] = !used[v];
      dfs(a[v][i].first);
    }
    if (a[v][i].second && used[a[v][i].first] != used[v]) stop();
    if (!a[v][i].second && used[a[v][i].first] == used[v]) stop();
  }
}
int main() {
  int n, m;
  scanf("%d", &n);
  scanf("%d", &m);
  a.resize(n);
  used.resize(n, -1);
  for (int i = 0; i < m; i++) {
    int t1, t2, t3;
    scanf("%d", &t1);
    scanf("%d", &t2);
    scanf("%d", &t3);
    t1--;
    t2--;
    a[t1].push_back(make_pair(t2, t3));
    a[t2].push_back(make_pair(t1, t3));
  }
  int ans = 1;
  for (int i = 0; i < n; i++) {
    if (used[i] == -1) {
      used[i] = 0;
      dfs(i);
      if (i) ans <<= 1, ans %= inf;
    }
  }
  printf("%d", ans);
  return 0;
}
