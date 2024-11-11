#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e2 + 5;
int n, x;
double a[MAXN];
double A[MAXN][MAXN], b[MAXN][MAXN], c[MAXN][MAXN];
int cnt;
void read_input() {
  cin >> n >> x;
  for (int i = 0; i < x + 1; i++) {
    cin >> a[i];
  }
}
void mult(double z[][MAXN], double g[][MAXN], bool p) {
  double h[MAXN][MAXN];
  for (int i = 0; i <= cnt; i++) {
    for (int j = 0; j <= cnt; j++) {
      double sum = 0;
      for (int f = 0; f <= cnt; f++) {
        sum += z[i][f] * g[f][j];
      }
      h[i][j] = sum;
    }
  }
  for (int i = 0; i <= cnt; i++) {
    for (int j = 0; j <= cnt; j++) {
      if (p == 0)
        b[i][j] = h[i][j];
      else {
        c[i][j] = h[i][j];
      }
    }
  }
}
void solve() {
  cnt = x + 1;
  for (int i = 0; i <= cnt; i++) {
    for (int j = 0; j <= cnt; j++) {
      c[i][j] = a[i ^ j];
    }
    b[i][i] = 1;
  }
  int mul = n;
  while (mul) {
    if (mul & 1) {
      mult(b, c, 0);
    }
    mult(c, c, 1);
    mul >>= 1;
  }
  cout << fixed;
  cout << setprecision(6) << 1 - b[0][0] << "\n";
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  read_input();
  solve();
  return 0;
}
