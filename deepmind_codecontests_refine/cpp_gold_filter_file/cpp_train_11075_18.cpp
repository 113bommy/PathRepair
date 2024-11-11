#include <bits/stdc++.h>
using namespace std;
const int inf = ~0U >> 1;
const long long INF = ~0ULL >> 1;
template <class T>
inline void read(T &n) {
  char c;
  for (c = getchar(); !(c >= '0' && c <= '9'); c = getchar())
    ;
  n = c - '0';
  for (c = getchar(); c >= '0' && c <= '9'; c = getchar()) n = n * 10 + c - '0';
}
int Pow(int base, int n, int mo) {
  if (n == 0) return 1;
  if (n == 1) return base % mo;
  int tmp = Pow(base, n >> 1, mo);
  tmp = (long long)tmp * tmp % mo;
  if (n & 1) tmp = (long long)tmp * base % mo;
  return tmp;
}
int n, m, sx, sy;
char Dir[3];
long long s, ans = 1;
int dir, curx, cury;
set<int> s1, s2, s3, s4;
void add(int x, int y) {
  if (x == 1) s1.insert(y);
  if (x == n) s2.insert(y);
  if (y == 1) s3.insert(x);
  if (y == m) s4.insert(x);
  if (s1.size() + s2.size() + s3.size() + s4.size() == s) {
    printf("%lld\n", ans);
    exit(0);
  }
}
int main() {
  scanf("%d%d", &n, &m);
  scanf("%d%d%s", &sx, &sy, Dir);
  if (Dir[0] == 'U' && Dir[1] == 'L')
    dir = 0;
  else if (Dir[0] == 'U')
    dir = 1;
  else if (Dir[1] == 'L')
    dir = 2;
  else
    dir = 3;
  for (int i = (1); i <= (m); ++i) {
    if ((1 + i) % 2 == (sx + sy) % 2) s++;
    if ((n + i) % 2 == (sx + sy) % 2) s++;
  }
  for (int i = (1); i <= (n); ++i) {
    if ((1 + i) % 2 == (sx + sy) % 2) s++;
    if ((m + i) % 2 == (sx + sy) % 2) s++;
  }
  curx = sx, cury = sy;
  add(curx, cury);
  for (int _ = (1); _ <= (1000000); ++_) {
    if (dir == 0) {
      int step = min(curx - 1, cury - 1);
      curx -= step;
      cury -= step;
      ans += step;
      add(curx, cury);
      if (curx == 1 && cury == 1)
        dir = 3;
      else if (cury == 1)
        dir = 1;
      else if (curx == 1)
        dir = 2;
    } else if (dir == 1) {
      int step = min(curx - 1, m - cury);
      curx -= step;
      cury += step;
      ans += step;
      add(curx, cury);
      if (curx == 1 && cury == m)
        dir = 2;
      else if (cury == m)
        dir = 0;
      else if (curx == 1)
        dir = 3;
    } else if (dir == 2) {
      int step = min(n - curx, cury - 1);
      curx += step;
      cury -= step;
      ans += step;
      add(curx, cury);
      if (curx == n && cury == 1)
        dir = 1;
      else if (curx == n)
        dir = 0;
      else if (cury == 1)
        dir = 3;
    } else if (dir == 3) {
      int step = min(n - curx, m - cury);
      curx += step;
      cury += step;
      ans += step;
      add(curx, cury);
      if (curx == n && cury == m)
        dir = 0;
      else if (curx == n)
        dir = 1;
      else if (cury == m)
        dir = 2;
    }
  }
  puts("-1");
  return 0;
}
