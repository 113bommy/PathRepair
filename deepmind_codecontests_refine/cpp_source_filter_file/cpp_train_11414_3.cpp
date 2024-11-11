#include <bits/stdc++.h>
using namespace std;
template <typename T, typename U>
inline void smin(T &a, U b) {
  if (a > b) a = b;
}
template <typename T, typename U>
inline void smax(T &a, U b) {
  if (a < b) a = b;
}
template <class T>
inline void gn(T &first) {
  char c, sg = 0;
  while (c = getchar(), (c > '9' || c < '0') && c != '-')
    ;
  for ((c == '-' ? sg = 1, c = getchar() : 0), first = 0; c >= '0' && c <= '9';
       c = getchar())
    first = (first << 1) + (first << 3) + c - '0';
  if (sg) first = -first;
}
template <class T1, class T2>
inline void gn(T1 &x1, T2 &x2) {
  gn(x1), gn(x2);
}
template <class T1, class T2, class T3>
inline void gn(T1 &x1, T2 &x2, T3 &x3) {
  gn(x1), gn(x2), gn(x3);
}
template <class T1, class T2, class T3, class T4>
inline void gn(T1 &x1, T2 &x2, T3 &x3, T4 &x4) {
  gn(x1), gn(x2), gn(x3), gn(x4);
}
template <class T>
inline void print(T first) {
  if (first < 0) {
    putchar('-');
    return print(-first);
  }
  if (first < 10) {
    putchar('0' + first);
    return;
  }
  print(first / 10);
  putchar(first % 10 + '0');
}
template <class T>
inline void printsp(T first) {
  print(first);
  putchar(' ');
}
template <class T>
inline void println(T first) {
  print(first);
  putchar('\n');
}
template <class T1, class T2>
inline void print(T1 x1, T2 x2) {
  printsp(x1), println(x2);
}
template <class T1, class T2, class T3>
inline void print(T1 x1, T2 x2, T3 x3) {
  printsp(x1), printsp(x2), println(x3);
}
template <class T1, class T2, class T3, class T4>
inline void print(T1 x1, T2 x2, T3 x3, T4 x4) {
  printsp(x1), printsp(x2), printsp(x3), println(x4);
}
int power(int a, int b, int m, int ans = 1) {
  for (; b; b >>= 1, a = 1LL * a * a % m)
    if (b & 1) ans = 1LL * ans * a % m;
  return ans;
}
char s[5][256];
int m[5];
int dp[1010][256];
int first[5], mx[5];
int main() {
  int n;
  gn(n);
  for (int i = 1; i <= 4; i++) {
    gn(m[i]);
  }
  for (int i = 1; i <= 4; i++) {
    scanf("%s", s[i] + 1);
  }
  for (int i = 0; i <= n; i++) {
    for (int j = 0; j < 256; j++) {
      dp[i][j] = 0x3f3f3f3f;
    }
  }
  dp[0][0] = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < 256; j++) {
      int u = j;
      for (int k = 1; k <= 4; k++) {
        first[k] = u % 4;
        u /= 4;
      }
      for (int a = 0; a <= 4; a++) {
        for (int b = 0; b <= 3; b++) {
          for (int c = 0; c <= 2; c++) {
            for (int d = 0; d <= 1; d++) {
              for (int k = 1; k <= 4; k++) {
                mx[k] = first[k];
              }
              for (int k = 1; k <= a; k++) {
                smax(mx[k], a);
              }
              for (int k = 1; k <= b; k++) {
                smax(mx[k + 1], b);
              }
              for (int k = 1; k <= c; k++) {
                smax(mx[k + 2], c);
              }
              for (int k = 1; k <= d; k++) {
                smax(mx[k + 3], d);
              }
              int ok = 1;
              for (int k = 1; k <= 4; k++) {
                if (mx[k] == 0 and s[k][i] == '*') {
                  ok = 0;
                  break;
                }
              }
              if (ok) {
                u = 0;
                for (int k = 4; k >= 1; k--) {
                  u = u * 4 + max(mx[k] - 1, 0);
                }
                smin(dp[i][u], dp[i - 1][j] + m[a] + m[b] + m[c] + m[d]);
              }
            }
          }
        }
      }
    }
  }
  int ans = 0x3f3f3f3f;
  for (int i = 0; i < 256; i++) {
    smin(ans, dp[n][i]);
  }
  println(ans);
}
