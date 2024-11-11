#include <bits/stdc++.h>
using namespace std;
inline int read() {
  int x = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return x * f;
}
const int N = 1000005;
int a, b[13];
int ans, n;
int main() {
  n = read();
  for (int i = 1; i <= 12; i++) b[i] = b[i - 1] + i;
  for (int i = 1; i <= n; i++) {
    a = read();
    int p = 12;
    for (int j = 1; j <= 12; j++) {
      if (b[j] + j >= a) {
        p = j;
        break;
      }
    }
    if (i == 1)
      ans = p;
    else
      ans = ans ^ p;
  }
  if (ans == 0)
    printf("YES");
  else
    printf("NO");
  return 0;
}
