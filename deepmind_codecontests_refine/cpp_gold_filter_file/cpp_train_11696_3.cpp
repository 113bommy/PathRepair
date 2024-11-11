#include <bits/stdc++.h>
using namespace std;
template <class T>
inline T min(T a, T b, T c) {
  return min(min(a, b), c);
}
template <class T>
inline T max(T a, T b, T c) {
  return max(max(a, b), c);
}
template <class T>
inline T min(T a, T b, T c, T d) {
  return min(min(a, b), min(c, d));
}
template <class T>
inline T max(T a, T b, T c, T d) {
  return max(min(a, b), max(c, d));
}
template <class T>
inline T Sqr(T a) {
  return a * a;
}
template <class T>
inline T Cub(T a) {
  return a * a * a;
}
inline void MUL(int &a, int b, int MOD) { a = (long long)a * b % MOD; }
template <class T>
inline T Abs(T a) {
  return a > 0 ? a : -a;
}
inline int PPow(int a, int b, int MOD) {
  int c = 1;
  while (b) {
    if (b & 1) MUL(c, a, MOD);
    MUL(a, a, MOD), b >>= 1;
  }
  return c;
}
char c[1510][1510];
pair<int, int> first[1510][1510];
int n, m;
int FF, Tot;
int dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
void dfs(int x, int y) {
  int xx = (x % n + n) % n, yy = (y % m + m) % m;
  if (first[xx][yy].first != 0X7fffffff) {
    cout << "Yes" << endl;
    exit(0);
  }
  first[xx][yy].first = x;
  first[xx][yy].second = y;
  FF++;
  if (FF > Tot) {
    cout << "No" << endl;
    exit(0);
  }
  for (int i = 0; i < 4; ++i) {
    int tx = x + dir[i][0], ty = y + dir[i][1];
    int ttx = (tx % n + n) % n, tty = (ty % m + m) % m;
    if (first[ttx][tty].first == tx && first[ttx][tty].second == ty) {
      continue;
    }
    if (c[ttx][tty] == '#') continue;
    dfs(tx, ty);
  }
}
int main() {
  cin >> n >> m;
  int posx, posy;
  FF = 0, Tot = n * m;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cin >> c[i][j];
      first[i][j].first = 0X7fffffff;
      if (c[i][j] == 'S') {
        posx = i;
        posy = j;
      }
    }
  }
  dfs(posx, posy);
  cout << "No" << endl;
  return 0;
}
