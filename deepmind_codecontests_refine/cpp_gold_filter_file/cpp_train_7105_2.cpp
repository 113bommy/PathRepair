#include <bits/stdc++.h>
const int MAXN = 4e5 + 10;
const double eps = 1e-8;
const long long inf = 1e18 + 7;
using namespace std;
struct edge {
  int t, v;
  edge *next;
} e[MAXN << 1], *h[MAXN], *o = e;
void add(int x, int y, int w) {
  o->t = y;
  o->v = w;
  o->next = h[x];
  h[x] = o++;
}
long long read() {
  long long x = 0, f = 1;
  char ch = getchar();
  while (!isdigit(ch)) {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (isdigit(ch)) x = x * 10 + ch - '0', ch = getchar();
  return x * f;
}
int n, a[MAXN];
long long dp[MAXN];
int main() {
  n = read();
  for (int i = 1; i <= n; i++) a[i] = read();
  if (n == 1)
    return 0 * printf("%d\n", a[1]);
  else if (n == 3) {
    int minn = 1e9 + 7;
    long long sum = 0;
    for (int i = 1; i <= n; i++) minn = min(minn, a[i]), sum += a[i];
    return 0 * printf("%lld\n", sum - minn);
  }
  for (int i = n + 1; i <= 2 * n; i++) a[i] = a[i - n];
  for (int i = 2 * n; i >= 1; i--) dp[i] = a[i] + dp[i + 2];
  long long maxx = 0;
  for (int i = 1; i <= n; i++) {
    maxx = max(maxx, a[i] + a[i + 1] + dp[i + 3] - dp[i + n]);
  }
  printf("%lld\n", maxx);
  return 0;
}
