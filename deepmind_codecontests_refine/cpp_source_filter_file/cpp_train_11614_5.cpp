#include <bits/stdc++.h>
using namespace std;
const int N = 12;
const int H = 16;
int n, a, b;
int h[N];
int d[N][H][H];
int p[N][H][H];
void solve() {
  scanf("%d%d%d", &n, &a, &b);
  for (int i = 1; i <= n; i++) scanf("%d", &h[i]);
  memset(d, 0x7f, sizeof d);
  for (int i = 0; i < H; i++)
    if (b * i >= h[1]) d[2][i][0] = i;
  for (int i = 3; i < N; i++)
    for (int j = 0; j < H; j++)
      for (int k = 0; k < H; k++)
        for (int l = 0; l < H; l++)
          if (a * k + b * (j + l) > h[i - 1]) {
            if (d[i][j][k] > d[i - 1][k][l] + j) {
              d[i][j][k] = d[i - 1][k][l] + j;
              p[i][j][k] = l;
            }
          }
  int ans = INT_MAX;
  int J, K;
  for (int j = 0; j < H; j++)
    for (int k = 0; k < H; k++)
      if (b * j > h[n]) {
        if (ans > d[n - 1][j][k]) {
          ans = d[n - 1][j][k];
          J = j;
          K = k;
        }
      }
  printf("%d\n", ans);
  int c = n - 1;
  while (c > 1) {
    for (int i = 0; i < J; i++) printf("%d ", c);
    int pj = K;
    int pk = p[c][J][K];
    J = pj, K = pk;
    c--;
  }
}
int main(void) { solve(); }
