#include <bits/stdc++.h>
using namespace std;
const int N = 110;
const int R = 30010;
const int INF = 1 << 30;
int read() {
  int w = 0, f = 0;
  char c = getchar();
  while ((c < '0' || c > '9') && c != '-') c = getchar();
  if (c == '-') f = 1, c = getchar();
  while (c >= '0' && c <= '9') w = w * 10 + c - '0', c = getchar();
  return f ? -w : w;
}
int f[N][R], a[N], b[N], ans = 0;
int n, second;
int main() {
  n = read(), second = read();
  for (int i = 1; i <= n; ++i) {
    a[i] = read(), b[i] = read();
    if (b[i] < 0) a[i] = max(a[i], abs(b[i]));
  }
  int lm = 0;
  for (int i = 1; i <= n; ++i) {
    for (int j = i + 1; j <= n; ++j)
      if (b[j] > b[i]) swap(a[i], a[j]), swap(b[i], b[j]);
    if (b[i] >= 0) lm = i;
  }
  for (int i = 1; i <= lm; ++i)
    for (int j = i + 1; j <= lm; ++j)
      if (a[j] < a[i]) swap(a[j], a[i]), swap(b[j], b[i]);
  for (int i = lm + 1; i <= n; ++i)
    for (int j = i + 1; j <= n; ++j)
      if (a[j] + b[j] > a[i] + b[i]) swap(a[j], a[i]), swap(b[j], b[i]);
  for (int i = 0; i < R; ++i) f[0][i] = (i <= second ? 0 : -INF);
  for (int i = 1; i <= n; ++i)
    for (int j = 0; j < R; ++j) {
      f[i][j] = f[i - 1][j];
      if (j - b[i] >= a[i] && j - b[i] >= 0 && j - b[i] < R)
        f[i][j] = max(f[i][j], f[i - 1][j - b[i]] + 1);
      ans = max(ans, f[i][j]);
    }
  cout << ans << endl;
  return 0;
}
