#include <bits/stdc++.h>
using namespace std;
const long long INF64 = 1000000000000000000;
const long long BigPrime = 252097800623;
const long double LDINF = 1000000000000;
const long long Mmod = 998244353;
const long long INF = 1000000000;
const long long Mod = 1000000007;
const long double PI = acosl(-1.);
const long double Eps = 10e-10;
const long long Prime = 131;
const unsigned int N = 2005;
const unsigned int Len = 5005;
int n, m;
int d[N][N];
vector<int> g[N], gr[N];
int mt[N];
bool used[N];
int x[N], a[N], f[N];
bool dfs(int v) {
  if (used[v]) return false;
  used[v] = true;
  for (int i = 0; i < (int)g[v].size(); i++) {
    int to = g[v][i];
    if (mt[to] == -1 || dfs(mt[to])) {
      mt[to] = v;
      return true;
    }
  }
  return false;
}
void solve1() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      d[i][j] = (i == j) ? 0 : INF;
    }
  }
  for (int i = 1; i <= m; i++) {
    int a, b;
    scanf("%d%d", &a, &b);
    if (a == b) continue;
    d[a][b] = d[b][a] = 1;
  }
  for (int k = 1; k <= n; k++) {
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
      }
    }
  }
  int s, b, k, h;
  cin >> s >> b >> k >> h;
  for (int i = 1; i <= s; i++) {
    scanf("%d%d%d", &x[i], &a[i], &f[i]);
  }
  for (int i = 1; i <= b; i++) {
    int xx, dd;
    scanf("%d%d", &xx, &dd);
    mt[i + s] = -1;
    for (int j = 1; j <= s; j++) {
      int v = x[j];
      if (a[j] >= dd && f[j] >= d[v][xx]) {
        g[j].push_back(i + s);
      }
    }
  }
  for (int i = 1; i <= s; i++) {
    for (int j = 1; j <= s + b; j++) {
      used[j] = false;
    }
    dfs(i);
  }
  int cnt = 0;
  for (int i = s + 1; i <= s + b; i++) {
    if (mt[i] != -1) {
      ++cnt;
    }
  }
  cout << min(cnt * 1ll * k, s * 1ll * h) << endl;
}
int main() {
  int testcases = 1;
  for (int _ = 0; _ < testcases; ++_) {
    solve1();
  }
  return 0;
}
