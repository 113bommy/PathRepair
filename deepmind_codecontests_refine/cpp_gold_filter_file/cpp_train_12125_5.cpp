#include <bits/stdc++.h>
using namespace std;
const double PI = acos(-1);
const double eps = 1e-9;
const int inf = 2000000000;
const long long infLL = 9000000000000000000;
inline bool checkBit(long long n, int i) { return n & (1LL << i); }
inline long long setBit(long long n, int i) {
  return n | (1LL << i);
  ;
}
inline long long resetBit(long long n, int i) { return n & (~(1LL << i)); }
int dx[] = {0, 0, +1, -1};
int dy[] = {+1, -1, 0, 0};
inline bool EQ(double a, double b) { return fabs(a - b) < 1e-9; }
inline bool isLeapYear(long long year) {
  return (year % 400 == 0) || (year % 4 == 0 && year % 100 != 0);
}
inline void normal(long long &a) {
  a %= 1000000007;
  (a < 0) && (a += 1000000007);
}
inline long long modMul(long long a, long long b) {
  a %= 1000000007, b %= 1000000007;
  normal(a), normal(b);
  return (a * b) % 1000000007;
}
inline long long modAdd(long long a, long long b) {
  a %= 1000000007, b %= 1000000007;
  normal(a), normal(b);
  return (a + b) % 1000000007;
}
inline long long modSub(long long a, long long b) {
  a %= 1000000007, b %= 1000000007;
  normal(a), normal(b);
  a -= b;
  normal(a);
  return a;
}
inline long long modPow(long long b, long long p) {
  long long r = 1;
  while (p) {
    if (p & 1) r = modMul(r, b);
    b = modMul(b, b);
    p >>= 1;
  }
  return r;
}
inline long long modInverse(long long a) { return modPow(a, 1000000007 - 2); }
inline long long modDiv(long long a, long long b) {
  return modMul(a, modInverse(b));
}
const int magicn = 350;
const int magicm = 10;
const int maxn = 101000;
const int maxm = 13;
int n, m, vis[maxn][maxm];
char grid[maxn][maxm];
pair<int, int> nxt[maxn][maxm];
pair<int, int> getnxt(int x, int y) {
  if (grid[x][y] == '^') return pair<int, int>(x - 1, y);
  if (grid[x][y] == '<') return pair<int, int>(x, y - 1);
  return pair<int, int>(x, y + 1);
}
bool opposite(int ux, int uy, int vx, int vy) {
  return ((grid[ux][uy] == '<' && grid[vx][vy] == '>') ||
          (grid[vx][vy] == '<' && grid[ux][uy] == '>'));
}
void dfs(int ux, int uy, int x, int y) {
  ;
  if (vis[ux][uy]) return;
  vis[ux][uy] = true;
  int lowx = x * magicn, highx = min((x + 1) * magicn, n) - 1;
  int lowy = y * magicm, highy = min((y + 1) * magicm, m) - 1;
  pair<int, int> temp = getnxt(ux, uy);
  int vx = temp.first, vy = temp.second;
  if (vx < lowx || vx > highx || vy < lowy || vy > highy) {
    nxt[ux][uy] = pair<int, int>(vx, vy);
    return;
  }
  if (opposite(ux, uy, vx, vy)) {
    vis[vx][vy] = true;
    nxt[ux][uy] = nxt[vx][vy] = pair<int, int>(-1, -1);
    return;
  }
  dfs(vx, vy, x, y);
  nxt[ux][uy] = nxt[vx][vy];
  ;
}
void calc(int x, int y) {
  for (int i = magicn * x; i < min(n, magicn * (x + 1)); ++i)
    for (int j = magicm * y; j < min(m, magicm * (y + 1)); ++j)
      vis[i][j] = false;
  for (int i = magicn * x; i < min(n, magicn * (x + 1)); ++i)
    for (int j = magicm * y; j < min(m, magicm * (y + 1)); ++j)
      if (!vis[i][j]) dfs(i, j, x, y);
}
bool valid(int x, int y) { return x >= 0 && y >= 0 && x < n && y < m; }
void solve(int &x, int &y) {
  while (valid(x, y)) {
    pair<int, int> temp = nxt[x][y];
    x = temp.first, y = temp.second;
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  int q;
  cin >> n >> m >> q;
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j) cin >> grid[i][j];
  for (int i = 0; i < magicn; ++i)
    for (int j = 0; j < magicm; ++j) {
      if (i * magicn < n && j * magicm < m) calc(i, j);
    }
  while (q--) {
    char d;
    cin >> d;
    if (d == 'A') {
      int x, y;
      cin >> x >> y;
      --x;
      --y;
      solve(x, y);
      if (x == -1 && y == -1)
        cout << x << " " << y << '\n';
      else
        cout << x + 1 << " " << y + 1 << '\n';
    } else {
      int x, y;
      char lol;
      cin >> x >> y >> lol;
      --x;
      --y;
      grid[x][y] = lol;
      calc(x / magicn, y / magicm);
    }
  }
  return 0;
}
