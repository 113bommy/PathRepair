#include <bits/stdc++.h>
using namespace std;
void fre() {
  freopen("c://test//input.in", "r", stdin);
  freopen("c://test//output.out", "w", stdout);
}
template <class T>
inline void gmax(T &a, T b) {
  if (b > a) a = b;
}
template <class T>
inline void gmin(T &a, T b) {
  if (b < a) a = b;
}
const int N = 1010, M = 0, Z = 1e9 + 7, ms63 = 1061109567;
const int dy[4] = {-1, 0, 0, 1}, dx[4] = {0, -1, 1, 0};
int n, m;
char s[N][N];
struct BFS {
  queue<pair<int, int> > q;
  int f[N][N];
  int ans[3];
  void init() {
    memset(f, 63, sizeof(f));
    memset(ans, 63, sizeof(ans));
  }
  void inq(int y, int x, int step) {
    if (y < 0 || y == n || x < 0 || x == m) return;
    if (s[y][x] == '#') return;
    if (step >= f[y][x]) return;
    f[y][x] = step;
    if (isdigit(s[y][x])) {
      gmin(ans[s[y][x] - '1'], f[y][x]);
    }
    q.push(make_pair(y, x));
  }
  void bfs() {
    while (!q.empty()) {
      int y = q.front().first;
      int x = q.front().second;
      q.pop();
      for (int i = 0; i < 4; i++) {
        inq(y + dy[i], x + dx[i], f[y][x] + 1);
      }
    }
  }
} a[3];
int main() {
  while (~scanf("%d%d", &n, &m)) {
    for (int i = 0; i < 3; i++) a[i].init();
    for (int i = 0; i < n; i++) {
      scanf("%s", s[i]);
      for (int j = 0; s[i][j]; j++)
        if (isdigit(s[i][j])) {
          a[s[i][j] - '1'].inq(i, j, 0);
        }
    }
    for (int i = 0; i < 3; i++) a[i].bfs();
    int ans = ms63;
    for (int i = 0; i < 3; i++) {
      gmin(ans, a[i].ans[0] + a[i].ans[1] + a[i].ans[2] - 2);
    }
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        long long tmp = -2;
        for (int k = 0; k < 3; k++) tmp += a[k].f[i][j];
        if (tmp < ans) ans = tmp;
      }
    }
    if (ans == ms63) ans = -1;
    printf("%d\n", ans);
  }
  return 0;
}
