#include <bits/stdc++.h>
using namespace std;
const int N = 500005;
int cnt, u, v, n, head[N], f[N], ans;
const int mod = 998244353;
const int inv_2 = 499122177;
struct node {
  int to, next;
} num[N << 1];
int ksm(int x, int y) {
  int res = 1;
  while (y) {
    if (y & 1) res = (long long)res * x % mod;
    x = (long long)x * x % mod;
    y >>= 1;
  }
  return res;
}
void up(int &x, int y) {
  x = x - mod + y;
  x = (x < 0) ? x + mod : x;
}
void add(int x, int y) {
  num[++cnt].to = y;
  num[cnt].next = head[x];
  head[x] = cnt;
}
void dfs(int x, int fa) {
  f[x] = 1;
  for (int i = head[x]; i; i = num[i].next)
    if (num[i].to != fa) {
      dfs(num[i].to, x);
      f[x] = (long long)f[x] * (1 + f[num[i].to]) % mod * inv_2 % mod;
    }
  f[x] = ((long long)1 - f[x] + mod) % mod;
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i < n; i++) scanf("%d%d", &u, &v), add(u, v), add(v, u);
  dfs(1, -1);
  for (int i = 1; i <= n; i++) up(ans, f[i]);
  printf("%d\n", (long long)ans * ksm(2, n) % mod);
  return 0;
}
