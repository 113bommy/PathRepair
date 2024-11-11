#include <bits/stdc++.h>
using namespace std;
const int maxn = 200010;
const int maxm = 2 * maxn;
int n, m, u, v, k;
struct edge {
  int v, next;
} e[maxm];
int h[maxn], num;
long long f[maxn][6];
long long sum[maxn][6];
long long ans = 0;
void build(int u, int v) {
  num++;
  e[num].v = v;
  e[num].next = h[u];
  h[u] = num;
}
void add(int x, int v) {
  long long temp[6], s[6];
  for (int i = 0; i <= k; i++) temp[i] = f[x][i];
  for (int i = 0; i < k; i++) ans += f[x][i] * f[v][k];
  for (int i = 0; i < k; i++)
    for (int j = 1; j < k; j++) ans -= f[x][i] * f[v][j];
  for (int i = 0; i < k; i++) {
    memset(s, 0, sizeof(s));
    s[0] = temp[k - 1];
    ans += f[v][i] * temp[0];
    ans += f[v][i] * temp[k];
    for (int j = 1; j < k; j++) s[j] += temp[j - 1];
    temp[k] += temp[0];
    for (int j = 0; j < k; j++) temp[j] = s[j];
  }
}
void dfs(int x, int fa) {
  f[x][0]++;
  for (int i = h[x]; i; i = e[i].next) {
    if (e[i].v == fa) continue;
    dfs(e[i].v, x);
    add(x, e[i].v);
    f[x][0] += f[e[i].v][k - 1];
    f[x][k] += f[e[i].v][0];
    f[x][k] += f[e[i].v][k];
    for (int j = 1; j < k; j++) f[x][j] += f[e[i].v][j - 1];
  }
}
int main() {
  cin >> n >> k;
  for (int i = 1; i < n; i++) {
    cin >> u >> v;
    build(u, v);
    build(v, u);
  }
  dfs(1, 0);
  cout << ans << endl;
  return 0;
}
