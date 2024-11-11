#include <bits/stdc++.h>
using namespace std;
int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }
int ppow(int a, int b, int mod) {
  a %= mod;
  int ans = 1 % mod;
  while (b) {
    if (b & 1) ans = (long long)ans * a % mod;
    a = (long long)a * a % mod;
    b >>= 1;
  }
  return ans;
}
int readdd() {
  int x = 0, f = 1;
  char c = getchar();
  while (!isdigit(c) && c != '-') c = getchar();
  if (c == '-') f = -1, c = getchar();
  while (isdigit(c)) x = x * 10 + c - '0', c = getchar();
  return f * x;
}
void printtt(int x) {
  if (x < 0) putchar('-'), x = -x;
  if (x >= 10) printtt(x / 10);
  putchar(x % 10 + '0');
}
bool addd(int a, int b) { return a > b; };
const int maxm = 5e5 + 5;
int l[maxm], r[maxm], tot;
vector<int> g[maxm];
int n;
void dfs(int x, int fa) {
  int len = g[x].size();
  for (int i = len - 1; i >= 0; i--) {
    int v = g[x][i];
    if (v == fa) continue;
    l[v] = ++tot;
  }
  r[x] = ++tot;
  for (int i = 0; i < len; i++) {
    int v = g[x][i];
    if (v == fa) continue;
    dfs(v, x);
  }
}
signed main() {
  scanf("%d", &n);
  for (int i = 1; i < n; i++) {
    int a, b;
    scanf("%d%d", &a, &b);
    g[a].push_back(b);
    g[b].push_back(a);
  }
  l[1] = ++tot;
  dfs(1, -1);
  for (int i = 1; i <= n; i++) {
    scanf("%d %d\n", l[i], r[i]);
  }
  return 0;
}
