#include <bits/stdc++.h>
using namespace std;
const long long mod = 1000000007;
long long qpow(long long a, long long n) {
  long long re = 1;
  while (n) {
    if (n & 1) re = (re * a) % mod;
    n >>= 1;
    a = (a * a) % mod;
  }
  return re % mod;
}
struct edge {
  long long to, next, w;
} edge[200005];
long long head[100005], cnt, top, num, ho[100005];
bool vis[100005];
void add1(long long u, long long v) {
  edge[++cnt].to = v;
  edge[cnt].next = head[u];
  head[u] = cnt;
}
long long dfs(long long x) {
  vis[x] = true;
  num++;
  for (long long i = head[x]; ~i; i = edge[i].next) {
    if (!vis[edge[i].to]) dfs(edge[i].to);
  }
  return num;
}
long long n, k;
int main() {
  cin >> n >> k;
  long long u, v, x;
  for (long long i = 1; i <= n; i++) head[i] = -1;
  for (long long i = 1; i < n; i++) {
    cin >> u >> v >> x;
    if (x == 0) add1(u, v), add1(v, u);
  }
  for (long long i = 1; i <= n; i++) {
    if (!vis[i]) num = 0, ho[++top] = dfs(i);
  }
  long long ans = qpow(n, k);
  for (long long i = 1; i <= top; i++) {
    long long temp = qpow(ho[i], k);
    ans = (ans - temp + mod) % mod;
  }
  cout << ans << endl;
  return 0;
}
