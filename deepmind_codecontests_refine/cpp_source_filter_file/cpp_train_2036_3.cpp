#include <bits/stdc++.h>
using namespace std;
int M, ch;
long long ans, now;
long long pw[100020];
long long _pw[100020];
vector<int> g[100020];
vector<int> s[100020];
int level[100020];
int P[100020];
map<int, int> fmp;
long long mypow(long long A, long long B) {
  if (!B) return 1;
  long long D = mypow(A, B / 2);
  D *= D;
  D %= M;
  if (B % 2) D *= A;
  return D % M;
}
void calc(int p, int u, int lvl, int now, int dp) {
  fmp[(1LL * ((M - now) % M) * _pw[dp]) % M]++;
  for (int i = 0; i < g[u].size(); i++) {
    int to = g[u][i];
    if (to == p) continue;
    if (level[to] != -1) continue;
    calc(u, to, lvl, (1LL * now * 10 + s[u][i]) % M, dp + 1);
  }
}
void calc2(int p, int u, int lvl, int now, int dp) {
  ans += fmp[now % M];
  for (int i = 0; i < g[u].size(); i++) {
    int to = g[u][i];
    if (to == p) continue;
    if (level[to] != -1) continue;
    calc2(u, to, lvl, (1LL * s[u][i] * pw[dp] + now) % M, dp + 1);
  }
}
int dfs(int p, int v, int siz, int& res) {
  int sum = 1;
  for (int i = 0; i < g[v].size(); i++) {
    int to = g[v][i];
    if (to == p) continue;
    if (level[to] != -1) continue;
    sum += dfs(v, to, siz, res);
  }
  if (res == -1 && (sum * 2 >= siz || p == -1)) res = v;
  return sum;
}
void build(int v, int siz, int d, int p) {
  int center = -1;
  dfs(-1, v, siz, center);
  P[center] = p;
  level[center] = d;
  fmp.clear();
  calc(-1, center, d, 0, 0);
  calc2(-1, center, d, 0, 0);
  for (int i = 0; i < g[center].size(); i++) {
    int to = g[center][i];
    if (level[to] != -1) continue;
    fmp.clear();
    now = ans;
    ans = 0;
    calc(center, to, d, s[center][i], 1);
    calc2(center, to, d, s[center][i], 1);
    ans = now - ans;
  }
  for (int i = 0; i < g[center].size(); i++) {
    int to = g[center][i];
    if (level[to] != -1) continue;
    build(to, siz / 2, d + 1, center);
  }
}
int n, i, x, y, m;
int main() {
  cin >> n >> M;
  for (i = 2; i <= n; i++) {
    scanf("%d%d%d", &x, &y, &ch);
    ch %= M;
    g[x].push_back(y);
    s[x].push_back(ch);
    g[y].push_back(x);
    s[y].push_back(ch);
  }
  if (M == 1) {
    cout << 1LL * n * (n - 1) << endl;
    return 0;
  }
  for (i = 0; i <= n; i++) level[i] = -1;
  pw[0] = 1;
  _pw[0] = 1;
  pw[1] = 10 % M;
  for (i = 1; i < 10; i++) {
    if ((1LL * M * i + 1) % 10 == 0) {
      _pw[1] = (1LL * M * i + 1) / 10;
      break;
    }
  }
  for (i = 2; i <= n; i++)
    pw[i] = (1LL * pw[i - 1] * 10) % M, _pw[i] = (1LL * _pw[i] * _pw[1]) % M;
  build(0, n, 0, -1);
  cout << ans - n << endl;
}
