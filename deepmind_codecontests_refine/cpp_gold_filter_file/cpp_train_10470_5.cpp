#include <bits/stdc++.h>
int ex[] = {1, -1, 0, 0};
int wye[] = {0, 0, 1, -1};
using namespace std;
vector<int> vt[10005];
bool visit[10005];
int n, x, y, an;
void dfs(int node) {
  if (visit[node]) return;
  visit[node] = true;
  int siz = vt[node].size();
  int tmp;
  for (int i = 0; i < siz; i++) {
    tmp = vt[node][i];
    if (visit[tmp]) continue;
    dfs(tmp);
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &x);
    vt[i].push_back(x);
    vt[x].push_back(i);
  }
  for (int i = 1; i <= n; i++) {
    if (visit[i]) continue;
    dfs(i);
    an++;
  }
  printf("%d\n", an);
  return 0;
}
