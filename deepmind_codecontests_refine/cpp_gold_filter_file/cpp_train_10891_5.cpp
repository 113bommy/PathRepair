#include <bits/stdc++.h>
using namespace std;
const int MAXN = 5e4 + 5;
const long long mod = 1e9 + 7;
const int inf = 0x3f3f3f3f;
template <class T>
inline bool read(T &ret) {
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
int main() {
  int n;
  read(n);
  int a, b, x0, ans0, ans1, flag, x1;
  printf("? ");
  for (int i = 1; i <= n; ++i) printf("0");
  printf("\n");
  fflush(stdout);
  read(x0);
  printf("? 1");
  for (int i = 2; i <= n; ++i) printf("0");
  printf("\n");
  fflush(stdout);
  read(x1);
  if (x0 > x1) {
    ans1 = 1;
    flag = 1;
  } else {
    ans0 = 1;
    flag = -1;
  }
  a = 2;
  b = n - 1;
  while (1) {
    if (b == 1) {
      if (flag == 1)
        ans0 = a;
      else
        ans1 = a;
      break;
    }
    printf("? ");
    for (int i = 1; i <= n; ++i) {
      if (i >= a && i <= a + b / 2 - 1)
        printf("1");
      else
        printf("0");
    }
    printf("\n");
    fflush(stdout);
    read(x1);
    if ((x1 - x0) * flag == b / 2) {
      if (flag == 1)
        ans0 = a;
      else
        ans1 = a;
      break;
    }
    if ((x1 - x0) * flag == -b / 2) {
      a = a + b / 2;
      b = b - (b / 2);
    } else
      b = b / 2;
  }
  printf("! %d %d\n", ans0, ans1);
  fflush(stdout);
  return 0;
}
