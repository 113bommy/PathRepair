#include <bits/stdc++.h>
using namespace std;
long long power(long long x, long long y, long long mod) {
  if (y < 0) return power(power(x, mod - 2, mod), -y, mod);
  long long res = 1;
  for (; y; y >>= 1, x = x * x % mod)
    if (y & 1) res = res * x % mod;
  return res;
}
const int ne = 300010, inf = 1 << 30;
const int MAX = 30000;
const int nn = 1100;
int mg[nn][nn], a[nn], v[MAX + 10];
int N, cnt;
vector<int> res[nn];
struct MAXFLOW {
  int S, T, es, flow, n;
  int g[ne], other[ne], next[ne], va[ne], vh[ne], di[ne], dis[ne], his[ne],
      pre[ne], v[ne];
  void insert(int x, int y, int z) {
    other[++es] = y;
    next[es] = g[x];
    g[x] = es;
    va[es] = z;
    other[++es] = x;
    next[es] = g[y];
    g[y] = es;
    va[es] = 0;
  }
  void init(int _S, int _T, int _n) {
    es = 1;
    flow = 0;
    S = _S;
    T = _T;
    n = _n;
    for (int i = 0; i <= _n + 10; ++i) g[i] = vh[i] = v[i] = dis[i] = 0;
  }
  void sap() {
    int aug = inf;
    for (int i = 0; i <= n; ++i) di[i] = g[i];
    vh[0] = n;
    int i = S;
    while (dis[S] < n) {
      his[i] = aug;
      int flag = 0;
      for (int p = di[i]; p; p = next[p]) {
        int j = other[p];
        if (va[p] > 0 && dis[i] == dis[j] + 1) {
          flag = 1;
          di[i] = p;
          pre[j] = p;
          aug = min(aug, va[p]);
          i = j;
          if (i == T) {
            flow += aug;
            while (i != S) {
              va[pre[i]] -= aug;
              va[pre[i] ^ 1] += aug;
              i = other[pre[i] ^ 1];
            }
            aug = inf;
          }
          break;
        }
      }
      if (flag) continue;
      int min = n - 1, j1;
      for (int p = g[i]; p; p = next[p])
        if (va[p] > 0 && dis[other[p]] < min) min = dis[other[p]], j1 = p;
      if (--vh[dis[i]] == 0) break;
      dis[i] = min + 1;
      ++vh[dis[i]];
      di[i] = j1;
      if (i != S) {
        i = other[pre[i] ^ 1];
        aug = his[i];
      }
    }
  }
  void bfs(int s) {
    queue<int> Q;
    Q.push(s);
    v[s] = 1;
    while (Q.size()) {
      int x = Q.front();
      Q.pop();
      for (int p = g[x]; p; p = next[p]) {
        int j = other[p];
        if (va[p] <= 0 || v[j]) continue;
        v[j] = 1;
        Q.push(j);
      }
    }
  }
  void work() {
    for (int i = 1; i <= N; ++i)
      if (a[i] % 2 == 1) {
        for (int p = g[i]; p; p = next[p]) {
          int j = other[p];
          if (va[p] == 0) {
            mg[i][j] = mg[j][i] = 1;
          }
        }
      }
  }
} T;
void init() {
  v[1] = 1;
  for (int i = 2; i <= MAX; ++i) {
    if (v[i]) continue;
    for (int j = i; j <= MAX / i; ++j) v[i * j] = 1;
  }
}
void dfs(int x, vector<int> &a) {
  if (v[x]) return;
  v[x] = 1;
  a.push_back(x);
  for (int i = 1; i <= N; ++i)
    if (mg[x][i]) {
      mg[x][i] = mg[i][x] = 0;
      dfs(i, a);
      return;
    }
}
int main() {
  init();
  scanf("%d", &N);
  T.init(0, N + 1, N + 2);
  for (int i = 1; i <= N; ++i) {
    scanf("%d", &a[i]);
  }
  int n0 = 0, n1 = 0;
  for (int i = 1; i <= N; ++i) {
    if (a[i] % 2 == 0) {
      n0++;
      T.insert(i, N + 1, 2);
    } else {
      n1++;
      T.insert(0, i, 2);
    }
    for (int j = 1; j <= N; ++j) {
      if (!v[a[i] + a[j]]) {
        if (a[i] % 2 == 1) T.insert(i, j, 1);
      }
    }
  }
  T.sap();
  if (n0 != n1 || T.flow != 2 * n0) {
    return puts("Impossible"), 0;
  }
  T.work();
  memset(v, 0, sizeof(v));
  int cnt = 0;
  for (int i = 1; i <= N; ++i) {
    dfs(i, res[cnt]);
    if (res[cnt].size()) cnt++;
  }
  printf("%d\n", cnt);
  for (int i = 0; i < cnt; ++i) {
    printf("%d", res[i].size());
    for (int j = 0; j < res[i].size(); ++j) {
      printf(" %d", a[res[i][j]]);
    }
    puts("");
  }
}
