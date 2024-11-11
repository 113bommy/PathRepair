#include <bits/stdc++.h>
using namespace std;
template <class T>
inline void MAX(T &x, T y) {
  if (y > x) x = y;
}
template <class T>
inline void MIN(T &x, T y) {
  if (y < x) x = y;
}
template <class T>
inline void rd(T &x) {
  x = 0;
  char o, f = 1;
  while (o = getchar(), o < 48)
    if (o == 45) f = -f;
  do x = (x << 3) + (x << 1) + (o ^ 48);
  while (o = getchar(), o > 47);
  x *= f;
}
const int M = 1005;
int n, ans, A[M], B[M], Q[M][M];
int main() {
  rd(n);
  for (int i = 1; i <= n; i++) rd(A[i]);
  int op = 1;
  for (int i = 1; i <= n; i++) {
    ++ans;
    if (op == 0) {
      for (int j = 1; j < i; j++) Q[ans][++Q[ans][0]] = 1;
      for (int j = 1; j <= n; j++)
        if (A[j] == i) {
          Q[ans][++Q[ans][0]] = j - i + 1;
          if (j < n) Q[ans][++Q[ans][0]] = n - j;
        }
    } else {
      for (int j = 1; j <= n; j++)
        if (A[j] == i) {
          if (j > 1) Q[ans][++Q[ans][0]] = j - 1;
          Q[ans][++Q[ans][0]] = n - i + 1 - j + 1;
        }
      for (int j = 1; j < i; j++) Q[ans][++Q[ans][0]] = 1;
    }
    op ^= 1;
    if (Q[ans][0] < 2)
      Q[ans][0] = 0, ans--;
    else {
      for (int j = 1; j <= n; j++) B[j] = A[j];
      int a = 0, b = n;
      for (int j = Q[ans][0]; j >= 1; j--) {
        b -= Q[ans][j];
        for (int k = 1; k <= Q[ans][j]; k++) A[++a] = B[b + k];
      }
    }
  }
  printf("%d\n", ans);
  for (int i = 1; i <= ans; i++) {
    for (int j = 0; j <= Q[i][0]; j++)
      printf("%d%c", Q[i][j], j == Q[i][0] ? '\n' : ' ');
  }
  return (0 - 0);
}
