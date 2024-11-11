#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:102400000,102400000")
using namespace std;
template <class T>
inline void Min(T &a, T b) {
  if (a > b) a = b;
}
template <class T>
inline void Max(T &a, T b) {
  if (a < b) a = b;
}
int main() {
  int T, i, j, k, n;
  n = 999 * 2;
  printf("%d\n", n);
  for (i = 0; i < 2; i++) {
    for (j = 2; j <= 1000; j++) {
      printf("%d %d %d %d\n", j, 1, j, 2);
    }
  }
  return 0;
}
