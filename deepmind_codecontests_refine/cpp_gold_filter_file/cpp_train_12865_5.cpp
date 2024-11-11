#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 7 + 100000;
vector<int> tab[MAX_N];
vector<int> f[MAX_N];
int can[MAX_N];
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  for (int i = 0; i <= n; i++) tab[i].resize(m + 1), f[i].resize(m + 1);
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) scanf("%d", &tab[i][j]);
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      f[i][j] = (tab[i][j] >= tab[i - 1][j]) * f[i - 1][j] + 1;
    }
    can[i] = 0;
    for (int j = 1; j <= m; j++) can[i] = max(can[i], f[i][j]);
  }
  int qn;
  scanf("%d", &qn);
  for (int i = 1; i <= qn; i++) {
    int ql, qr;
    scanf("%d%d", &ql, &qr);
    printf(can[qr] >= qr - ql + 1 ? "Yes\n" : "No\n");
  }
}
