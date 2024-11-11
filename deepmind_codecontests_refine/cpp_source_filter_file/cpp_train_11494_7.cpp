#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int n, tp, rou[N];
bool vis[N];
void dfs(int u) {
  vis[u] = 1;
  if (!vis[(u << 1) % n]) dfs((u << 1) % n);
  if (!vis[(u << 1 | 1) % n]) dfs((u << 1 | 1) % n);
  rou[++tp] = u;
}
int main() {
  scanf("%d", &n);
  if (n & 1) {
    printf("0");
    return 0;
  }
  dfs(0);
  for (int i = n; i >= 1; i--) {
    printf("%d ", rou[i]);
  }
  printf("0");
  return 0;
}
