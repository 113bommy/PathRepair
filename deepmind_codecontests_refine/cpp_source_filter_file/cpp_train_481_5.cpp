#include <bits/stdc++.h>
using namespace std;
struct Matrix {
  long long p[3][3];
  friend Matrix operator*(Matrix a, Matrix b) {
    Matrix c;
    memset(c.p, 0, sizeof(c.p));
    for (int i = 0; i < 3; i++)
      for (int j = 0; j < 3; j++) {
        for (int k = 0; k < 3; k++) {
          c.p[i][j] += a.p[i][k] * b.p[k][j] % 1000000007;
        }
        c.p[i][j] %= 1000000007;
      }
    return c;
  }
};
struct data {
  long long x;
  int y, p;
  bool operator<(const data a) const { return x < a.x; }
} point[20005];
int n;
long long m;
long long ans[4];
Matrix A;
Matrix powd(Matrix a, int b) {
  Matrix c;
  memset(c.p, 0, sizeof(c.p));
  c.p[0][0] = c.p[1][1] = c.p[2][2] = 1;
  while (b > 0) {
    if (b & 1) c = c * a;
    a = a * a;
    b >>= 1;
  }
  return c;
}
int main() {
  cin >> n >> m;
  int cnt = 0, i;
  for (i = 1; i <= n; i++) {
    int ak;
    long long x, y;
    cin >> ak >> x >> y;
    point[++cnt] = (data){x, ak, 1};
    point[++cnt] = (data){y + 1, ak, -1};
  }
  point[++cnt] = (data){m, 1, 0};
  sort(point + 1, point + cnt + 1);
  ans[0] = 0;
  ans[1] = 1;
  ans[2] = 0;
  int flag[3];
  long long ans1[3];
  memset(flag, 0, sizeof(flag));
  long long now = 1;
  for (i = 1; i <= cnt; i++) {
    long long dis = point[i].x - now;
    now = point[i].x;
    if (dis > 0) {
      for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++) {
          if (flag[i] == 0 && abs(i - j) <= 1) {
            A.p[i][j] = 1;
          } else {
            A.p[i][j] = 0;
          }
        }
      A = powd(A, dis);
      memset(ans1, 0, sizeof(ans1));
      for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++) {
          ans1[i] += ans[j] * A.p[j][i] % 1000000007;
        }
      for (int i = 0; i < 3; i++) ans[i] = ans1[i] % 1000000007;
    }
    while (point[i + 1].x == point[i].x) {
      flag[point[i].y - 1] += point[i].p;
      i++;
    }
    flag[point[i].y - 1] += point[i].p;
    for (int i = 0; i < 3; i++) {
      if (flag[i] > 0) ans[i] = 0;
    }
  }
  printf("%I64d\n", (ans[1] + 1000000007) % 1000000007);
  return 0;
}
