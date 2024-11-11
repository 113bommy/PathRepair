#include <bits/stdc++.h>
using namespace std;
char p[42], q[42];
int n, m, cnt, C[1 << 20], OK[50][50];
long long U[40 << 18], TP[40 << 18];
void Do(int st, int pv, long long s) {
  if (pv == n) {
    U[cnt++] = s;
    return;
  }
  if (pv < m) {
    long long t = (p[m - pv - 1] - '0');
    Do(st, pv + 1, s + (t << ((pv + st) % n)));
    return;
  }
  Do(st, pv + 1, s);
  Do(st, pv + 1, s + (1ll << ((pv + st) % n)));
}
int A[50][50], B[50][50], Pre[50], Suf[50];
int Calc2(int L, int i, int ck) {
  int j;
  int pr = 0, su = 0;
  for (j = 0; j <= L - m; j++) {
    if (((i >> j) & ((1 << m) - 1)) == Pre[m]) {
      pr = su = m;
    }
  }
  for (j = 1; j <= m && j <= L; j++) {
    if ((i >> (L - j)) == Suf[j]) su = max(su, j);
    if ((i & ((1 << j) - 1)) == Pre[j]) pr = max(pr, j);
  }
  if (ck == 0) return pr;
  return su;
}
void Calc(int L, int pv) {
  int i, j;
  for (i = 0; i < (1 << L); i++) {
    int pr = 0, su = 0;
    for (j = 0; j <= L - m; j++) {
      if (((i >> j) & ((1 << m) - 1)) == Pre[m]) {
        pr = su = m;
      }
    }
    for (j = 1; j <= m && j <= L; j++) {
      if ((i >> (L - j)) == Suf[j]) su = max(su, j);
      if ((i & ((1 << j) - 1)) == Pre[j]) pr = max(pr, j);
    }
    if (pv == 0)
      A[pr][su]++;
    else
      B[pr][su]++;
  }
}
void Go() {
  int i;
  for (i = 0; i < n; i++) {
    Do(i, 0, 0);
  }
  for (i = 0; i < cnt; i++) {
    C[U[i] & 1048575]++;
  }
  for (i = 1; i < (1 << 20); i++) C[i] += C[i - 1];
  for (i = 0; i < cnt; i++) {
    TP[--C[U[i] & 1048575]] = U[i];
  }
  for (i = 0; i < (1 << 20); i++) C[i] = 0;
  for (i = 0; i < cnt; i++) {
    C[TP[i] >> 20]++;
  }
  for (i = 1; i < (1 << 20); i++) C[i] += C[i - 1];
  for (i = cnt - 1; i >= 0; i--) {
    U[--C[TP[i] >> 20]] = TP[i];
  }
  int res = cnt;
  for (i = 1; i < cnt; i++) {
    if (U[i] == U[i - 1]) res--;
  }
  printf("%d\n", res);
}
int main() {
  int i, j, k;
  scanf("%d", &n);
  scanf("%s", p);
  m = strlen(p);
  if (n - m < 19) {
    Go();
    return 0;
  }
  for (i = 0; i < m; i++) {
    Pre[i + 1] = Pre[i] * 2 + p[i] - '0';
  }
  for (i = m - 1; i >= 0; i--) {
    Suf[m - i] = Suf[m - i - 1] + ((p[i] - '0') << (m - i - 1));
  }
  Calc((n + 1) / 2, 0);
  Calc(n / 2, 1);
  for (i = 0; i <= m; i++)
    for (j = 0; j <= m; j++) {
      long long s = Pre[i];
      s = (s << j) + Suf[j];
      for (k = 0; k <= i + j - m; k++) {
        if (((s >> k) & ((1 << m) - 1)) == Pre[m]) OK[i][j] = 1;
      }
    }
  long long res = 0;
  for (i = 0; i <= m; i++)
    for (j = 0; j <= m; j++)
      for (int ii = 0; ii <= m; ii++)
        for (int jj = 0; jj <= m; jj++) {
          if (!OK[i][jj] && !OK[ii][j]) continue;
          res += 1ll * A[i][j] * B[ii][jj];
        }
  printf("%lld\n", res);
}
