#include <bits/stdc++.h>
using namespace std;
vector<int> vt[10007];
int vis[10007], vis2[10007];
void dfs(int att, int c) {
  if (vis2[att] == c) return;
  vis2[att] = c;
  for (int i = 0; i < vt[att].size(); i++) {
    dfs(vt[att][i], c);
  }
}
int main() {
  int num, val, coun = 0;
  scanf("%d", &num);
  memset(vis2, -1, sizeof(vis2));
  for (int i = 2; i <= num; i++) {
    scanf("%d", &val);
    vt[val].push_back(i);
  }
  for (int i = 1; i <= num; i++) {
    scanf("%d", &val);
    vis[i] = val;
  }
  for (int i = 1; i <= num; i++) {
    if (vis2[i] != vis[i]) {
      coun++;
      dfs(i, vis[i]);
    }
  }
  printf("%d\n", coun);
}
