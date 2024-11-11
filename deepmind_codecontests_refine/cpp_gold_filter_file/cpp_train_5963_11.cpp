#include <bits/stdc++.h>
using namespace std;
int n;
int a[300][300];
int value[300][301];
int p[300];
int which_t[300][300];
int which(int to, int time) {
  for (int i = 0; i < n; i++)
    if (p[i] <= time && p[i] != to) return p[i];
  return n;
}
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) {
      scanf("%d", &a[i][j]);
      a[i][j]--;
    }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) value[i][a[i][j]] = n - j;
    value[i][n] = -1;
  }
  for (int i = 0; i < n; i++) {
    scanf("%d", &p[i]);
    p[i]--;
  }
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) which_t[i][j] = which(i, j);
  for (int to = 0; to < n; to++) {
    if (to) printf(" ");
    int best = -1, when = -1;
    for (int t = 0; t < n; t++)
      if (value[to][which_t[to][t]] > best) {
        best = value[to][which_t[to][t]];
        when = t;
      }
    printf("%d", when + 1);
  }
  return 0;
}
