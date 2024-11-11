#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1000;
int n, m;
int a[MAXN][MAXN];
unsigned int msk[MAXN][32];
int two[MAXN];
bool check(int val) {
  for (int i = 0; i < n; i++) {
    two[i] = 0;
    for (int j = 0; j < m; j += 32) {
      int pos = j / 32;
      msk[i][pos] = 0;
      for (int k = 0; k < 32 && k + j < m; k++)
        if (a[i][j + k] >= val) {
          msk[i][pos] |= 1U << k;
          two[i]++;
        }
    }
  }
  for (int x = 0; x < n; x++)
    if (two[x] >= 2)
      for (int y = x + 1; y < n; y++)
        if (two[y] >= 2) {
          int cnt = 0;
          for (int j = 0; j < m; j += 32) {
            cnt += __builtin_popcount(msk[x][j / 32] & msk[y][j / 32]);
            if (cnt > 1) return true;
          }
        }
  return false;
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) scanf("%d", &a[i][j]);
  int l, r, mid;
  l = 0, r = 1000000000;
  while (l < r) {
    mid = (l + r + 1) >> 1;
    if (check(mid))
      l = mid;
    else
      r = mid - 1;
  }
  printf("%d\n", l);
  return 0;
}
