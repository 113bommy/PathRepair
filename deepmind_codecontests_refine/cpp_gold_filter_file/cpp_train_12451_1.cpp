#include <bits/stdc++.h>
const long long P = 1000000007, N = 101;
long long min(long long a, long long b) { return a < b ? a : b; }
struct Mat {
  long long n, m;
  long long a[N][N];
  Mat() { memset(a, 0, sizeof a); }
  void print() {}
};
Mat operator*(const Mat &a, const Mat &b) {
  Mat ans;
  ans.n = a.n;
  ans.m = b.m;
  for (long long i = 1; i <= ans.n; ++i)
    for (long long j = 1; j <= ans.m; ++j) {
      ans.a[i][j] = 0;
      for (long long k = 1; k <= a.m; ++k)
        (ans.a[i][j] += a.a[i][k] * b.a[k][j]) %= P;
    }
  return ans;
}
Mat pow(Mat a, long long b) {
  Mat ans;
  ans.n = a.n;
  ans.m = a.m;
  for (long long i = 1; i <= ans.n; ++i) ans.a[i][i] = 1;
  for (; b; b /= 2, a = a * a)
    if (b % 2) ans = ans * a;
  return ans;
}
int main() {
  long long n, k;
  scanf("%I64d%I64d", &n, &k);
  Mat a;
  a.n = 1;
  a.m = 1;
  a.a[1][1] = 1;
  Mat b;
  b.n = 16;
  b.m = 16;
  for (long long i = 1; i <= 16; ++i)
    b.a[i][i] = b.a[i][i - 1] = b.a[i][i + 1] = 1;
  for (long long i = 1; i <= n; ++i) {
    long long l, r, p;
    scanf("%I64d%I64d%I64d", &l, &r, &p);
    ++p;
    r = min(r, k);
    a.m = p;
    b.n = p;
    b.m = p;
    a = a * pow(b, r - l);
    if (r == k) break;
  }
  printf("%I64d", a.a[1][1]);
  return 0;
}
