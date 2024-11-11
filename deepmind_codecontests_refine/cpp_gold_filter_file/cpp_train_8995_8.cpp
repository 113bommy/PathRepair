#include <bits/stdc++.h>
using namespace std;
const long long N = 6;
struct coord {
  long long c[N + 3][N + 3];
};
long long x[] = {2, 1, 1, 0, 1, 2};
long long y[] = {1, 2, 0, 1, 1, 2};
long long dx[] = {1, 1, 1, 0, 1, 2};
long long dy[] = {1, 1, 0, 1, 1, 2};
long long sh[] = {0, 0, 0, 0, 1, 1};
long long C[] = {0, 0, 0, 0, 0, 1};
coord a, b;
long long n, xo, yo, dxo, dyo, to;
coord mult(const coord &a, const coord &b) {
  coord r;
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      r.c[i][j] = 0;
    }
  }
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      for (int k = 0; k < N; ++k) {
        r.c[i][j] = (r.c[i][j] + a.c[i][k] * b.c[k][j]) % n;
      }
    }
  }
  return r;
}
coord Bpow(long long n) {
  if (n == 1) {
    return a;
  }
  if (n % 2 == 0) {
    coord p = Bpow(n / 2);
    return mult(p, p);
  }
  return mult(Bpow(n - 1), a);
}
int main() {
  for (int i = 0; i < N; ++i) {
    a.c[i][0] = x[i];
    a.c[i][1] = y[i];
    a.c[i][2] = dx[i];
    a.c[i][3] = dy[i];
    a.c[i][4] = sh[i];
    a.c[i][5] = C[i];
  }
  cin >> n >> xo >> yo >> dxo >> dyo >> to;
  if (to == 0) {
    cout << xo << " " << yo << endl;
    return 0;
  }
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      b.c[i][j] = 0;
    }
  }
  b.c[0][0] = xo - 1;
  b.c[0][1] = yo - 1;
  b.c[0][2] = dxo;
  b.c[0][3] = dyo;
  b.c[0][4] = 0;
  b.c[0][5] = 1;
  coord ce = Bpow(to);
  coord re = mult(b, ce);
  long long rx = (re.c[0][0] + n) % n, ry = (re.c[0][1] + n) % n;
  cout << rx + 1 << " " << ry + 1 << endl;
  return 0;
}
