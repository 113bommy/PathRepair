#include <bits/stdc++.h>
using namespace std;
template <class T>
inline void input(T &x) {
  register char c = getchar();
  x = 0;
  int neg = 0;
  for (; ((c < 48 || c > 57) && c != '-'); c = getchar())
    ;
  if (c == '-') {
    neg = 1;
    c = getchar();
  }
  for (; c > 47 && c < 58; c = getchar()) {
    x = (x << 1) + (x << 3) + c - 48;
  }
  if (neg) x = -x;
}
inline long long bigmod(long long p, long long e, long long M) {
  long long ret = 1;
  for (; e > 0; e >>= 1) {
    if (e & 1) ret = (ret * p) % M;
    p = (p * p) % M;
  }
  return ret;
}
template <class T>
inline T gcd(T a, T b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
template <class T>
inline T modinverse(T a, T M) {
  return bigmod(a, M - 2, M);
}
const int N = 1007;
bool vis[N][N];
int color[N][N];
int SZ[N * N];
int r, c;
int dir[][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
char g[N][N];
bool check(int x, int y) { return x >= 0 && x < r && y >= 0 && y < c; }
void dfs(int x, int y, int col) {
  if (vis[x][y]) return;
  vis[x][y] = 1;
  color[x][y] = col;
  SZ[col]++;
  for (int i = 0; i < 4; i++) {
    int xp = x + dir[i][0], yp = y + dir[i][1];
    if (check(xp, yp) && g[xp][yp] == '.') dfs(xp, yp, col);
  }
}
int main() {
  input(r), input(c);
  for (int i = 0; i < r; i++) scanf("%s", g[i]);
  int col = 0;
  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      if (vis[i][j] == 0 && g[i][j] == '.') {
        dfs(i, j, col++);
      }
    }
  }
  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      if (g[i][j] == '*') {
        set<int> comp;
        for (int k = 0; k < 4; k++) {
          int xp = i + dir[k][0], yp = j + dir[k][1];
          if (check(xp, yp) && g[xp][yp] == '.') comp.insert(color[xp][yp]);
        }
        int sum = 1;
        for (auto v : comp) sum += SZ[v];
        g[i][j] = sum % 10 + '0';
      }
    }
  }
  for (int i = 0; i < r; i++) printf("%s\n", g[i]);
  return 0;
}
