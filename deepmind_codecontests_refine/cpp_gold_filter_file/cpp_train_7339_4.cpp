#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:102400000,102400000")
using namespace std;
const int N = 105;
template <class T>
inline bool rd(T &ret) {
  char c;
  int sgn;
  if (c = getchar(), c == EOF) return 0;
  while (c != '-' && (c < '0' || c > '9')) c = getchar();
  sgn = (c == '-') ? -1 : 1;
  ret = (c == '-') ? 0 : (c - '0');
  while (c = getchar(), c >= '0' && c <= '9') ret = ret * 10 + (c - '0');
  ret *= sgn;
  return 1;
}
template <class T>
inline void pt(T x) {
  if (x < 0) {
    putchar('-');
    x = -x;
  }
  if (x > 9) pt(x / 10);
  putchar(x % 10 + '0');
}
int n = 8;
char a[10][10];
int main() {
  for (int i = 0; i < n; i++) {
    scanf("%s", a[i]);
  }
  int A = 9, B = 9, now = 0;
  for (int j = 0; j < n; j++) {
    now = 9;
    for (int i = 0; i < n; i++) {
      if (a[i][j] == 'W') {
        now = i;
        A = min(A, now);
        break;
      } else if (a[i][j] == 'B')
        break;
    }
  }
  for (int j = 0; j < n; j++) {
    now = 9;
    for (int i = n - 1; i >= 0; i--) {
      if (a[i][j] == 'B') {
        now = 7 - i;
        B = min(B, now);
        break;
      } else if (a[i][j] == 'W')
        break;
    }
  }
  if (A <= B)
    puts("A");
  else
    puts("B");
  return 0;
}
