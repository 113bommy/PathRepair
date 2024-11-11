#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10, M = 1 << 7;
struct Node {
  int a, ver;
  bool operator<(const Node& t) const { return a > t.a; }
} node[N];
int s[N][7], cnt[M];
long long f[M];
int main() {
  int n, m, K;
  scanf("%d%d%d", &n, &m, &K);
  for (int i = 1; i <= n; i++) scanf("%d", &node[i].a), node[i].ver = i;
  for (int i = 1; i <= n; i++)
    for (int j = 0; j < m; j++) scanf("%d", &s[i][j]);
  sort(node + 1, node + 1 + n);
  for (int i = 1; i < 1 << m; i++)
    for (int j = 0; j < m; j++)
      if ((i >> j) & 1) cnt[i]++;
  memset(f, -1, sizeof f);
  f[0] = 0;
  for (int i = 1; i <= n; i++) {
    int w = node[i].a, ver = node[i].ver;
    for (int j = (1 << m) - 1; j >= 0; j--) {
      if (i - cnt[j] <= K && f[j] != -1) f[j] += w;
      for (int k = 0; k < m; k++)
        if ((j >> k) & 1 && f[j - (1 << k)] != -1) {
          f[j] = max(f[j], f[j - (1 << k)] + s[ver][k]);
        }
    }
  }
  printf("%d\n", f[(1 << m) - 1]);
  return 0;
}
