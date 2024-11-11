#include <bits/stdc++.h>
using namespace std;
struct bian {
  int next, point, w;
} b[10000];
int d[2100][2100], n, x[2100], f[2100], pd[2100], pre[2100], p[2100], len;
long long e[2100][2100];
int getmin() {
  int num = 2e9, where = 0;
  for (int i = 1; i <= n; i++)
    if (pd[i] == 0 && f[i] < num) {
      num = f[i];
      where = i;
    }
  return where;
}
void ade(int k1, int k2, int k3) {
  b[++len] = (bian){p[k1], k2, k3};
  p[k1] = len;
}
void add(int k1, int k2, int k3) {
  ade(k1, k2, k3);
  ade(k2, k1, k3);
}
void dfs(int k1, int k2, long long k3, int k4) {
  e[k4][k1] = k3;
  for (int i = p[k1]; i; i = b[i].next) {
    int j = b[i].point;
    if (j != k2) dfs(j, k1, k3 + b[i].w, k4);
  }
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++) scanf("%d", &d[i][j]);
  for (int i = 1; i <= n; i++)
    if (d[i][i] != 0) {
      cout << "NO" << endl;
      return 0;
    }
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++)
      if (d[i][j] != d[j][i]) {
        cout << "NO" << endl;
        return 0;
      }
  memset(f, 0x3f, sizeof f);
  f[1] = 0;
  memset(pd, 0x00, sizeof pd);
  for (int i = 1; i <= n; i++) {
    int k1 = getmin();
    if (k1 != 1 && f[k1] == 0) {
      cout << "NO" << endl;
      return 0;
    }
    if (pre[k1]) add(pre[k1], k1, f[k1]);
    pd[k1] = 1;
    for (int j = 1; j <= n; j++)
      if (pd[j] == 0 && d[k1][j] < f[j]) {
        pre[j] = k1;
        f[j] = d[k1][j];
      }
  }
  for (int i = 1; i <= n; i++) dfs(i, 0, 0, i);
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++)
      if (e[i][j] != d[i][j]) {
        cout << "NO" << endl;
        return 0;
      }
  cout << "YES" << endl;
  return 0;
}
