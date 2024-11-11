#include <bits/stdc++.h>
using namespace std;
const int maxn = 3e5 + 5;
const long long mod = 1e9 + 7;
int lft[maxn], rht[maxn], n, q, cnt;
long long deep[maxn], BIT[2][maxn];
vector<int> graph[maxn];
void dfs(int cur, int d) {
  lft[cur] = ++cnt;
  deep[cur] = d;
  for (int i = 0; i < graph[cur].size(); ++i) {
    int v = graph[cur][i];
    dfs(v, d + 1);
  }
  rht[cur] = cnt;
}
int lowbit(int k) { return (k & -k); }
void add(int pos, long long val, int idx) {
  while (pos <= n) {
    BIT[idx][pos] += val;
    BIT[idx][pos] %= mod;
    pos += lowbit(pos);
  }
}
long long sum(int pos, int idx) {
  long long ret = 0;
  while (pos > 0) {
    ret += BIT[idx][pos];
    pos -= lowbit(pos);
    ret %= mod;
  }
  return ret;
}
int main() {
  scanf("%d", &n);
  int pi;
  for (int i = 2; i <= n; ++i) {
    scanf("%d", &pi);
    graph[pi].push_back(i);
  }
  dfs(1, 1);
  scanf("%d", &q);
  for (int i = 0; i < q; ++i) {
    int type;
    scanf("%d", &type);
    if (type == 1) {
      int v;
      long long x, k;
      scanf("%d%lld%lld", &v, &x, &k);
      long long val = (x + deep[v] * k) % mod;
      add(lft[v], val, 0);
      add(rht[v] + 1, -val, 0);
      add(lft[v], k, 1);
      add(rht[v] + 1, -k, 1);
    } else {
      int v;
      scanf("%d", &v);
      int pos = lft[v];
      long long part1 = sum(pos, 0);
      long long part2 = sum(pos, 1);
      part2 = part2 * deep[v] % mod;
      long long ans = ((part1 - part2) % mod + mod) % mod;
      printf("%lld\n", ans);
    }
  }
  return 0;
}
