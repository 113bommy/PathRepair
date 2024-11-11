#include <bits/stdc++.h>
using namespace std;
int read() {
  int f = 1, x = 0;
  char c = getchar();
  while (c < '0' || c > '9') {
    if (c == '-') f = -f;
    c = getchar();
  }
  while (c >= '0' && c <= '9') x = x * 10 + c - '0', c = getchar();
  return f * x;
}
int n, a[100005];
void init() {
  n = read();
  for (int i = 1; i <= n; ++i) a[i] = read();
}
void solve() {
  sort(a + 1, a + n + 1);
  int ans = 0;
  for (int i = n - 1; i >= 1; --i) {
    if (a[i] >= i) {
      ans = i - 1;
      break;
    }
  }
  printf("%d\n", ans);
}
int main() {
  int T = read();
  for (int i = 0; i < T; ++i) {
    init();
    solve();
  }
  return 0;
}
