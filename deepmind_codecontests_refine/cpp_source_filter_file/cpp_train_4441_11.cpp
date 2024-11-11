#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1001010;
int rem[MAXN], p[MAXN], n, ans;
vector<int> v[MAXN];
void dfs(int u, int h) {
  rem[h] = 1;
  int k = v[u].size();
  for (int i = 0; i < k; i++) {
    dfs(v[u][i], h + 1);
  }
}
int main() {
  scanf("%d", &n);
  for (int i = 2; i <= n; i++) {
    int t;
    scanf("%d", &t);
    v[t].push_back(i);
  }
  dfs(1, 0);
  for (int i = 0; i <= n; i++)
    if (rem[i]) ans++;
  printf("%d", ans);
}
