#include <bits/stdc++.h>
using namespace std;
const int maxn = 100003;
long long n, u, v;
long long p[maxn], num_child[maxn], num_depth[maxn], ans = 0;
vector<int> a[maxn];
void DFS(int u, int depth) {
  num_depth[depth]++;
  for (int i = 0; i <= a[u].size() - 1; ++i) {
    int v = a[u][i];
    if (!p[v]) {
      p[v] = u;
      num_child[u]++;
      DFS(v, depth + 1);
    }
  }
}
void DFS2(int u, int depth) {
  long long num = 0;
  if (num_depth[depth + 1] != 0) {
    num = num_depth[depth + 1];
    ans += num - num_child[u];
  }
  for (int i = 0; i <= a[u].size() - 1; ++i) {
    int v = a[u][i];
    if (p[u] != v) {
      DFS2(v, depth + 1);
    }
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  scanf("%d", &n);
  for (int i = 1; i <= n - 1; ++i) {
    scanf("%d%d", &u, &v);
    a[u].push_back(v);
    a[v].push_back(u);
  }
  p[1] = -1;
  DFS(1, 1);
  for (int i = n; i >= 1; --i) {
    num_depth[i] += num_depth[i + 2];
  }
  DFS2(1, 1);
  printf("%I64d", ans);
  return 0;
}
