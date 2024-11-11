#include <bits/stdc++.h>
using namespace std;
int cmp(const void *a, const void *b) { return (*(int *)a) - (*(int *)b); }
int EQ(double a, double b) {
  if (fabs(a - b) < 1e-12)
    return 0;
  else if (a > b + 1e-12)
    return 1;
  else
    return -1;
}
vector<int> node[210];
queue<int> Q;
int deg[210], din[210], ans = (2100000000);
int n;
int test(int x) {
  int degg[210], f[210];
  int i, need = -1, u, cnt = 0;
  memset(f, 0, sizeof(f));
  for (i = 1; i <= n; i++) degg[i] = deg[i];
  while (cnt < n) {
    need++;
    for (i = 1; i <= n; i++) {
      if (!f[i] && !degg[i] && din[i] == x) {
        f[i] = 1;
        Q.push(i);
      }
    }
    while (!Q.empty()) {
      u = Q.front();
      Q.pop();
      cnt++;
      need++;
      for (i = 0; i < node[u].size(); i++) {
        degg[node[u][i]]--;
        if (!degg[node[u][i]] && din[node[u][i]] == x) {
          f[i] = 1;
          Q.push(node[u][i]);
        }
      }
    }
    x = x + 1;
    if (x == 4) x = 1;
  }
  if (need < ans) ans = need;
  return 0;
}
int main() {
  int i, j, k, u;
  memset(deg, 0, sizeof(deg));
  scanf("%d", &n);
  for (i = 1; i <= n; i++) {
    scanf("%d", din + i);
  }
  for (i = 1; i <= n; i++) {
    scanf("%d", &k);
    for (j = 0; j < k; j++) {
      scanf("%d", &u);
      node[u].push_back(i);
      deg[i]++;
    }
  }
  test(1);
  test(2);
  test(3);
  printf("%d\n", ans);
  return 0;
}
