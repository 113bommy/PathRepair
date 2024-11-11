#include <bits/stdc++.h>
using namespace std;
const int maxn = 100000 + 100;
int n, u, v;
vector<int> G[maxn];
int num[maxn];
void dfs(int f, int x) {
  num[x] = 1;
  int len = G[x].size();
  for (int i = 0; i < len; ++i) {
    int pos = G[x][i];
    if (pos != f) {
      dfs(x, pos);
      num[x] ^= num[pos];
    }
  }
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i < n; ++i) {
    scanf("%d%d", &u, &v);
    G[u].push_back(v);
    G[v].push_back(u);
  }
  dfs(1, 1);
  if (num[1] == 1) {
    printf("-1\n");
  } else {
    int cnt = 0;
    for (int i = 2; i <= n; ++i) {
      cnt += 1 - num[i];
    }
    printf("%d\n", cnt);
  }
  return 0;
}
