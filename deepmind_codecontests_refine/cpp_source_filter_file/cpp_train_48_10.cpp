#include <bits/stdc++.h>
using namespace std;
int p[110][60], t[110], a[110][60], d[110][60], n, rp[60], T;
long long rq[60];
long long gcd(long long a, long long b) { return b == 0 ? a : gcd(b, a % b); }
int qpow(long long a, long long i) {
  long long r = 1;
  for (; i; i >>= 1, a = a * a % 1000000007)
    if (i & 1) r = r * a % 1000000007;
  return r;
}
void check() {
  for (int i = 1; i <= n; ++i) {
    long long TMP = -1;
    for (int j = 1, k = 1; j <= t[i]; ++j) {
      while (k <= T && p[i][j] > rp[k]) {
        if (rq[k]) {
          printf("-1");
          exit(0);
        };
        ++k;
      }
      if (k > T || rp[k] ^ p[i][j]) {
        if (a[i][j]) {
          printf("-1");
          exit(0);
        };
        if (TMP < 0)
          TMP = 1;
        else if (TMP) {
          printf("-1");
          exit(0);
        };
        --k;
      } else if (d[i][j]) {
        if ((rq[k] - a[i][j]) % d[i][j]) {
          printf("-1");
          exit(0);
        };
        long long R = (rq[k] - a[i][j]) / d[i][j];
        if (R < 0) {
          printf("-1");
          exit(0);
        };
        if (TMP < 0)
          TMP = R;
        else if (TMP ^ R) {
          printf("-1");
          exit(0);
        };
      } else if (a[i][j] ^ rq[k]) {
        printf("-1");
        exit(0);
      };
      ++k;
    }
  }
  long long ans = 1;
  for (int i = 1; i <= T; ++i) ans = qpow(rp[i], rq[i]) * ans % 1000000007;
  printf("%I64d", ans);
  exit(0);
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    int A, Q;
    scanf("%d %d", &A, &Q);
    for (int j = 2; j <= 32000; ++j) {
      if (A == 1 && Q == 1) break;
      if (j * j > A && j * j > Q) {
        if (A == Q) p[i][++t[i]] = A, a[i][t[i]] = d[i][t[i]] = 1;
        if (A ^ 1)
          if (A < Q || Q == 1) p[i][++t[i]] = A, a[i][t[i]] = 1;
        if (Q ^ 1)
          if (A > Q || A == 1) p[i][++t[i]] = Q, d[i][t[i]] = 1;
        if (A < Q && A ^ 1) p[i][++t[i]] = Q, d[i][t[i]] = 1;
        if (A > Q && Q ^ 1) p[i][++t[i]] = A, a[i][t[i]] = 1;
        A = Q = 1;
      }
      if (A == 1 && Q == 1) break;
      if (A % j == 0 || Q % j == 0) {
        ++t[i];
        p[i][t[i]] = j;
        while (A % j == 0) A /= j, ++a[i][t[i]];
        while (Q % j == 0) Q /= j, ++d[i][t[i]];
      }
    }
  }
  for (int i = 2; i <= n; ++i) {
    for (int j = 1; j <= t[i] || j <= t[1]; ++j)
      if (p[i][j] < p[1][j] || !p[1][j]) {
        if (a[i][j]) {
          printf("-1");
          exit(0);
        };
        T = t[i];
        for (int k = 1; k <= t[i]; ++k) rq[k] = a[i][k], rp[k] = p[i][k];
        check();
      } else if (p[1][j] < p[i][j] || !p[i][j]) {
        if (a[1][j]) {
          printf("-1");
          exit(0);
        };
        T = t[1];
        for (int k = 1; k <= t[1]; ++k) rq[k] = a[1][k], rp[k] = p[1][k];
        check();
      } else if (d[i][j] && !d[1][j]) {
        if ((a[1][j] - a[i][j]) % d[i][j] != 0) {
          printf("-1");
          exit(0);
        };
        int D = (a[1][j] - a[i][j]) / d[i][j];
        if (D < 0) {
          printf("-1");
          exit(0);
        };
        T = t[i];
        for (int k = 1; k <= t[i]; ++k)
          rq[k] = a[i][k] + d[i][k] * D, rp[k] = p[i][k];
        check();
      } else if (d[1][j] && !d[i][j]) {
        if ((a[i][j] - a[1][j]) % d[1][j] != 0) {
          printf("-1");
          exit(0);
        };
        int D = (a[i][j] - a[1][j]) / d[1][j];
        if (D < 0) {
          printf("-1");
          exit(0);
        };
        T = t[1];
        for (int k = 1; k <= t[1]; ++k)
          rq[k] = a[1][k] + d[1][k] * D, rp[k] = p[1][k];
        check();
      } else if (!d[i][j] && !d[1][j])
        if (a[i][j] ^ a[1][j]) {
          printf("-1");
          exit(0);
        };
    for (int j = 2; j <= t[i]; ++j)
      if (d[1][1] * d[i][j] ^ d[1][j] * d[i][1]) {
        for (int x = 0; x <= 30; ++x)
          for (int y = 0; y <= 30; ++y)
            if (a[1][1] + d[1][1] * x == a[i][1] + d[i][1] * y)
              if (a[1][j] + d[1][j] * x == a[i][j] + d[i][j] * y) {
                for (int k = 1; k <= t[i]; ++k)
                  rq[k] = a[1][k] + d[1][k] * x, rp[k] = p[1][k];
                T = t[1];
                check();
              }
        {
          printf("-1");
          exit(0);
        };
      }
  }
  long long A = 0, Q = 1;
  for (int i = 2; i <= n; ++i)
    for (int j = 1; j <= t[1]; ++j)
      if (d[i][j] ^ d[1][j]) {
        int B = -1, P = d[i][j] / gcd(d[i][j], d[1][j]), t = 0;
        for (int k = 0; k < 60; ++k)
          if (d[1][j] * k + a[1][j] >= a[i][j])
            if ((d[1][j] * k + a[1][j] - a[i][j]) % d[i][j] == 0) {
              B = k;
              break;
            }
        if (B < 0) {
          printf("-1");
          exit(0);
        };
        for (int k = 0; k < 90; ++k)
          if (Q * k + A >= B)
            if ((Q * k + A - B) % P == 0) {
              t = 1;
              A = Q * k + A;
              Q = Q * P / gcd(P, Q);
              break;
            }
        if (!t) {
          printf("-1");
          exit(0);
        };
      }
  T = t[1];
  for (int i = 1; i <= t[1]; ++i)
    rp[i] = p[1][i], rq[i] = A * d[1][i] + a[1][i];
  check();
}
