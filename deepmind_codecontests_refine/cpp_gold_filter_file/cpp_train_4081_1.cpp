#include <bits/stdc++.h>
using namespace std;
struct data {
  int to, head;
} e[750000 * 2];
stack<int> s;
vector<int> cir[750000];
int n, m, len, head[750000], dfn[750000], low[750000], cnt, num, p[750000],
    binv[750000], d[750000];
int ans, tot;
long long mm;
int mul(int a, int b) {
  int ans = 1;
  while (b) {
    if (b & 1) ans = 1ll * ans * a % 1000000007;
    a = 1ll * a * a % 1000000007;
    b >>= 1;
  }
  return ans;
}
void dfs(int lab, int fa) {
  dfn[lab] = low[lab] = ++num;
  s.push(lab);
  for (int i = head[lab]; i; i = e[i].head) {
    if (!dfn[e[i].to]) {
      dfs(e[i].to, lab);
      low[lab] = min(low[lab], low[e[i].to]);
      if (low[e[i].to] == dfn[lab]) {
        cnt++;
        int m1;
        do {
          m1 = s.top();
          s.pop();
          if (dfn[lab] == low[m1]) cir[cnt].push_back(m1);
        } while (m1 != e[i].to);
        cir[cnt].push_back(lab);
        m1 = cir[cnt].size();
        for (auto j : cir[cnt]) p[j] = (1ll * p[j] + binv[m1]) % 1000000007;
        tot = (1ll * tot + binv[m1]) % 1000000007;
      }
    }
    if (e[i].to != fa) low[lab] = min(low[lab], dfn[e[i].to]);
  }
}
void add(int u, int v) {
  e[++len].to = v;
  e[len].head = head[u];
  head[u] = len;
}
int main() {
  binv[0] = 1;
  binv[1] = mul(2, 1000000007 - 2);
  int u, v, m1, m2, m3;
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= m; i++) {
    scanf("%d%d", &u, &v);
    add(u, v);
    add(v, u);
    d[u]++;
    d[v]++;
  }
  m1 = max(n, 10);
  for (int i = 2; i <= m1; i++)
    binv[i] = 1ll * binv[1] * binv[i - 1] % 1000000007;
  ans = 1ll * n * (n + 1) % 1000000007 * binv[2] % 1000000007;
  ans = (ans + 1ll * m * binv[2]) % 1000000007;
  dfs(1, 0);
  for (int i = 1; i <= n; i++) {
    ans = (ans - 2ll * d[i] * binv[2]) % 1000000007;
    ans = (ans - 2ll * (m - d[i]) * binv[3]) % 1000000007;
    ans = (ans + 2ll * p[i]) % 1000000007;
    ans = (ans + 2ll * (tot - p[i]) * binv[1]) % 1000000007;
    for (int j = head[i]; j; j = e[j].head) {
      if (e[j].to < i) continue;
      ans = (ans + (1ll * d[i] + d[e[j].to] - 3 + m) * binv[4]) % 1000000007;
    }
  }
  ans = (1ll * ans + tot) % 1000000007;
  for (int i = 1; i <= cnt; i++) {
    m1 = 0;
    m2 = cir[i].size(), m3 = 0;
    for (auto j : cir[i]) {
      m1 = (1ll * m1 + p[j] - binv[m2]) % 1000000007;
      ans = (ans + 1ll * (p[j] - binv[m2]) * binv[m2] % 1000000007 * 2) %
            1000000007;
      m3 = (1ll * m3 + d[j] - 2) % 1000000007;
      ans = (ans - 2ll * binv[m2 + 1] * (d[j] - 2)) % 1000000007;
    }
    m1 = (1ll * m1 + binv[m2]) % 1000000007;
    ans = (ans + 1ll * (tot - m1) * binv[m2]) % 1000000007;
    ans = (ans - 2ll * m2 * binv[m2]) % 1000000007;
    ans = (ans - 2ll * (m - m3 - m2) * binv[m2 + 2]) % 1000000007;
  }
  m1 = (1ll * n * binv[1] - 1ll * m * binv[2] + 1ll * tot) % 1000000007;
  ans = ((ans - 1ll * m1 * m1) % 1000000007 + 1000000007) % 1000000007;
  printf("%d\n", ans);
}
