#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:102400000,102400000")
using namespace std;
const int MOD = 1000000007;
const int INF = 0x3f3f3f3f;
const int N = 500100;
const int M = 100010;
const int Mat = 110;
typedef double Matrix[Mat][Mat];
const double eps = 1e-10;
inline int readint() {
  char c = getchar();
  while (c < '0' || c > '9') c = getchar();
  int x = 0;
  while ('0' <= c && c <= '9') {
    x = x * 10 + c - '0';
    c = getchar();
  }
  return x;
}
int buf[10];
inline void writeint(int i) {
  int p = 0;
  if (i == 0)
    p++;
  else
    while (i) {
      buf[p++] = i % 10;
      i /= 10;
    }
  for (int j = p - 1; j >= 0; j--) putchar('0' + buf[j]);
}
int n, m, ans;
int A[N];
void f(int l, int r) {
  int res = 0, i;
  if (A[l] == A[r]) {
    for (i = l + 1; i < r; i++) {
      if (A[i] != A[l]) res++;
    }
    for (i = l + 1; i < r; i++) A[i] = A[l];
  } else {
    res = (r - l - 1) / 2;
    for (i = l + 1; i <= l + res; i++) A[i] = A[l];
    for (i = r - 1; i >= r - res; i--) A[i] = A[r];
  }
  if (res > ans) ans = res;
}
void solve() {
  int i, j, k;
  ans = 0;
  scanf("%d", &n);
  for (i = 1; i <= n; i++) {
    scanf("%d", &A[i]);
  }
  A[0] = A[1];
  A[n + 1] = A[n];
  i = 2;
  j = 1;
  while (i <= n) {
    if (A[i] == A[i + 1]) {
      f(j, i);
      i++;
      j = i;
    } else
      i++;
  }
  printf("%d\n", ans);
  for (i = 1; i < n; i++) printf("%d ", A[i]);
  printf("%d\n", A[n]);
  return;
}
int main() {
  int i, T = 1;
  for (i = 1; i <= T; i++) {
    solve();
  }
  return 0;
}
