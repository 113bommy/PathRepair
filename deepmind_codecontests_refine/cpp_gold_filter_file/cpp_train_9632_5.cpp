#include <bits/stdc++.h>
using namespace std;
int log(int x) {
  if (x == 0) return 0;
  return __builtin_clz(1) - __builtin_clz(x);
}
int visit[1000000][31];
int cost[1000000][31];
int pot[1000000];
int qvisit(int l, int r) {
  int j = log(r - l), J = 1 << j;
  return max(visit[l][j], visit[r - J + 1][j]);
}
int qcost(int l, int r) {
  int j = log(r - l), J = 1 << j;
  return min(cost[l][j], cost[r - J + 1][j]);
}
int qpot(int l, int r) { return min(qcost(l, r), qvisit(l, r) * 100); }
int main() {
  int n, k;
  scanf("%d %d", &n, &k);
  for (int i = 0; i < n; ++i) scanf("%d", visit + i);
  for (int i = 0; i < n; ++i) scanf("%d", cost + i);
  for (int j = 1, J = 1; j < 31; J = 1 << j, ++j)
    for (int i = 0; i < n; ++i)
      visit[i][j] =
          max(visit[i][j - 1], i + J < n ? visit[i + J][j - 1] : INT_MIN),
      cost[i][j] =
          min(cost[i][j - 1], i + J < n ? cost[i + J][j - 1] : INT_MAX);
  for (int l = 0; l < n; ++l) {
    int a = l, b = n - 1, m;
    while (a < b) {
      m = (a + b) / 2;
      if (qcost(l, m) > qvisit(l, m) * 100)
        a = m + 1;
      else
        b = m;
    }
    pot[l] = qpot(l, a);
    if (a > l) pot[l] = max(qpot(l, a - 1), pot[l]);
    if (a + 1 < n) pot[l] = max(qpot(l, a + 1), pot[l]);
  }
  sort(pot, pot + n);
  double answer = 0;
  double p = 1;
  for (int i = 0; i < n; ++i)
    answer += pot[i] * p * k / (n - i), p = p * (n - i - k) / (n - i);
  printf("%f\n", answer);
  return 0;
}
