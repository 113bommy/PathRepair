#include <bits/stdc++.h>
using namespace std;
inline int read() {
  char v = getchar();
  int x = 0, f = 1;
  while (!isdigit(v)) {
    if (x == '-') {
      f = -1;
    }
    v = getchar();
  }
  while (isdigit(v)) {
    x = x * 10 + v - 48;
    v = getchar();
  }
  return x * f;
}
const int N = 5001;
const int INF = 520060329;
int dp[N], n, m, a[N], b[N], g[N], p;
void Print(int p) {
  if (!p) return;
  Print(g[p]);
  printf("%d\n", b[p]);
}
int main() {
  n = read();
  for (int i = 1; i <= n; ++i) {
    a[i] = read();
  }
  m = read();
  for (int i = 1; i <= m; ++i) {
    b[i] = read();
  }
  for (int i = 1; i <= n; ++i) {
    int tmp = 0;
    for (int j = 1; j <= m; ++j) {
      if (a[i] == b[j]) {
        dp[j] = dp[tmp] + 1;
        g[j] = tmp;
      }
      if (a[i] > b[j] && dp[tmp] < dp[j]) {
        tmp = j;
      }
    }
  }
  for (int i = 1; i <= m; ++i) {
    if (dp[i] > dp[p]) {
      p = i;
    }
  }
  printf("%d\n", dp[p]);
  Print(p);
  return 0;
}
