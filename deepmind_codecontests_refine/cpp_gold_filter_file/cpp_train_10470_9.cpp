#include <bits/stdc++.h>
using namespace std;
int ob[1000000];
int n, p[1000000];
vector<int> v[1000000];
void dfs(int x) {
  ob[x] = 1;
  for (int i = 0; i < v[x].size(); i++)
    if (!ob[v[x][i]]) dfs(v[x][i]);
}
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    scanf("%d", &p[i]);
    v[p[i]].push_back(i);
    v[i].push_back(p[i]);
  }
  int ans = 0;
  for (int i = 1; i <= n; i++)
    if (!ob[i]) {
      dfs(i);
      ans++;
    }
  printf("%d\n", ans);
  return 0;
}
