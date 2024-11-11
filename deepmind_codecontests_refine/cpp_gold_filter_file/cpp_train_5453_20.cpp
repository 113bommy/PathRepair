#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 1;
vector<int> t[N];
int n, dep[N];
double ans;
void dfs(int u, int d) {
  dep[u] = d;
  for (int v : t[u])
    if (!dep[v]) dfs(v, d + 1);
}
int main() {
  scanf("%d", &n);
  for (int i = 1, a, b; i < n; i++) {
    scanf("%d%d", &a, &b);
    t[a].push_back(b);
    t[b].push_back(a);
  }
  dfs(1, 1);
  for (int i = 1; i <= n; i++) ans += 1.0l / dep[i];
  printf("%.20f", ans);
}
