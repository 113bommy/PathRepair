#include <bits/stdc++.h>
const int maxn = 100 + 2;
struct Mat {
  long long f[maxn][maxn];
};
long long N, B, K, M, arr[50005];
Mat Mul(const Mat& a, const Mat& b) {
  Mat res;
  memset(&res, 0, sizeof(res));
  for (int i = 0; i < M; ++i) {
    for (int j = 0; j < M; ++j) {
      for (int k = 0; k < M; ++k) {
        res.f[i][j] =
            (res.f[i][j] + (a.f[i][k] * b.f[k][j]) % 1000000007) % 1000000007;
      }
    }
  }
  return res;
}
Mat QuickPower(Mat& a, long long b) {
  Mat e, x = a;
  memset(e.f, 0, sizeof(e));
  for (int i = 0; i < M; ++i) {
    e.f[i][i] = 1;
  }
  while (b) {
    if (b & 1) {
      e = Mul(e, x);
    }
    x = Mul(x, x);
    b >>= 1;
  }
  return e;
}
inline long long read() {
  long long f = 1, r = 0;
  char c = getchar();
  while (!isdigit(c)) {
    if (c == '-') {
      f = -1;
    }
    c = getchar();
  }
  while (isdigit(c)) {
    r = 10 * r + c - '0';
    c = getchar();
  }
  return f * r;
}
inline void write(long long x) {
  if (x < 0) putchar('-'), x = -x;
  if (x > 9) write(x / 10);
  putchar(x % 10 + '0');
}
inline void writesp(long long x) { write(x), putchar(' '); }
inline void writeln(long long x) { write(x), puts(""); }
int main() {
  N = read(), B = read(), K = read(), M = read();
  Mat base, ans;
  memset(base.f, 0, sizeof(base.f));
  memset(ans.f, 0, sizeof(ans.f));
  for (int i = 1; i <= N; ++i) {
    arr[i] = read();
  }
  for (int i = 0; i < M; ++i) {
    for (int j = 1; j <= N; ++j) {
      int x = (i * 10 % M + arr[j] % M) % M;
      base.f[x][i]++;
    }
  }
  ans.f[0][0] = 1;
  base = QuickPower(base, B);
  ans = Mul(base, ans);
  writeln(ans.f[K][0]);
  return 0;
}
