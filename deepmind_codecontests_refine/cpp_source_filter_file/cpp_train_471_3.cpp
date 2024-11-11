#include <bits/stdc++.h>
using namespace std;
template <typename T>
inline bool chkmin(T &a, const T &b) {
  return a > b ? a = b, 1 : 0;
}
template <typename T>
inline bool chkmax(T &a, const T &b) {
  return a < b ? a = b, 1 : 0;
}
const int oo = 0x3f3f3f3f;
const int maxn = 100000;
int n, m, K;
vector<int> ret[maxn + 5];
const int walk[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
bool vis[5][5];
bool g[5][5];
void dfs(int first, int second) {
  vis[first][second] = 1;
  for (int i = (0), i_end_ = (4); i < i_end_; ++i) {
    int u = first + walk[i][0], v = second + walk[i][1];
    if (u < 0 || u >= n || v < 0 || v >= m) continue;
    if (g[u][v] && !vis[u][v]) dfs(u, v);
  }
}
int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    scanf("%d%d%d", &n, &m, &K);
    if (n <= 4 && m <= 4) {
      bool find = 0;
      for (int i = (1), i_end_ = ((1 << (n * m))); i < i_end_; ++i) {
        for (int j = (0), j_end_ = (n); j < j_end_; ++j)
          for (int k = (0), k_end_ = (m); k < k_end_; ++k)
            g[j][k] = (i >> (j * m + k) & 1);
        int cnt = 0;
        memset(vis, 0, sizeof vis);
        for (int j = (0), j_end_ = (n); j < j_end_; ++j)
          for (int k = (0), k_end_ = (m); k < k_end_; ++k)
            if (g[j][k] && !vis[j][k]) dfs(j, k), ++cnt;
        if (cnt > 1) continue;
        int tot = 0;
        for (int j = (0), j_end_ = (n - 1); j < j_end_; ++j)
          for (int k = (0), k_end_ = (m - 1); k < k_end_; ++k) {
            int tmp = g[j][k] + g[j + 1][k] + g[j][k + 1] + g[j + 1][k + 1];
            if (tmp == 3)
              ++tot;
            else if (tmp == 4)
              tot += 4;
          }
        if (tot == K) {
          find = 1;
          for (int j = (0), j_end_ = (n); j < j_end_; ++j) {
            for (int k = (0), k_end_ = (m); k < k_end_; ++k) {
              if (g[j][k])
                putchar('*');
              else
                putchar('.');
            }
            putchar('\n');
          }
          putchar('\n');
          break;
        }
      }
      if (!find) puts("-1\n");
      continue;
    }
    if (K > ((n - 1) * (m - 1) << 2)) {
      puts("-1\n");
      continue;
    } else if (K == ((n - 1) * (m - 1) << 2)) {
      for (int i = (0), i_end_ = (n); i < i_end_; ++i) {
        for (int j = (0), j_end_ = (m); j < j_end_; ++j) putchar('*');
        putchar('\n');
      }
      putchar('\n');
      continue;
    } else if (K == ((n - 1) * (m - 1) << 2) - 8) {
      if (n == 3) {
        for (int i = (0), i_end_ = (n); i < i_end_; ++i) {
          for (int j = (0), j_end_ = (m); j < j_end_; ++j)
            putchar(!j ? '.' : '*');
          putchar('\n');
        }
      } else if (m == 3) {
        for (int i = (0), i_end_ = (n); i < i_end_; ++i) {
          for (int j = (0), j_end_ = (m); j < j_end_; ++j)
            putchar(!i ? '.' : '*');
          putchar('\n');
        }
      } else
        puts("NO");
      putchar('\n');
      continue;
    } else if (!K) {
      for (int i = (0), i_end_ = (n); i < i_end_; ++i) {
        for (int j = (0), j_end_ = (m); j < j_end_; ++j)
          putchar((!i && !j ? '*' : '.'));
        putchar('\n');
      }
      putchar('\n');
      continue;
    }
    bool rev = 0;
    if (n > m) swap(n, m), rev = 1;
    for (int i = (0), i_end_ = (n); i < i_end_; ++i) ret[i] = vector<int>(m, 0);
    bool failed = 0;
    --K;
    for (int i = (0), i_end_ = (m); i < i_end_; ++i) ret[0][i] = 1;
    int px = 0, py = m - 1;
    for (int i = (1), i_end_ = (n); i < i_end_; ++i)
      for (int j = (1), j_end_ = (m); j < j_end_; ++j) {
        if (K < 4) break;
        px = i, py = j;
        ret[i][j] = 1;
        K -= 4;
      }
    if (py == m - 1) ++px, py = 0;
    for (int i = (0), i_end_ = (px + 1); i < i_end_; ++i) ret[i][0] = 1;
    if (K == 1) {
      if (px != n - 1) {
        if (py >= 1)
          ret[px + 1][0] = 1;
        else
          ret[px][m - 1] = 1;
      } else if (py < m - 2)
        ret[n - 1][m - 1] = 1;
      else
        failed = 1;
    } else if (K == 2) {
      if (px != n - 1) {
        if (py >= 2)
          ret[px + 1][1] = 1;
        else
          ret[px][m - 2] = 1;
      } else if (py < m - 3)
        ret[px][m - 2] = 1;
      else
        failed = 1;
    } else if (K == 3) {
      if (px != n - 1) {
        if (py >= 3)
          ret[px + 1][0] = ret[px + 1][py - 1] = 1;
        else if (py == 2)
          ret[px + 1][1] = ret[px][m - 1] = 1;
        else if (py == 1)
          ret[px + 1][0] = ret[px][m - 2] = 1;
        else
          ret[px][m - 3] = ret[px][m - 1] = 1;
      } else if (py < m - 4)
        ret[px][m - 3] = ret[px][m - 1] = 1;
      else
        failed = 1;
    }
    if (rev) swap(n, m);
    if (failed) {
      puts("-1");
    } else {
      for (int i = (0), i_end_ = (n); i < i_end_; ++i) {
        for (int j = (0), j_end_ = (m); j < j_end_; ++j)
          putchar((rev ? ret[j][i] : ret[i][j]) ? '*' : '.');
        putchar('\n');
      }
    }
    putchar('\n');
  }
  return 0;
}
