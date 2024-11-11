#include <bits/stdc++.h>
using namespace std;
template <class T>
inline void read(T& x) {
  bool fu = 0;
  char c;
  for (c = getchar(); c <= 32; c = getchar())
    ;
  if (c == '-') fu = 1, c = getchar();
  for (x = 0; c > 32; c = getchar()) x = x * 10 + c - '0';
  if (fu) x = -x;
};
template <class T>
inline void read(T& x, T& y) {
  read(x);
  read(y);
}
template <class T>
inline void read(T& x, T& y, T& z) {
  read(x);
  read(y);
  read(z);
}
inline char getc() {
  char c;
  for (c = getchar(); c <= 32; c = getchar())
    ;
  return c;
}
const int inf = int(1e9);
int n, m, i, j, k, l, p2, p, f, ans;
int L[155], R[155];
char a[155][155];
bool kong(int n) {
  int i;
  for (i = 1; i <= m; i++)
    if (a[n][i] == 'W') return 0;
  return 1;
}
int main() {
  read(n, m);
  for (i = 1; i <= n; i++) scanf("%s", a[i] + 1);
  for (i = 1; i <= n; i++) L[i] = inf, R[i] = 0;
  for (i = 1; i <= n; i++)
    for (j = 1; j <= m; j++)
      if (a[i][j] == 'W') L[i] = min(L[i], j), R[i] = max(R[i], j);
  int t = n;
  for (; t > 1 && kong(t); t--)
    ;
  p = 1;
  f = 1;
  L[n + 1] = inf;
  for (i = 1; i <= t; i++) {
    if (f == 1) {
      p2 = max(max(R[i], R[i + 1]), p);
      ans += p2 - p;
      p = p2;
      f = -1;
      ans++;
    } else {
      p2 = min(min(L[i], L[i + 1]), p);
      ans += p - p2;
      p = p2;
      f = 1;
      ans++;
    }
  }
  printf("%d\n", ans - 1);
  scanf("\n");
  return 0;
}
