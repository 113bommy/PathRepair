#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
int n, K, m;
int T[13][16][13][16];
long long f[200][200];
int Num(int x) {
  int ans = 0;
  while (x != 0) {
    ans += x % 2;
    x /= 2;
  }
  return ans;
}
int Js(int x, int y) { return (x << m) + y; }
long long c[200][200];
void Chen(long long a[][200], long long b[][200]) {
  memset(c, 0, sizeof(c));
  for (int i = 0; i < ((K + 1) << m); i++)
    for (int j = 0; j < ((K + 1) << m); j++)
      for (int k = 0; k < ((K + 1) << m); k++)
        c[i][j] = (c[i][j] + a[i][k] * b[k][j]) % mod;
  for (int i = 0; i < ((K + 1) << m); i++)
    for (int j = 0; j < ((K + 1) << m); j++) a[i][j] = c[i][j];
}
long long ans[200][200];
void Pow(long long a[][200], int b) {
  for (int i = 0; i < ((K + 1) << m); i++) ans[i][i] = 1;
  while (b != 0) {
    if (b % 2) Chen(ans, a);
    Chen(a, a);
    b /= 2;
  }
}
long long anss;
int main() {
  scanf("%d %d %d", &n, &K, &m);
  for (int i = 1; i <= K; i++)
    for (int j = 0; j < (1 << m); j++) {
      int num = Num(j);
      if (num > i) continue;
      if (j % 2) {
        T[i - 1][j / 2][i][j] = num;
        T[i - 1][j / 2 + (1 << (m - 1))][i][j] = num + 1;
      } else {
        T[i][j / 2][i][j] = 1;
        T[i][j / 2 + (1 << (m - 1))][i][j] = 1;
      }
    }
  T[0][0][0][0] = 1;
  for (int i = 0; i <= K; i++)
    for (int j = 0; j < (1 << m); j++)
      for (int k = 0; k <= K; k++)
        for (int r = 0; r < (1 << m); r++) {
          f[Js(i, j)][Js(k, r)] = T[i][j][k][r];
        }
  Pow(f, n);
  for (int i = 0; i < ((K + 1) << m); i++)
    if (i >= Js(K, 0)) {
      anss = (anss + ans[0][i]) % mod;
    }
  printf("%d", anss);
  return 0;
}
