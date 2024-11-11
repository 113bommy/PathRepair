#include <bits/stdc++.h>
using namespace std;
int n, m;
bitset<4000> st[2000];
int x[500000], y[500000];
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= m; i++)
    scanf("%d%d", &x[i], &y[i]), st[x[i] - 1][y[i] - 1] = 1;
  for (int i = 0; i < n; i++) st[i][i + n] = 1;
  for (int i = 0; i < n; i++) {
    int j = i;
    for (j = i; j < n; j++)
      if (st[j][i]) break;
    if (j != i) swap(st[i], st[j]);
    for (j = 0; j < n; j++)
      if (j != i && st[j][i]) st[j] ^= st[i];
  }
  for (int i = 1; i <= m; i++) puts(st[y[i] - 1][n + x[i] - 1] ? "NO" : "YES");
  return 0;
}
