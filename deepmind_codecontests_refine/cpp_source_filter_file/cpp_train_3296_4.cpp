#include <bits/stdc++.h>
using std::cerr;
using std::cin;
using std::max;
using std::min;
int n, m, A[305], e[305][305];
void Solve(int l, int r, int p) {
  if (l > r) return;
  for (int i = 1; i <= A[l]; i++)
    for (int j = i + 1; j <= A[r] + 1; j++) e[p + i - 1][p + j - 1] = 1;
  for (int i = l + 1; i < r; i++) A[i] -= A[l];
  Solve(l + 1, r - 1, p + A[l]);
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", &A[i]);
  Solve(1, n, 1);
  for (int i = 1; i <= A[n] + 1; i++)
    for (int j = i + 1; j <= A[n] + 1; j++) m += e[i][j];
  printf("%d\n", m);
  for (int i = 1; i <= A[n] + 1; i++)
    for (int j = i + 1; j <= A[n] + 1; j++)
      if (e[i][j]) printf("%d %d\n", i, j);
  return 0;
}
