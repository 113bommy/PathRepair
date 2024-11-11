#include <bits/stdc++.h>
using namespace std;
const int N = 210, mo = 1e4 + 7;
char s[N];
int n, m;
int f[N][N][N];
int odd, ans;
void get_count() {
  f[0][0][0] = 1;
  for (int x = 0; x < n; x++) {
    for (int y = 0; x + y < n; y++) {
      for (int k = 0; 2 * k < n; k++)
        if (f[x][y][k]) {
          for (int i = 'a'; i <= 'z'; i++)
            if ((s[x + 1] == i) || (s[n - y] == i)) {
              int _x = x + (s[x + 1] == i);
              int _y = y + (s[n - y] == i);
              ((f[_x][_y][k + (s[x + 1] == s[n - y])]) =
                   ((f[_x][_y][k + (s[x + 1] == s[n - y])]) + (f[x][y][k])) %
                   mo);
            }
        }
    }
  }
}
int sz, cnta, cntb;
typedef int mat[2 * N][2 * N];
mat a;
void mult(mat a, mat b, mat c) {
  static mat ret;
  memset(ret, 0, sizeof ret);
  for (int k = 1; k <= sz; k++) {
    for (int i = 1; i <= k; i++)
      if (a[i][k]) {
        for (int j = k; j <= sz; j++) {
          ((ret[i][j]) = ((ret[i][j]) + (a[i][k] * b[k][j])) % mo);
        }
      }
  }
  memcpy(c, ret, sizeof ret);
}
void ksm(mat x, int y) {
  static mat ret;
  memset(ret, 0, sizeof ret);
  for (int i = 1; i <= sz; i++) ret[i][i] = 1;
  for (; y; y >>= 1) {
    if (y & 1) mult(ret, x, ret);
    mult(x, x, x);
  }
  memcpy(x, ret, sizeof ret);
}
void build_graph() {
  cnta = n, cntb = (n + 1) / 2;
  memset(a, 0, sizeof a);
  for (int i = 1; i < cnta + cntb; i++) a[i][i + 1] = 1;
  for (int i = 1; i <= cnta; i++) a[i][i] = 24;
  for (int i = cnta + 1; i <= cnta + cntb; i++) {
    a[i][i] = 25;
    a[i][i + cntb] = 1;
    a[i + cntb][i + cntb] = 26;
  }
  sz = cnta + cntb + cntb;
}
void calc() {
  build_graph();
  ksm(a, (n + m + 1) / 2);
  for (int k = 0; k * 2 <= n + 1; k++) {
    int sum[2];
    sum[0] = sum[1] = 0;
    for (int x = 0; x <= n + 1; x++) {
      if (n - x >= 0) ((sum[0]) = ((sum[0]) + (f[x][n - x][k])) % mo);
      ((sum[1]) = ((sum[1]) + (f[x][n + 1 - x][k])) % mo);
    }
    for (int s = n; s <= n + 1; s++) {
      int z = s - 2 * k;
      if (z >= 0)
        ((ans) =
             ((ans) + (a[cnta - z + 1][cnta + k + cntb] * sum[s - n])) % mo);
    }
  }
}
void calc2() {
  build_graph();
  ksm(a, (n + m) / 2);
  for (int k = 1; k * 2 <= n; k++) {
    int z = n - 2 * k, sum = 0;
    for (int x = 0; x < n - 1; x++)
      if (s[x + 1] == s[x + 2]) {
        ((sum) = ((sum) + (f[x][n - 2 - x][k - 1])) % mo);
      }
    if (z >= 0) ((ans) = ((ans) + (-a[cnta - z + 1][cnta + k] * sum)) % mo);
  }
}
int main() {
  cin >> s + 1 >> m;
  n = strlen(s + 1);
  odd = (n + m) % 2;
  get_count();
  calc();
  if (odd) calc2();
  cout << (ans + mo) % mo << endl;
}
