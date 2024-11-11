#include <bits/stdc++.h>
using namespace std;
const int F = 222222;
const int INF = 1e9 + 7;
inline int read() {
  int X = 0;
  bool flag = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') flag = 0;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9')
    X = (X << 1) + (X << 3) + ch - '0', ch = getchar();
  if (flag) return X;
  return (X - 1);
}
int a[F];
int ans = INF;
int main() {
  int n = read();
  for (int i = 1; i <= n; i++) {
    a[i] = read();
  }
  sort(a + 1, a + n + 1);
  for (int i = 1; i <= n / 2; i++) {
    ans = min(ans, a[i + n / 2] - a[i]);
  }
  printf("%d", ans);
  return 0;
}
