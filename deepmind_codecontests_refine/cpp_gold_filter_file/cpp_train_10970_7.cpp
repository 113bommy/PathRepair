#include <bits/stdc++.h>
using namespace std;
int read() {
  char ch = getchar();
  int h = 0, t = 1;
  while (ch != '-' && (ch > '9' || ch < '0')) ch = getchar();
  if (ch == '-') t = -1, ch = getchar();
  while (ch >= '0' && ch <= '9') h = h * 10 + ch - '0', ch = getchar();
  return h * t;
}
const int N = 210000;
int n, w[N], p[N], l[N], r[N], vis[N], qq[N], dp[N], sta[N], top;
map<pair<int, int>, int> Map;
int main() {
  n = read();
  for (int i = 1; i <= n; i++)
    w[i] = read(), p[i] = read(), l[i] = read(), r[i] = read();
  for (int i = 1; i <= n; i++)
    if (l[i] == 0) vis[i] = 1, dp[i] = w[i];
  for (int i = 1; i <= n; i++) {
    int f = Map[make_pair(l[i], r[i] + p[i])];
    if (f) dp[i] = dp[f] + w[i], qq[i] = f, vis[i] = 1;
    if (vis[i] && dp[Map[make_pair(l[i] + p[i], r[i])]] <= dp[i])
      Map[make_pair(l[i] + p[i], r[i])] = i;
  }
  int x = 0;
  for (int i = 1; i <= n; i++)
    if (dp[i] > dp[x] && r[i] == 0) x = i;
  if (!x) return puts("0"), 0;
  while (x) sta[++top] = x, x = qq[x];
  printf("%d\n", top);
  while (top) printf("%d ", sta[top--]);
  puts("");
  return 0;
}
