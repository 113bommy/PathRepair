#include <bits/stdc++.h>
using namespace std;
const int N = 100005, M = 100005, m1 = 998244353, m2 = 1e9 + 9, base = 1e6 + 3;
inline void gmin(int &x, int y) {
  if (x > y) x = y;
}
inline void gmax(int &x, int y) {
  if (x < y) x = y;
}
struct node {
  int to, next;
} p[N << 2];
int n, tot, head[N], du[N];
set<unsigned long long> s;
map<int, unsigned long long> dp[N];
void add(int x, int y) {
  p[++tot] = (node){y, head[x]};
  head[x] = tot;
  p[++tot] = (node){x, head[y]};
  head[y] = tot;
}
unsigned long long f1(unsigned long long x) {
  return x * x * x * 109457 + x * 201712589 + 103751981;
}
unsigned long long dfs(int x, int f) {
  if (dp[x].count(f)) return dp[x][f];
  unsigned long long &ans = dp[x][f];
  ans = 1;
  for (int i = head[x]; i; i = p[i].next) {
    int y = p[i].to;
    if (y == f) continue;
    ans *= dfs(y, x);
  }
  unsigned long long t = f1(du[x]);
  ans -= t;
  ans ^= du[x];
  return ans;
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i < n; i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    add(x, y);
    du[x]++;
    du[y]++;
  }
  for (int i = 1; i <= n; i++)
    if (du[i] < 4) s.insert(dfs(i, 0));
  printf("%d\n", (int)s.size());
  return 0;
}
