#include <bits/stdc++.h>
using namespace std;
int data[9][9] = {{0, 0, 1, 0, 0, 0, 0, 0, 1}, {0, 0, 0, 0, 0, 0, 1, 1, 1},
                  {1, 1, 0, 0, 0, 0, 0, 0, 1}, {0, 0, 0, 0, 1, 1, 0, 0, 1},
                  {0, 0, 0, 1, 0, 0, 0, 0, 1}, {0, 0, 0, 0, 0, 0, 1, 1, 1},
                  {1, 1, 0, 0, 0, 0, 0, 0, 1}, {0, 0, 0, 0, 1, 1, 0, 0, 1},
                  {0, 0, 0, 0, 0, 0, 0, 0, 1}};
void cheng(int a[][9], int b[][9], int c[][9]) {
  for (int i = 0; i < 9; i++)
    for (int j = 0; j < 9; j++) {
      a[i][j] = 0;
      for (int k = 0; k < 9; k++) {
        a[i][j] += ((long long)b[i][k]) * c[k][j] % 1000000007;
        a[i][j] %= 1000000007;
      }
    }
}
int compute(int K) {
  if (K < 2) return 0;
  K -= 1;
  int g[9][9], now[9][9], tmp[9][9];
  for (int i = 0; i < 9; i++)
    for (int j = 0; j < 9; j++) now[i][j] = i == j;
  memcpy(g, data, sizeof(g));
  while (K) {
    if (K & 1) {
      cheng(tmp, now, g);
      memcpy(now, tmp, sizeof(now));
    }
    K >>= 1;
    cheng(tmp, g, g);
    memcpy(g, tmp, sizeof(tmp));
  }
  memcpy(g, data, sizeof(g));
  cheng(tmp, g, g);
  memcpy(g, tmp, sizeof(tmp));
  int ans = 0;
  for (int i = 0; i < 8; i++) ans = (ans + now[i][8]) % 1000000007;
  return ans;
}
int solve(int K) {
  if (K == 0) return 0;
  if (K == 1) return 4;
  int g, h;
  g = compute(K);
  h = compute((K + 1) / 2);
  return ((g - h) * 500000004ll + h) % 1000000007;
}
int main() {
  int l, r;
  scanf("%d%d", &l, &r);
  r = solve(r);
  l = solve(l - 1);
  int ans = ((r - l) % 1000000007 + 1000000007) % 1000000007;
  printf("%d\n", ans);
  return 0;
}
