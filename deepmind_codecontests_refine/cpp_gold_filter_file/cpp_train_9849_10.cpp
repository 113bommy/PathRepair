#include <bits/stdc++.h>
using namespace std;
vector<int> adj[234567];
void dfs(int cur, int p = -1) {
  for (int v : adj[cur]) {
    if (v == p) continue;
    printf("%d %d\n", cur, v);
    dfs(v, cur);
  }
}
int main() {
  int n, k;
  scanf("%d%d", &n, &k);
  vector<int> leaves_with_dep[234567];
  for (int i = 0; i < k; i++) {
    adj[1].push_back(i + 2);
    leaves_with_dep[1].push_back(i + 2);
  }
  n = n - k - 1;
  int cur = 1;
  int nxt = k + 2;
  while (n) {
    adj[leaves_with_dep[cur].back()].push_back(nxt);
    leaves_with_dep[cur].pop_back();
    leaves_with_dep[cur + 1].push_back(nxt);
    if (leaves_with_dep[cur].empty()) cur++;
    nxt++, n--;
  }
  int res = 0;
  for (int i = 0; i < 234567; i++) {
    if (leaves_with_dep[i].size() >= 2) {
      res = max(res, 2 * i);
    }
    if (leaves_with_dep[i].size() == 1) {
      res = max(res, 2 * i - 1);
    }
  }
  printf("%d\n", res);
  dfs(1);
  return 0;
}
