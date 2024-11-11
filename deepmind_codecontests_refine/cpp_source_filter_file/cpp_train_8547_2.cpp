#include <bits/stdc++.h>
using namespace std;
const double pi = acos(-1.0);
const double eps = 1e-8;
const int mxn = 300033;
const int mod = 1e9 + 7;
inline int read() {
  int x = 0, f = 1;
  char c = getchar();
  while (!isdigit(c)) f = c == '-' ? -1 : 1, c = getchar();
  while (isdigit(c)) x = x * 10 + c - '0', c = getchar();
  return x * f;
}
inline long long gcd(long long a, long long b) {
  return b == 0 ? a : gcd(b, a % b);
}
long long ksm(long long a, long long b, long long mod) {
  long long ans = 1;
  while (b) {
    if (b & 1) ans = (ans * a) % mod;
    a = (a * a) % mod;
    b >>= 1;
  }
  return ans;
}
long long inv2(long long a, long long mod) { return ksm(a, mod - 2, mod); }
void exgcd(long long a, long long b, long long &x, long long &y, long long &d) {
  if (!b) {
    d = a;
    x = 1;
    y = 0;
  } else {
    exgcd(b, a % b, y, x, d);
    y -= x * (a / b);
  }
}
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
int n, m;
vector<int> g[2][mxn];
int sum[mxn], id[2][mxn], que[mxn];
void topsort(int x) {
  int idx = 0;
  for (int i = 1; i <= n; ++i)
    if (id[x][i] == 0) que[++idx] = i;
  for (int i = 1; i <= idx; ++i) {
    int u = que[i];
    if (idx - i == 0)
      sum[u] += n - idx;
    else if (idx - i == 1) {
      int v = que[i + 1], flg = 0;
      for (int j = 0; j < g[x][v].size(); ++j)
        if (--id[x][g[x][v][j]] == 0) flg = 1;
      if (!flg) sum[u] += n - idx;
    }
    for (int j = 0; j < g[x][u].size(); ++j)
      if (--id[x][g[x][u][j]] == 0) que[++idx] = g[x][u][j];
  }
}
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  ;
  cin >> n >> m;
  for (int i = 1; i <= m; ++i) {
    int u, v;
    cin >> u >> v;
    g[0][u].push_back(v);
    g[1][v].push_back(u);
    id[0][v]++;
    id[1][u]++;
  }
  topsort(0);
  topsort(1);
  int res = 0;
  for (int i = 1; i <= n; ++i)
    if (sum[i] >= n - 2) res++;
  cout << res << endl;
  return 0;
}
