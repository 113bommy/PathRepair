#include <bits/stdc++.h>
using namespace std;
int n, a[100000];
int sol;
int next(int i) { return (i < n - 1) ? a[i + 1] : 1000000007; }
int prev(int i) { return (i > 0) ? a[i - 1] : 0; }
int dp[10000][3];
int count(int i, int dir) {
  if (dp[i][dir]) return dp[i][dir];
  int rez = 1;
  if (dir < 2 && i > 0) {
    rez++;
    for (int j = i - 2; j >= 0 && a[j] < a[j + 1]; --j) rez++;
  }
  if (dir != 1 && i < n - 1) {
    rez++;
    for (int j = i + 2; j < n && a[j] > a[j - 1]; ++j) rez++;
  }
  return dp[i][dir] = rez;
}
int main(void) {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
  int t = 0;
  for (int i = 0; i < n; ++i) {
    if (a[i] > next(i)) {
      t = 1;
      if (next(i) - prev(i) > 1) sol = max(sol, count(i, 0));
      if (next(i + 1) - a[i] > 1) sol = max(sol, count(i + 1, 0));
      sol = max(sol, count(i + 1, 1));
      sol = max(sol, count(i, 2));
    }
  }
  printf("%d", ((t) ? sol : n));
  return 0;
}
