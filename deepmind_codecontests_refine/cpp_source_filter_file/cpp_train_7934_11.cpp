#include <bits/stdc++.h>
using namespace std;
const int inf = 1e9 + 5;
const long long Linf = 1e18 + 5;
template <class T>
inline void umax(T &a, T b) {
  if (a < b) a = b;
}
template <class T>
inline void umin(T &a, T b) {
  if (a > b) a = b;
}
template <class T>
inline T abs(T a) {
  return a > 0 ? a : -a;
}
template <class T>
inline T lcm(T a, T b) {
  return a / __gcd(a, b) * b;
}
inline int read() {
  int res = 0;
  int neg;
  while (true) {
    char ch = getchar();
    if (ch >= '0' && ch <= '9' || ch == '-') {
      if (ch == '-')
        neg = -1;
      else
        neg = 1, res = ch - '0';
      break;
    }
  }
  while (true) {
    char ch = getchar();
    if (ch >= '0' && ch <= '9')
      res *= 10, res += ch - '0';
    else
      break;
  }
  return res * neg;
}
const int MAXN = 10;
const int N = 8;
const int limit = 300000;
bool st[MAXN][MAXN];
struct data {
  int x, y, t;
  friend bool operator<(const data &a, const data &b) { return a.t < b.t; }
};
const int X[] = {1, 1, 1, 0, 0, -1, -1, -1};
const int Y[] = {1, -1, 0, 1, -1, 1, 0, -1};
bool used[MAXN][MAXN][limit + 1];
bool statue(int x, int y, int t) {
  if (x <= t) return false;
  return st[x - t][y];
}
int main() {
  for (int(i) = (1); (i) <= (N); (i)++)
    for (int(j) = (1); (j) <= (N); (j)++) {
      char ch;
      scanf(" %c", &ch);
      if (ch == 'S') st[i][j] = true;
    }
  priority_queue<data> q;
  q.push((data){8, 1, 0});
  while (!q.empty()) {
    int x = q.top().x;
    int y = q.top().y;
    int len = q.top().t;
    q.pop();
    if (used[x][y][len]) continue;
    if (x == 1 && y == N) {
      puts("WIN");
      return 0;
    }
    used[x][y][len] = true;
    if (len == limit) continue;
    for (int(i) = (0); (i) < (8); (i)++) {
      int nx = x + X[i];
      int ny = y + Y[i];
      if (nx >= 1 && nx <= N && ny >= 1 && ny <= N) {
        if (statue(nx, ny, len) == false && statue(nx, ny, len + 1) == false) {
          q.push((data){nx, ny, len + 1});
        }
      }
    }
  }
  puts("LOSE");
  return 0;
}
