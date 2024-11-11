#include <bits/stdc++.h>
using namespace std;
const int N = 55;
map<string, int> mp;
int n, m, num, ans;
int cnt[N], vis[N], link[N][N], group[N];
vector<int> vec;
int dfs(int x, int tot) {
  for (int i = x + 1; i <= num; i++) {
    if (cnt[i] + tot <= ans) return 0;
    if (link[x][i]) {
      int flag = 0;
      for (int j = 0; j < tot; j++) {
        if (!link[i][vis[j]]) flag = 1;
      }
      if (!flag) {
        vis[tot] = x;
        if (dfs(i, tot + 1)) return 1;
      }
    }
  }
  if (tot > ans) {
    ans = tot;
    return 1;
  }
  return 0;
}
int main() {
  cin >> n >> m;
  for (int i = 1; i <= m; i++)
    for (int j = 1; j <= m; j++) link[i][j] = 1;
  for (int i = 1; i <= n; i++) {
    int d;
    scanf("%d", &d);
    if (d == 1) vec.clear();
    if (d == 2) {
      string s;
      cin >> s;
      if (!mp[s]) mp[s] = ++num;
      for (auto v : vec) {
        link[v][mp[s]] = link[mp[s]][v] = 0;
      }
      vec.push_back(mp[s]);
    }
  }
  ans = -1;
  for (int i = num; i >= 1; i--) {
    vis[0] = i;
    dfs(i, 1);
    cnt[i] = ans;
  }
  cout << ans << endl;
  return 0;
}
