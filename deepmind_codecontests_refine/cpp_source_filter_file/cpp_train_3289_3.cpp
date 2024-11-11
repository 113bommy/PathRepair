#include <bits/stdc++.h>
using namespace std;
int cor[300005];
vector<int> adj[300005];
vector<int> ic[300005];
int oc[300005];
void dfs(int a, int p = -1) {
  for (int i : ic[a])
    if (cor[i]) oc[cor[i]] = a;
  int mex = 1;
  for (int i : ic[a]) {
    if (!cor[i]) {
      while (oc[mex] == a) mex++;
      cor[i] = mex;
      oc[mex] = a;
    }
  }
  for (int i : adj[a]) {
    if (i != p) dfs(i, a);
  }
}
int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; i++) {
    int x;
    scanf("%d", &x);
    while (x--) {
      int y;
      scanf("%d", &y);
      ic[i + 1].push_back(y);
    }
  }
  for (int i = 1; i < n; i++) {
    int a, b;
    scanf("%d %d", &a, &b);
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  dfs(1);
  int ans = 0;
  for (int i = 1; i <= m; i++) ans = max(ans, cor[i]);
  printf("%d\n", ans);
  for (int i = 1; i <= m; i++) printf("%d ", cor[i]);
  printf("\n");
  return 0;
}
