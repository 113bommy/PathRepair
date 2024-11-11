#include <bits/stdc++.h>
using namespace std;
template <typename T, typename U>
inline void smin(T &a, U b) {
  if (a > b) a = b;
}
template <typename T, typename U>
inline void smax(T &a, U b) {
  if (a < b) a = b;
}
template <typename T>
inline void getint(T &first) {
  char c, sg = 0;
  while (c = getchar(), (c > '9' || c < '0') && c != '-')
    ;
  for ((c == '-' ? sg = 1, c = getchar() : 0), first = 0; c >= '0' && c <= '9';
       c = getchar())
    first = (first << 1) + (first << 3) + c - '0';
  if (sg) first = -first;
}
template <typename T>
inline void print(T first) {
  if (first < 0) {
    putchar('-');
    return print(-first);
  }
  if (first < 10) {
    putchar('0' + first);
    return;
  }
  print(first / 10);
  putchar(first % 10 + '0');
}
int power(int a, int b, int m, int ans = 1) {
  for (; b; b >>= 1, a = 1LL * a * a % m)
    if (b & 1) ans = 1LL * ans * a % m;
  return ans;
}
vector<pair<int, int> > adj[100100];
int pp[100100], rpp[100100];
int qf, qb, q[100100], sz[100100], fa[100100], vst[100100], val[100100][2];
int nn, n, M, runs;
long long ans;
int find_root(int u) {
  qf = qb = 0;
  q[qb++] = u;
  fa[u] = 0;
  while (qf < qb) {
    u = q[qf++];
    for (int i = adj[u].size(); i--;) {
      int v = adj[u][i].first;
      if (v == fa[u] || vst[v]) continue;
      fa[v] = u;
      q[qb++] = v;
    }
  }
  nn = qb;
  for (int i = nn; i--;) {
    sz[u = q[i]] = 1;
    int mx = 0;
    for (int j = adj[u].size(); j--;) {
      int v = adj[u][j].first;
      if (v == fa[u] || vst[v]) continue;
      smax(mx, sz[v]);
      sz[u] += sz[v];
    }
    if (mx * 2 <= nn && sz[u] * 2 >= nn) return u;
  }
}
map<int, int> cnt[2];
map<int, int> flag[2];
void add(int id, int val) {
  if (!flag[id].count(val) || flag[id][val] != runs) {
    flag[id][val] = runs;
    cnt[id][val] = 1;
  } else
    cnt[id][val]++;
}
int calc(int id, int val) {
  if (!flag[id].count(val) || flag[id][val] != runs) return 0;
  return cnt[id][val];
}
int root, D[100100];
void dfs(int u, int fa = -1, int dp = 0) {
  D[u] = dp;
  if (u != root) {
    if (!val[u][0]) ans++;
    if (!val[u][1]) ans++;
    int v0 = (long long)rpp[dp] * (M - val[u][1]) % M;
    ans += calc(0, v0);
    ans += calc(1, val[u][0]);
    q[qb++] = u;
  }
  for (int i = adj[u].size(); i--;) {
    int v = adj[u][i].first;
    if (v == fa || vst[v]) continue;
    if (u == root) qf = qb = 0;
    val[v][0] = ((long long)pp[dp] * adj[u][i].second + val[u][0]) % M;
    val[v][1] = (10LL * val[u][1] + adj[u][i].second) % M;
    dfs(v, u, dp + 1);
    if (u == root) {
      for (int j = qb; j--;) {
        add(0, val[q[j]][0]);
        int v1 = (long long)rpp[D[q[j]]] * (M - val[q[j]][1]) % M;
        add(1, v1);
      }
    }
  }
}
void solve(int u) {
  u = find_root(u);
  vst[u] = 1;
  runs++;
  val[u][0] = val[u][1] = 0;
  dfs(root = u);
  for (int i = adj[u].size(); i--;) {
    int v = adj[u][i].first;
    if (!vst[v]) solve(v);
  }
}
int ex_gcd(int a, int b, int &first, int &second) {
  if (b == 0) return first = 1, second = 0, a;
  int g = ex_gcd(b, a % b, second, first);
  second -= a / b * first;
  return g;
}
int main() {
  cin >> n >> M;
  if (M == 1) {
    cout << (long long)n * (n - 1) / 2 << endl;
    return 0;
  }
  pp[0] = rpp[0] = 1;
  int first, second;
  ex_gcd(10, M, first, second);
  first %= M;
  if (first < 0) first += M;
  for (int i = 1; i <= n; i++) {
    pp[i] = 10LL * pp[i - 1] % M;
    rpp[i] = (long long)first * rpp[i - 1] % M;
  }
  int u, v, w;
  for (int i = 1; i < n; i++) {
    scanf("%d %d %d", &u, &v, &w);
    adj[u].push_back(pair<int, int>(v, w));
    adj[v].push_back(pair<int, int>(u, w));
  }
  solve(0);
  cout << ans << endl;
  return 0;
}
