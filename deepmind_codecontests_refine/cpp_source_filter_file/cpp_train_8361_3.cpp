#include <bits/stdc++.h>
using namespace std;
const int MAX = 1010;
int marker[MAX][MAX], cap[MAX][MAX], smd[MAX], scd[MAX], n, m;
void solve() {
  memset(smd, 0, sizeof(smd));
  memset(scd, 0, sizeof(scd));
  for (int i = 1; i <= MAX; i++) {
    for (int j = 1; j <= MAX; j++) {
      smd[i] += marker[j][i];
    }
  }
  for (int i = 1; i <= MAX; i++) {
    for (int j = 1; j <= MAX; j++) {
      scd[i] += cap[j][i];
    }
  }
  int ans1 = 0;
  for (int i = 1; i <= MAX; i++) ans1 += min(scd[i], smd[i]);
  int ans2 = 0;
  for (int i = 1; i <= MAX; i++)
    for (int j = 1; j <= MAX; j++) ans2 += min(marker[i][j], cap[i][j]);
  printf("%d %d\n", ans1, ans2);
}
int main() {
  scanf("%d%d", &n, &m);
  memset(marker, 0, sizeof(marker));
  memset(cap, 0, sizeof(cap));
  for (int i = 0; i < n; i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    marker[x][y]++;
  }
  for (int i = 0; i < m; i++) {
    int a, b;
    scanf("%d%d", &a, &b);
    cap[a][b]++;
  }
  solve();
  return 0;
}
