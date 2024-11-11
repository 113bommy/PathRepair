#include <bits/stdc++.h>
using namespace std;
struct Debug {
  int cnt = 0;
  bool on = false;
  char debug[10] = "debug";
  template <class T>
  Debug& operator<<(const T& v) {
    if (on && cnt++ == 0) cerr << "debug: ";
    if (on) cerr << v << ' ';
    return *this;
  }
  Debug& operator<<(ostream& (*pManip)(ostream&)) {
    if (on) cerr << (*pManip);
    cnt = 0;
    return *this;
  }
} debug;
const int MAXN = 1e6 + 20;
const int N = 22;
int lmask[1 << N] = {};
int rmask[1 << (40 - N)] = {};
int rs[1 << (40 - N)] = {};
int graph[40][40] = {};
int single[40] = {};
int n, m, x, y;
int main(int argc, char* argv[]) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  if (argc > 1 && !strcmp(argv[1], debug.debug)) debug.on = true;
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    cin >> x >> y;
    x--;
    y--;
    graph[x][y] = graph[y][x] = 1;
    single[x] = single[y] = 1;
  }
  int vis[40] = {};
  int valid = 1;
  int ngroups = 0;
  int nsingles = 0;
  function<void(int, int)> dfs = [&](int i, int c) {
    vis[i] = c;
    for (int j = 0; j < 40; j++) {
      if (j != i && graph[i][j]) {
        if (!vis[j])
          dfs(j, 3 - c);
        else if (vis[j] == vis[i])
          valid = 0;
      }
    }
  };
  for (int i = 0; i < n; i++) {
    if (!vis[i]) {
      dfs(i, 1);
      ngroups++;
    }
    if (!single[i]) nsingles++;
  }
  for (int mask = 0; mask < (1 << N); mask++) {
    lmask[mask] = 1;
    for (int i = 0; i < N && lmask[mask]; i++) {
      if (!((1 << i) & mask)) continue;
      for (int j = i + 1; j < N; j++) {
        if (!((1 << j) & mask)) continue;
        if (graph[i][j] == 1) {
          lmask[mask] = 0;
          break;
        }
      }
    }
  }
  debug << "123 " << endl;
  if (n <= N) {
    long long res = accumulate(lmask, lmask + (1 << n), 0LL);
    debug << res << endl;
    cout << (1LL << n) - 2 * res - ((1LL << ngroups)) +
                valid * (1LL << ngroups) +
                (1LL << (n == nsingles ? n : 1 + nsingles))
         << endl;
    return 0;
  }
  for (int mask = 0; mask < (1 << (n - N)); mask++) {
    rmask[mask] = 1;
    for (int i = 0; i < n - N && rmask[mask]; i++) {
      if (!((1 << i) & mask)) continue;
      for (int j = i + 1; j < n - N; j++) {
        if (!((1 << j) & mask)) continue;
        if (graph[i + N][j + N] == 1) {
          rmask[mask] = 0;
          break;
        }
      }
    }
  }
  debug << "123 " << endl;
  for (int mask = 0; mask < (1 << (n - N)); mask++) {
    for (int tmp = mask;; tmp = mask & (tmp - 1)) {
      rs[mask] += rmask[tmp];
      if (tmp <= 0) break;
    }
  }
  debug << "123 " << endl;
  long long res = 0;
  for (int mask = 0; mask < (1 << N); mask++) {
    if (!lmask[mask]) continue;
    int tmp = ((1 << N) - 1) & ~mask;
    int mask1 = (1 << (n - N)) - 1;
    for (int i = 0; i < N; i++) {
      if (!((1 << i) & mask)) continue;
      for (int j = N; j < n; j++) {
        if (i == j || !graph[i][j]) continue;
        mask1 -= (1 << (j - N));
      }
    }
    res += rs[mask1];
  }
  cout << (1LL << n) - 2 * res - ((1LL << ngroups)) + valid * (1LL << ngroups) +
              (1LL << (n == nsingles ? n : 1 + nsingles))
       << endl;
  return 0;
}
