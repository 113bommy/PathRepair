#include <bits/stdc++.h>
using namespace std;
inline int read() {
  int res = 0;
  int neg;
  while (true) {
    char ch = getchar();
    if (ch >= '0' && ch <= '9' || ch == '-') {
      if (ch == '-')
        neg = -1;
      else
        neg = 1, res = ch - '0';
      break;
    }
  }
  while (true) {
    char ch = getchar();
    if (ch >= '0' && ch <= '9')
      res *= 10, res += ch - '0';
    else
      break;
  }
  return res * neg;
}
const int maxn = 120;
const int maxm = 1000020;
const int MOd = 1e9 + 7;
int add(int a, int b) { return (a + b) >= MOd ? a + b - MOd : a + b; }
int mul(int a, int b) { return (long long)a * b % MOd; }
struct M {
  int mat[maxn][maxn];
  void init() { memset(mat, 0, sizeof(mat)); }
} C, B;
int a, b, x;
int s[maxn], dn[maxn][maxn][maxn];
bool used[maxn];
M mull(M xx, M y) {
  M h;
  h.init();
  for (int i = 0; i <= x; i++)
    for (int j = 0; j <= x; j++)
      for (int k = 0; k <= x; k++)
        h.mat[i][j] = add(h.mat[i][j], mul(xx.mat[i][k], y.mat[k][j]));
  return h;
}
int main() {
  int K;
  scanf("%d %d %d %d", &a, &b, &K, &x);
  for (int i = 1, j; i <= a; i++) {
    scanf("%d", &j);
    s[j]++;
  }
  int t = 1;
  int l = 1;
  for (int i = 0;; i++) {
    if (used[l]) {
      a = i;
      break;
    }
    used[l] = 1;
    l *= 10, l %= x;
  }
  for (int i = 0; i <= x; i++) dn[a + 1][i][i] = 1;
  int a2 = 0;
  B.init();
  for (int i = a; i >= 1; i--) {
    if (t == l && !a2) {
      a2 = i;
      for (int j = 0; j <= x; j++)
        for (int k = 0; k <= x; k++) {
          B.mat[j][k] = dn[i + 1][j][k];
          if (j == k)
            dn[i + 1][j][k] = 1;
          else
            dn[i + 1][j][k] = 0;
        }
      b -= a - a2;
    }
    for (int j = 0; j <= x; j++)
      for (int k = 0; k <= x; k++) {
        for (int y = 0; y <= 9; y++) {
          int h = (j + y * t) % x;
          dn[i][j][k] = add(dn[i][j][k], mul(s[y], dn[i + 1][h][k]));
        }
      }
    t *= 10;
    t %= x;
  }
  a = a2;
  C.init();
  for (int j = 0; j <= x; j++)
    for (int k = 0; k <= x; k++) C.mat[j][k] = dn[1][j][k];
  int y = b / a;
  while (y) {
    if (y & 1) B = mull(B, C);
    C = mull(C, C);
    y >>= 1;
  }
  for (int j = 0; j <= x; j++)
    for (int k = 0; k <= x; k++) C.mat[j][k] = dn[a - (b % a) + 1][j][k];
  B = mull(B, C);
  cout << B.mat[0][K] << endl;
  return 0;
}
