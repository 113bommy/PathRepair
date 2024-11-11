#include <bits/stdc++.h>
using namespace std;
int n;
int a[110][110];
int t[110];
bool cmp(int a, int b) { return a > b ? a : b; }
void input() {
  scanf("%d", &n);
  for (int i = 1, ___t = (n); i <= ___t; i++) {
    scanf("%d", &a[i][0]);
    for (int j = 1, ___t = (a[i][0]); j <= ___t; j++) {
      scanf("%d", &a[i][j]);
    }
  }
}
void solve() {
  int S1 = 0, S2 = 0;
  for (int i = 1, ___t = (n); i <= ___t; i++) {
    if (a[i][0] % 2 == 0) {
      for (int j = 1, ___t = (a[i][0] / 2); j <= ___t; j++) S1 += a[i][j];
      for (int j = a[i][0] / 2 + 1, ___t = (a[i][0]); j <= ___t; j++)
        S2 += a[i][j];
    } else {
      for (int j = 1, ___t = (a[i][0] / 2); j <= ___t; j++) S1 += a[i][j];
      for (int j = (a[i][0] + 1) / 2 + 1, ___t = (a[i][0]); j <= ___t; j++)
        S2 += a[i][j];
      t[++t[0]] = a[i][(a[i][0] + 1) / 2];
    }
  }
  sort(&t[1], &t[t[0] + 1], cmp);
  for (int i = 1, ___t = (t[0]); i <= ___t; i++) {
    if (i % 2 == 1)
      S1 += t[i];
    else
      S2 += t[i];
  }
  printf("%d %d\n", S1, S2);
}
int main() {
  input();
  solve();
  return 0;
}
