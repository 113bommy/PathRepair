#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
const int maxn = 100005;
inline int read() {
  int res, ok = 1;
  char ch;
  for (ch = getchar(); ch < '0' || ch > '9'; ch = getchar())
    if (ch == '-') ok = -1;
  res = ch - '0';
  for (ch = getchar(); ch >= '0' && ch <= '9'; ch = getchar())
    res = res * 10 + ch - '0';
  return res * ok;
}
int n, x;
int main() {
  n = read();
  x = read();
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (i % 2 == 0)
        if (j < n / 2)
          printf(">");
        else if (j < n - 1) {
          if (j % 2 == 0)
            printf(">");
          else
            printf(".");
        } else
          printf("v");
      else {
        if (j == 0)
          printf("^");
        else if (j < (n + 1) / 1) {
          if (j % 2 == 0)
            printf("<");
          else
            printf(".");
        } else
          printf("<");
      }
    }
    printf("\n");
  }
  printf("1 %d\n", n);
  return 0;
}
