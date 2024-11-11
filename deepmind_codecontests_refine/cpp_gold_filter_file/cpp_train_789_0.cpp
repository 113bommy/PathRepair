#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:167772160000")
using namespace std;
vector<pair<int, int> > edges[310000];
bool ans[310000];
int ansCount;
int num[310000];
int cnt[3];
bool vis[310000];
bool dfs(int a) {
  if (vis[a]) return false;
  vis[a] = true;
  bool ret = (num[a] == 2);
  for (int i = 0; i < (edges[a].size()); i++) {
    if (dfs(edges[a][i].first)) {
      ans[edges[a][i].second] = true;
      ansCount++;
      ret = !ret;
    }
  }
  return ret;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= (n); i++) {
    cin >> num[i];
    num[i]++;
    cnt[num[i]]++;
  }
  for (int i = 1; i <= (m); i++) {
    int a, b;
    cin >> a >> b;
    edges[a].push_back(pair<int, int>(b, i));
    edges[b].push_back(pair<int, int>(a, i));
  }
  if (cnt[2] % 2 == 1 && cnt[0] == 0) {
    cout << -1;
    return 0;
  }
  int st = 1;
  if (cnt[0] > 0)
    while (num[st] != 0) st++;
  dfs(st);
  cout << ansCount << "\n";
  for (int i = 1; i <= (m); i++)
    if (ans[i]) cout << i << "\n";
  return 0;
}
