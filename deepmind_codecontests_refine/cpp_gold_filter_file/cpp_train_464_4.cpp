#include <bits/stdc++.h>
using namespace std;
inline void getInt(int &x) {
  char c = 0;
  int sign = 1;
  while ((c < '0' || c > '9') && c != '-') {
    c = getchar();
  };
  if (c == '-') {
    sign = -1;
    c = getchar();
  }
  x = c - '0';
  while ((c = getchar()) >= '0' && c <= '9') {
    x = x * 10 + c - '0';
  }
  x *= sign;
}
int main() {
  int n, k, m;
  getInt(n);
  getInt(k);
  int ans = 2 * n - k + 1;
  while (k--) {
    getInt(m);
    for (int i = 0, c = 0, x; i < m; i++) {
      getInt(x);
      if (x == c + 1) {
        c++;
        ans -= 2;
      }
    }
  }
  printf("%d\n", ans);
}
