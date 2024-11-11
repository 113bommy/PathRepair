#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const long long linf = 1e18;
const int N = 1000 + 10;
const double eps = 1e-10;
const int mo = 998244353;
int n, k, t;
vector<int> s[N], s2[N], del[N];
bool leaf[N];
long long f[N][20], g[N][20];
vector<int> v[N];
vector<int> u[N];
int a[N][20], b[N];
bool in[N][N];
int tot;
int de[N], de2[N];
bool vis[N];
void add(int x, int y) {
  if (in[x][y] || in[y][x]) return;
  in[x][y] = in[y][x] = 1;
  v[x].push_back(y);
  v[y].push_back(x);
  ++de[x], ++de[y];
}
void add2(int x, int y) {
  if (in[x][y] || in[y][x]) return;
  in[x][y] = in[y][x] = 1;
  v[x].push_back(y);
  v[y].push_back(x);
}
void dfs(int x, int fa) {
  for (auto &y : v[x]) {
    if (y != fa) {
      cout << x << " " << y << endl;
      dfs(y, x);
    }
  }
}
void dfs2(int x, int fa) {
  if (vis[fa]) de2[x]++;
  for (auto &y : v[x]) {
    if (y != fa) {
      if (vis[y]) de2[x]++;
      dfs2(y, x);
    }
  }
}
int main() {
  std::ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  for (int i = 1; i <= n; i++) leaf[i] = 1;
  for (int i = 1; i <= n; i++) {
    cin >> k;
    for (int j = 1; j <= k; j++) {
      cin >> t;
      s[i].push_back(t);
      u[t].push_back(i);
    }
    sort(s[i].begin(), s[i].end());
    int p = 0;
    long long top = 1;
    for (int l = 1; l <= 16; l++) {
      top = 1;
      for (int j = 1; j <= 64; j++) {
        if (j + (l - 1) * 64 == s[i][p]) {
          f[i][l] |= top;
          p++;
          if (p >= (int)s[i].size()) break;
        }
        top <<= 1;
      }
      if (p >= (int)s[i].size()) break;
    }
  }
  bool star = 1;
  for (int i = 1; i <= n; i++)
    if ((int)s[i].size() != n) {
      star = 0;
      break;
    }
  if (star) {
    for (int i = 1; i <= n - 1; i++) {
      cout << i << " " << n << endl;
    }
    return 0;
  }
  for (int i = 1; i <= n; i++)
    for (int j = i + 1; j <= n; j++) {
      int cnt = 0;
      int o = 0, o2 = 0;
      for (int l = 1; l <= 16; l++)
        if (f[i][l] & f[j][l]) {
          ++cnt;
          if (cnt == 1) {
            o = l;
          } else if (cnt == 2) {
            o2 = l;
          }
        }
      int cc = 0;
      long long top = 1;
      if (cnt == 1) {
        top = 1;
        for (int r = 0; r < 64; r++) {
          if (f[i][o] & f[j][o] & top) {
            cc++;
          }
          top <<= 1;
        }
      } else if (cnt == 2) {
        top = 1;
        for (int r = 0; r < 64; r++) {
          if (f[i][o] & f[j][o] & top) {
            cc++;
          }
          top <<= 1;
        }
        top = 1;
        for (int r = 0; r < 64; r++) {
          if (f[i][o2] & f[j][o2] & top) {
            cc++;
          }
          top <<= 1;
        }
      }
      if (cc == 2) {
        int p1 = 0, p2 = 0, x = 0, y = 0;
        while (1) {
          if (p1 == (int)s[i].size() || p2 == (int)s[j].size()) break;
          if (s[i][p1] == s[j][p2]) {
            if (x == 0)
              x = s[i][p1];
            else
              y = s[i][p1];
            p1++, p2++;
          } else if (s[i][p1] > s[j][p2])
            p2++;
          else if (s[i][p1] < s[j][p2])
            p1++;
        }
        add(x, y);
        leaf[x] = leaf[y] = 0;
      }
    }
  int xx = 0, yy = 0, cnt = 0;
  for (int i = 1; i <= n; i++) {
    if (!leaf[i]) {
      cnt++;
      if (cnt == 1)
        xx = i;
      else if (cnt == 2)
        yy = i;
    }
  }
  if (cnt == 2) {
    add(xx, yy);
    for (int i = 1; i <= n; i++)
      if ((int)s[i].size() != n) {
        bool success = 0;
        for (auto &y : s[i]) {
          if (y != xx && y != yy) {
            if (leaf[y]) {
              add(y, xx);
              leaf[y] = 0;
              success = 1;
            } else {
              break;
            }
          }
        }
        if (success) break;
      }
    for (int i = 1; i <= n; i++)
      if ((int)s[i].size() != n) {
        bool success = 0;
        for (auto &y : s[i]) {
          if (y != xx && y != yy) {
            if (leaf[y]) {
              add(y, yy);
              leaf[y] = 0;
              success = 1;
            } else {
              break;
            }
          }
        }
        if (success) break;
      }
    dfs(1, 0);
    return 0;
  }
  for (int i = 1; i <= n; i++)
    if (leaf[i]) {
      int mn = inf, p = 0;
      for (auto &y : u[i]) {
        if ((int)s[y].size() < mn) {
          mn = (int)s[y].size();
          p = y;
        }
      }
      for (auto &y : s[p])
        if (!leaf[y]) {
          vis[y] = 1;
        }
      for (int j = 1; j <= n; j++) de2[j] = 0;
      for (auto &y : s[p])
        if (!leaf[y]) {
          dfs2(y, 0);
          break;
        }
      bool success = 0;
      for (auto &y : s[p])
        if (!leaf[y]) {
          if (de2[y] > 1) {
            add2(i, y);
            success = 1;
            break;
          }
        }
      if (success == 0) {
        for (auto &y : s[p])
          if (!leaf[y]) {
            if (de[y] == 1) {
              add2(i, y);
              break;
            }
          }
      }
      for (auto &y : s[p])
        if (!leaf[y]) {
          vis[y] = 0;
        }
    }
  dfs(1, 0);
  return 0;
}
