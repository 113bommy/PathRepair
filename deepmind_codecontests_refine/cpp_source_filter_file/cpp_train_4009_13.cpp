#include <bits/stdc++.h>
using namespace std;
const int N = 1 << 16, P = 1000000007;
int i, j, k, n, m, T, a, b, c, d, x, f1, f0, ans;
int f[150][N], tmp1[N], tmp2[N];
int A[9][N];
char s[550];
void FMT_or(int *a, int fg) {
  int i, j;
  for (i = 1; i < N; i <<= 1)
    for (j = 0; j < N; j++)
      if (j & i) {
        if (!fg)
          a[j] = (a[j] + a[j ^ i]) % P;
        else
          a[j] = (a[j] + P - a[j ^ i]) % P;
      }
}
void FMT_and(int *a, int fg) {
  int i, j;
  for (i = 1; i < N; i <<= 1)
    for (j = 0; j < N; j++)
      if (j & i) {
        if (!fg)
          a[j ^ i] = (a[j ^ i] + a[j]) % P;
        else
          a[j ^ i] = (a[j ^ i] + P - a[j]) % P;
      }
}
int *solve(int l, int r) {
  int *F = f[T++];
  if (l == r) {
    if ('A' <= s[l] && s[l] <= 'D') return A[s[l] - 'A'];
    if ('a' <= s[l] && s[l] <= 'd') return A[s[l] - 'a' + 4];
    return A[8];
  }
  int i, j, nm = 0;
  for (i = l; i <= r; i++) {
    if (s[i] == '(') {
      nm++;
      continue;
    }
    if (s[i] == ')') {
      nm--;
      continue;
    }
    if (!nm) {
      int *fl = solve(l + 1, i - 2);
      int *fr = solve(i + 2, r - 1);
      if (s[i] == '|' || s[i] == '?') {
        for (j = 0; j < N; j++) tmp1[j] = fl[j], tmp2[j] = fr[j];
        FMT_or(tmp1, 0);
        FMT_or(tmp2, 0);
        for (j = 0; j < N; j++) tmp1[j] = (long long)tmp1[j] * tmp2[j] % P;
        FMT_or(tmp1, 1);
        for (j = 0; j < N; j++) F[j] = (F[j] + tmp1[j]) % P;
      }
      if (s[i] == '&' || s[i] == '?') {
        for (j = 0; j < N; j++) tmp1[j] = fl[j], tmp2[j] = fr[j];
        FMT_and(tmp1, 0);
        FMT_and(tmp2, 0);
        for (j = 0; j < N; j++) tmp1[j] = (long long)tmp1[j] * tmp2[j] % P;
        FMT_and(tmp1, 1);
        for (j = 0; j < N; j++) F[j] = (F[j] + tmp1[j]) % P;
      }
      break;
    }
  }
  return F;
}
void pre() {
  int a, b, c, d, t;
  int fA = 0, fB = 0, fC = 0, fD = 0, fa = 0, fb = 0, fc = 0, fd = 0;
  for (a = 0; a < 2; a++)
    for (b = 0; b < 2; b++)
      for (c = 0; c < 2; c++)
        for (d = 0; d < 2; d++) {
          t = 1 << (d << 3 | c << 2 | b << 1 | a);
          if (a)
            fA |= t;
          else
            fa |= t;
          if (b)
            fB |= t;
          else
            fb |= t;
          if (c)
            fC |= t;
          else
            fc |= t;
          if (d)
            fD |= t;
          else
            fd |= t;
        }
  A[0][fA] = A[8][fA] = 1;
  A[1][fB] = A[8][fB] = 1;
  A[2][fC] = A[8][fC] = 1;
  A[3][fD] = A[8][fD] = 1;
  A[4][fa] = A[8][fa] = 1;
  A[5][fb] = A[8][fb] = 1;
  A[6][fc] = A[8][fc] = 1;
  A[7][fd] = A[8][fd] = 1;
}
int main() {
  pre();
  scanf("%s", s + 1);
  n = strlen(s + 1);
  scanf("%d", &m);
  for (i = 1; i <= m; i++) {
    scanf("%d%d%d%d%d", &a, &b, &c, &d, &x);
    if (x == 1) f1 |= 1 << (d << 3 | c << 2 | b << 1 | a);
    if (x == 0) f0 |= 1 << (d << 3 | c << 2 | b << 1 | a);
  }
  int *F = solve(1, n);
  for (i = 0; i < N; i++)
    if ((i & f1) == f1 && (i & f0) == 0) ans = (ans + F[i]) % P;
  printf("%d\n", T);
}
