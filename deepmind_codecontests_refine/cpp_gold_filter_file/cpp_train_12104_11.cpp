#include <bits/stdc++.h>
using namespace std;
int n, m, ans1, ans2;
char S[25][25];
int A[45][45];
int sg[45][45][45][45];
int Sg(int u, int d, int l, int r) {
  if (u > d || l > r) return 0;
  if (sg[u][d][l][r] != -1) return sg[u][d][l][r];
  int vis[525] = {0};
  for (int i = u; i <= d; i++)
    for (int j = l; j <= r; j++) {
      if (A[i][j] == 1) vis[Sg(u, i - 1, l, r) ^ Sg(i + 1, d, l, r)] = 1;
      if (A[i][j] == 2) vis[Sg(u, d, l, j - 1) ^ Sg(u, d, j + 1, r)] = 1;
      if (A[i][j] == 3)
        vis[Sg(u, i - 1, l, j - 1) ^ Sg(u, i - 1, j + 1, r) ^
            Sg(i + 1, d, l, j - 1) ^ Sg(i + 1, d, j + 1, r)] = 1;
    }
  for (int i = 0; i <= 520; i++) {
    if (!vis[i]) {
      sg[u][d][l][r] = i;
      break;
    }
  }
  return sg[u][d][l][r];
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) scanf("%s", S[i] + 1);
  memset(A, 0, sizeof(A));
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if ((i & 1) == (j & 1)) {
        int a = (i + j) / 2, b = (m + 1) / 2 + (i - j) / 2;
        if (S[i][j] == 'L') A[a][b] = 1;
        if (S[i][j] == 'R') A[a][b] = 2;
        if (S[i][j] == 'X') A[a][b] = 3;
      }
    }
  }
  memset(sg, -1, sizeof(sg));
  ans1 = Sg(1, (n + m) / 2, 1, (n + m) / 2);
  memset(A, 0, sizeof(A));
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if ((i & 1) != (j & 1)) {
        int a = (i + j) / 2, b = (m + 1) / 2 + (i - j + 1) / 2;
        if (S[i][j] == 'L') A[a][b] = 1;
        if (S[i][j] == 'R') A[a][b] = 2;
        if (S[i][j] == 'X') A[a][b] = 3;
      }
    }
  }
  memset(sg, -1, sizeof(sg));
  ans2 = Sg(1, (n + m) / 2 + 2, 1, (n + m) / 2 + 2);
  if (ans1 == ans2)
    puts("LOSE");
  else
    puts("WIN");
}
