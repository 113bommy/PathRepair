#include <bits/stdc++.h>
using namespace std;
int read() {
  int ret = 0, f = 1;
  char ch = getchar();
  while (!isdigit(ch) && (ch ^ '-')) ch = getchar();
  if (ch == '-') f = -1, ch = getchar();
  while (isdigit(ch)) {
    ret = (ret << 3) + (ret << 1) + (ch ^ '0'), ch = getchar();
  }
  return ret * f;
}
long long readll() {
  long long ret = 0, f = 1;
  char ch = getchar();
  while (!isdigit(ch) && (ch ^ '-')) ch = getchar();
  if (ch == '-') f = -1, ch = getchar();
  while (isdigit(ch)) {
    ret = (ret << 3) + (ret << 1) + (ch ^ '0'), ch = getchar();
  }
  return ret * f;
}
const int maxn = 3 * 1e5 + 10;
int n;
long long ans;
long long val[maxn][2];
long long sum[maxn][2], nxt[maxn][2];
long long f[maxn][2], g[maxn][2];
int main() {
  n = read();
  for (int i = 1; i <= n; ++i) {
    val[i][0] = readll();
  }
  for (int i = 1; i <= n; ++i) {
    val[i][1] = readll();
  }
  for (int i = n; i >= 1; --i) {
    sum[i][0] = sum[i + 1][0] + val[i][0];
    sum[i][1] = sum[i + 1][1] + val[i][1];
    nxt[i][0] = nxt[i + 1][0] + val[i][0] * i;
    nxt[i][1] = nxt[i + 1][1] + val[i][1] * i;
  }
  for (int i = 1; i <= n; ++i) {
    if (i & 1) {
      f[i][0] = f[i - 1][0] + (2 * (i - 1)) * val[i][0];
      f[i][1] = f[i][0] + (2 * (i - 1) + 1) * val[i][1];
    } else {
      f[i][1] = f[i - 1][1] + (2 * (i - 1)) * val[i][1];
      f[i][0] = f[i][1] + (2 * (i - 1) + 1) * val[i][0];
    }
  }
  for (int i = 1; i <= n; ++i) {
    if (!(i & 1)) {
      g[i][1] = nxt[i][1] + (2 * (i - 1) - i) * sum[i][1];
      g[i][1] += (2 * (i - 1) + 2 * n - 2 * +2) * sum[i][0] - nxt[i][0];
    } else {
      g[i][0] = nxt[i][0] + (2 * (i - 1) - i) * sum[i][0];
      g[i][0] += (2 * (i - 1) + 2 * n - 2 * i + 2) * sum[i][1] - nxt[i][1];
    }
  }
  for (int i = 0; i <= n; ++i) {
    if (i & 1) {
      ans = max(ans, f[i][1] + g[i + 1][1]);
    } else {
      ans = max(ans, f[i][0] + g[i + 1][0]);
    }
  }
  cout << ans << endl;
  return 0;
}
