#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const double eps = 1e-6;
const double PI = acos(-1.0);
inline long long read() {
  char ch;
  long long x = 0;
  bool f = true;
  for (ch = getchar(); !isdigit(ch); ch = getchar())
    if (ch == '-') f ^= f;
  for (; isdigit(ch); ch = getchar()) x = (x << 3) + (x << 1) + ch - 48;
  return f ? x : -x;
}
const int N = 1010;
char ch[N][N];
int h[N * N], e[2 * N * N], ne[2 * N * N], idx;
int ans[N][N];
void add(int a, int b) {
  e[++idx] = b;
  ne[idx] = h[a];
  h[a] = idx;
}
void dfs(int u, int res) {
  if (ans[u / N][u % N]) return;
  int t = (res == 1 ? 4 : 1);
  ans[u / N][u % N] = res;
  for (int i = h[u]; i; i = ne[i]) {
    int j = e[i];
    dfs(j, t);
  }
}
int z(int x, int y) { return x * N + y; }
int dx[] = {-1, 0, 1, 0}, dy[] = {0, -1, 0, 1};
void solve() {
  int n = read(), m = read();
  for (int i = 1; i <= n; i++) cin >> (ch[i] + 1);
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
      if (ch[i][j] == 'X') {
        vector<int> vs;
        for (int k = 0; k < 4; k++) {
          if (ch[i + dx[k]][j + dy[k]] != '.') continue;
          vs.push_back(z(i + dx[k], j + dy[k]));
        }
        if (vs.size() % 2 == 1) return printf("NO\n"), void(0);
        for (int k = 0; k < vs.size(); k += 2)
          add(vs[k], vs[k + 1]), add(vs[k + 1], vs[k]);
      }
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) {
      if (ch[i][j] == 'X') continue;
      if (ans[i][j]) continue;
      dfs(z(i, j), 1);
    }
  cout << "YES\n";
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (ch[i][j] == 'X')
        for (int k = 0; k < 4; k++)
          if (ch[i + dx[k]][j + dy[k]] == '.')
            ans[i][j] += ans[i + dx[k]][j + dy[k]];
      cout << ans[i][j] << " ";
    }
    cout << "\n";
  }
}
int main() {
  int T = 1;
  while (T--) solve();
  return 0;
}
