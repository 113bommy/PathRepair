#include <bits/stdc++.h>
using namespace std;
const int maxn = 305;
int n, a[maxn][maxn], f[10][maxn], pos[maxn];
int get(int l, int r) {
  if (l > r) return n + 1;
  int k = (int)trunc(log(r - l + 1) / log(2));
  return min(f[k][l], f[k][r - (1 << k) + 1]);
}
int main() {
  scanf("%d", &n);
  for (int i = (1); i <= (n); i++)
    for (int j = (1); j <= (n); j++) scanf("%d", &a[i][j]);
  for (int i = (1); i <= (n); i++) {
    scanf("%d", &f[0][i]);
    pos[f[0][i]] = i;
  }
  for (int j = (1); j <= (trunc(log(n) / log(2)) + 1e-6); j++)
    for (int i = (1); i <= (n - (1 << j) + 1); i++)
      f[j][i] = min(f[j - 1][i], f[j - 1][i + (1 << (j - 1))]);
  for (int i = (1); i <= (n); i++) {
    int j;
    for (int c = (1); c <= (n); c++)
      if (a[i][c] != i) {
        int k;
        j = a[i][c];
        if (pos[i] < pos[j])
          k = min(get(1, pos[i] - 1), get(pos[i] + 1, pos[j]));
        else
          k = get(1, pos[j]);
        if (k >= j) break;
      }
    printf("%d ", j);
  }
  return 0;
}
