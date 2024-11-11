#include <bits/stdc++.h>
using namespace std;
template <typename T>
void read(T& x) {
  x = 0;
  char ch = getchar();
  long long f = 1;
  while (!isdigit(ch)) {
    if (ch == '-') f *= -1;
    ch = getchar();
  }
  while (isdigit(ch)) {
    x = x * 10 + ch - 48;
    ch = getchar();
  }
  x *= f;
}
template <typename T, typename... Args>
void read(T& first, Args&... args) {
  read(first);
  read(args...);
}
template <typename T>
void write(T arg) {
  T x = arg;
  if (x < 0) {
    putchar('-');
    x = -x;
  }
  if (x > 9) {
    write(x / 10);
  }
  putchar(x % 10 + '0');
}
template <typename T, typename... Ts>
void write(T arg, Ts... args) {
  write(arg);
  if (sizeof...(args) != 0) {
    putchar(' ');
    write(args...);
  }
}
using namespace std;
long long gcd(long long a, long long b) { return b == 0 ? a : gcd(b, a % b); }
long long lcm(long long a, long long b) { return a / gcd(a, b) * b; }
const int N = 3005, mod = 998244353;
int n, w[N][N], tot;
struct E {
  int u, v, w;
  bool operator<(const E& no) const { return w < no.w; }
} edge[1505 * 1505];
vector<int> E[N];
int fa[N << 1], siz[N << 1], egs[N << 1], mark[N << 1], cnt;
int findroot(int x) {
  if (fa[x] == x) return x;
  return fa[x] = findroot(fa[x]);
}
void check(int x) {
  egs[x]++;
  int p = siz[x] * (siz[x] - 1) / 2;
  if (egs[x] == p) mark[x] = 1;
}
void merge(int x, int y) {
  int fax = findroot(x);
  int fay = findroot(y);
  if (fax != fay) {
    ++cnt;
    E[cnt].push_back(fax), E[fax].push_back(cnt);
    E[cnt].push_back(fay), E[fay].push_back(cnt);
    fa[fax] = fa[fay] = fa[cnt] = cnt;
    siz[cnt] = siz[fax] + siz[fay];
    egs[cnt] = egs[fax] + egs[fay];
    check(cnt);
  } else
    check(fax);
}
int l[N], r[N], times;
vector<int> ve[N];
void dfs(int u, int pa) {
  if (u <= n) {
    l[u] = r[u] = ++times;
    return;
  }
  l[u] = 0x3f3f3f3f;
  for (auto v : E[u]) {
    if (v != pa) {
      dfs(v, u);
      l[u] = min(l[u], l[v]);
    }
  }
  r[u] = times;
  if (mark[u]) ve[r[u]].push_back(l[u]);
}
long long dp[N][N];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++) {
      cin >> w[i][j];
      if (i < j) edge[++tot].u = i, edge[tot].v = j, edge[tot].w = w[i][j];
    }
  for (int i = 1; i <= n; i++) fa[i] = i, siz[i] = 1, ve[i].push_back(i);
  cnt = n;
  sort(edge + 1, edge + 1 + tot);
  for (int i = 1; i <= tot; i++) merge(edge[i].u, edge[i].v);
  dfs(cnt, cnt);
  dp[0][0] = 1;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      for (auto v : ve[i]) dp[i][j] = (dp[i][j] + dp[v - 1][j - 1]) % mod;
    }
  }
  for (int i = 1; i <= n; i++) cout << dp[n][i] << ' ';
  cout << endl;
}
