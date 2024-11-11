#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 51;
int test;
int n, r, sum;
inline int read() {
  register int num = 0, neg = 1;
  register char ch = getchar();
  while (!isdigit(ch) && ch != '-') {
    ch = getchar();
  }
  if (ch == '-') {
    neg = -1;
    ch = getchar();
  }
  while (isdigit(ch)) {
    num = (num << 3) + (num << 1) + (ch - '0');
    ch = getchar();
  }
  return num * neg;
}
inline void solve() {
  n = read(), r = read(), sum = 0;
  for (register int i = 1; i <= n - 1; i++) {
    sum += read();
  }
  printf("%d\n", (sum - r + n) % n + 1);
}
int main() {
  test = read();
  for (register int i = 0; i < test; i++) {
    solve();
  }
}
