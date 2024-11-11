#include <bits/stdc++.h>
using namespace std;
const int N = 300005;
const int inf = 1 << 30;
const long long inff = 1ll << 60;
inline int read() {
  int x = 0, f = 1;
  char c = getchar();
  while (c < '0' || c > '9') {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    x = (x << 1) + (x << 3) + (c ^ 48);
    c = getchar();
  }
  return x * f;
}
int n, f[N];
int main() {
  int tests = 1;
  tests = read();
  while (tests--) {
    n = read();
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= i; j++) printf("(");
      for (int j = 1; j <= i; j++) printf(")");
      for (int j = 1; j + (i - 1) <= n; j++) printf("()");
      puts("");
    }
  }
  return 0;
}
