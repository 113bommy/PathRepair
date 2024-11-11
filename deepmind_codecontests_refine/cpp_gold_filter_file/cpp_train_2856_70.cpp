#include <bits/stdc++.h>
using namespace std;
inline long long IN() {
  long long x = 0;
  int ch = getchar(), f = 1;
  while (!isdigit(ch) && (ch != '-') && (ch != EOF)) ch = getchar();
  if (ch == '-') {
    f = -1;
    ch = getchar();
  }
  while (isdigit(ch)) {
    x = (x << 1) + (x << 3) + ch - '0';
    ch = getchar();
  }
  return x * f;
}
inline void OUT(long long x) {
  if (x < 0) putchar('-'), x = -x;
  if (x >= 10)
    OUT(x / 10), putchar(x % 10 + '0');
  else
    putchar(x + '0');
}
int Ans[16] = {1, 0, 0, 1, 0, 1, 0, 1, 1, 1, 0, 0, 1, 0, 1, 0};
int main() {
  int n = IN();
  OUT(Ans[n - 1]);
}
