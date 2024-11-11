#include <bits/stdc++.h>
using namespace std;
inline int read() {
  int x = 0;
  char c = getchar();
  while (c < '0' || c > '9') c = getchar();
  while (c >= '0' && c <= '9') x = (x << 3) + (x << 1) + c - '0', c = getchar();
  return x;
}
const int maxn = 2e5 + 10;
const int mod = 1e9 + 7;
const double eps = 1e-9;
int n;
int a[maxn], ans[maxn];
int main() {
  n = read();
  for (int i = 1; i <= n; ++i) {
    a[i] = read();
  }
  a[n + 1] = 2e9;
  int mx = -1, mi = 1e9;
  for (int i = 1; i <= n; ++i) {
    if (a[i] > mx && (a[i] < a[i + 1] || a[i] >= mi)) {
      mx = a[i], ans[i] = 0;
    } else if (a[i] < mi) {
      mi = a[i], ans[i] = 1;
    } else
      return printf("NO\n"), 0;
  }
  printf("YES\n");
  for (int i = 1; i <= n; ++i) printf("%d%c", ans[i], " \n"[i == n]);
}
