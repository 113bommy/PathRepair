#include <bits/stdc++.h>
using namespace std;
inline long long read() {
  register long long x = 0, f = 1;
  register char c = getchar();
  for (; !isdigit(c); c = getchar())
    if (c == '-') f = -1;
  for (; isdigit(c); c = getchar()) x = (x << 1) + (x << 3) + (c ^ 48);
  return x * f;
}
void write(long long x) {
  if (x < 0) x = -x, putchar('-');
  if (x >= 10) write(x / 10);
  putchar(x % 10 + '0');
}
void writeln(long long x) {
  write(x);
  puts("");
}
const int maxn = 2e5 + 233;
int size[maxn], dp[maxn], cnt, tag[maxn], res, n, k, a[maxn];
vector<int> edge[maxn];
void pre(int u, int fa) {
  size[u] = 1;
  for (auto v : edge[u])
    if (v != fa) pre(v, u), size[u] += size[v];
}
void dfs(int u, int fa) {
  if (res >= k) return;
  int all = 0, mx1 = 0, mx2 = 0;
  for (auto v : edge[u]) {
    if (v == fa) continue;
    dfs(v, u);
    tag[u] += tag[v];
    if (dp[v] == tag[v])
      all += size[v];
    else if (dp[v] > mx1)
      mx2 = mx1, mx1 = dp[v];
    else if (dp[v] > mx2)
      mx2 = dp[v];
  }
  if (!a[u])
    dp[u] = 0;
  else {
    dp[u] = all + mx1 + 1;
    tag[u]++;
  }
  if (n - size[u] == cnt - tag[u]) all += n - size[u];
  if (a[u]) res = max(res, all + mx1 + mx2 + 1);
}
int b[maxn];
bool check(int limit) {
  cnt = 0, res = 0;
  for (register int i = (1); i <= int(n); ++i)
    a[i] = b[i] >= limit, cnt += a[i], tag[i] = dp[i] = 0;
  if (cnt < k) return false;
  dfs(1, 0);
  return res >= k;
}
int main() {
  int l = 1000000, r = 1;
  n = read(), k = read();
  for (register int i = (1); i <= int(n); ++i)
    b[i] = read(), l = min(l, b[i]), r = max(r, b[i]);
  for (register int i = (1); i < int(n); ++i) {
    int a = read(), b = read();
    edge[a].push_back(b);
    edge[b].push_back(a);
  }
  pre(1, 0);
  int ans = 19260817;
  while (l <= r) {
    int mid = (l + r) >> 1;
    if (check(mid)) {
      ans = mid;
      l = mid + 1;
    } else {
      r = mid - 1;
    }
  }
  writeln(ans);
  return 0;
}
