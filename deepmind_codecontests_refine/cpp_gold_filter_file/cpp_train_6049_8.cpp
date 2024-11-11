#include <bits/stdc++.h>
using namespace std;
int input() {
  int x = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') x = x * 10 + ch - '0', ch = getchar();
  return f * x;
}
int n, a, b;
int q[27];
void solve() {
  int ans = 0;
  n = input();
  a = input();
  b = input();
  for (int i = 1; i <= n; i++) q[i] = input();
  for (int i = 1; i <= n / 2; i++) {
    if (q[i] == 2 && q[n - i + 1] == 2) ans += 2 * min(a, b);
    if (q[i] != q[n - i + 1]) {
      if (q[i] != 2 && q[n - i + 1] != 2) {
        printf("-1\n");
        return;
      }
      if (q[i] == 0) ans += a;
      if (q[i] == 1) ans += b;
      if (q[n - i + 1] == 0) ans += a;
      if (q[n - i + 1] == 1) ans += b;
    }
  }
  if (n % 2 == 1 && q[n / 2 + 1] == 2) ans += min(a, b);
  printf("%d\n", ans);
}
int main() { solve(); }
