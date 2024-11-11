#include <bits/stdc++.h>
using namespace std;
int n, m, Query;
char ch;
bool a[520][520];
int A[520][520][15][18], P[520], dp[520];
void go(int tl, int tr, int deep, int pr) {
  if (tl == tr) return;
  int v = (tl + tr) / 2;
  dp[v] = deep;
  P[v] = pr;
  for (int i = 1; i <= n; ++i) {
    if (a[i][v] == 1) continue;
    for (int j = 0; j < 17; ++j) A[i][v][deep][j] = A[i - 1][v][deep][j];
    int x = i / 31;
    int y = i % 31;
    A[i][v][deep][x] = (A[i][v][deep][x] | (1 << y));
  }
  for (int i = v + 1; i < tr; ++i)
    for (int j = 1; j <= n; ++j) {
      if (a[j][i] == 1) continue;
      for (int k = 0; k < 17; ++k)
        A[j][i][deep][k] = (A[j - 1][i][deep][k] | A[j][i - 1][deep][k]);
    }
  for (int i = n; i >= 1; --i) {
    for (int j = 0; j < 17; ++j)
      if (a[i][v] == 0)
        A[i][v][deep][j] = A[i + 1][v][deep][j];
      else
        A[i][v][deep][j] = 0;
    if (a[i][v] == 1) continue;
    int x = i / 31;
    int y = i % 31;
    A[i][v][deep][x] = (A[i][v][deep][x] | (1 << y));
  }
  for (int i = v - 1; i >= tl; --i)
    for (int j = n; j >= 1; --j) {
      if (a[j][i] == 1) continue;
      for (int k = 0; k < 17; ++k)
        A[j][i][deep][k] = (A[j + 1][i][deep][k] | A[j][i + 1][deep][k]);
    }
  go(tl, v, deep + 1, v);
  go(v + 1, tr, deep + 1, v);
}
int main() {
  scanf("%d %d", &n, &m);
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j) {
      ch = getchar();
      while (ch != '.' && ch != '#') ch = getchar();
      if (ch == '#')
        a[i][j] = true;
      else
        a[i][j] = false;
    }
  go(1, m + 1, 0, 0);
  scanf("%d", &Query);
  while (Query--) {
    pair<int, int> x, y;
    int c1, c2, X, Y;
    scanf("%d %d", &x.first, &x.second);
    scanf("%d %d", &y.first, &y.second);
    if (x.first > y.first || x.second > y.second) {
      printf("No\n");
      continue;
    }
    c1 = x.second;
    c2 = y.second;
    while (dp[c1] > dp[c2]) c1 = P[c1];
    while (dp[c2] > dp[c1]) c2 = P[c2];
    while (c1 != c2) c1 = P[c1], c2 = P[c2];
    if (y.second == c2) {
      X = y.first / 31;
      Y = y.first % 31;
      if ((A[x.first][x.second][dp[c1]][X] & (1 << Y)) == 0)
        printf("No\n");
      else
        printf("Yes\n");
      continue;
    }
    bool b = true;
    for (int i = 0; i < 17; ++i)
      if ((A[x.first][x.second][dp[c1]][i] & A[y.first][y.second][dp[c1]][i]) >
          0) {
        b = false;
        break;
      }
    if (b)
      printf("No\n");
    else
      printf("Yes\n");
  }
}
