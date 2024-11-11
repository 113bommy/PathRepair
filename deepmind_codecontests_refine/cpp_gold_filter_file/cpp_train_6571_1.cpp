#include <bits/stdc++.h>
using namespace std;
template <typename T>
void chkmax(T &x, T y) {
  x = x > y ? x : y;
}
template <typename T>
void chkmin(T &x, T y) {
  x = x > y ? y : x;
}
template <typename T>
void upd(T &x, T y, T mod) {
  x = x + y > mod ? x + y - mod : x + y;
}
template <typename T>
void sub(T &x, T y, T mod) {
  x = x - y < 0 ? x - y + mod : x - y;
}
template <typename T>
void multi(T &x, T y, T mod) {
  x = 1ll * x * y % mod;
}
const int INF = (1ll << 30);
template <typename T>
void read(T &x) {
  x = 0;
  bool f = 1;
  char ch;
  do {
    ch = getchar();
    if (ch == '-') f = 0;
  } while (ch > '9' || ch < '0');
  do {
    x = x * 10 + ch - '0';
    ch = getchar();
  } while (ch >= '0' && ch <= '9');
  x = f ? x : -x;
}
template <typename T>
void write(T x) {
  if (x < 0) x = ~x + 1, putchar('-');
  if (x > 9) write(x / 10);
  putchar(x % 10 + '0');
}
struct Node {
  int x, y;
  bool operator<(const Node &rhs) const {
    return x < rhs.x || (x == rhs.x && y < rhs.y);
  }
} a[4];
vector<Node> sol;
inline void work() {
  int nowx = a[0].x, nowy = a[0].y;
  sol.push_back((Node){nowx, nowy});
  while (nowx < a[1].x) sol.push_back((Node){++nowx, nowy});
  while (nowy < a[1].y) sol.push_back((Node){nowx, ++nowy});
  while (nowy > a[1].y) sol.push_back((Node){nowx, --nowy});
  if (min(a[0].y, a[1].y) <= a[2].y && a[2].y <= max(a[0].y, a[1].y))
    nowx = a[1].x, nowy = a[2].y;
  if (a[2].y < min(a[1].y, a[0].y)) nowx = a[1].x, nowy = min(a[0].y, a[1].y);
  if (a[2].y > max(a[1].y, a[0].y)) nowx = a[1].x, nowy = max(a[0].y, a[1].y);
  while (nowx < a[2].x) sol.push_back((Node){++nowx, nowy});
  while (nowy < a[2].y) sol.push_back((Node){nowx, ++nowy});
  while (nowy > a[2].y) sol.push_back((Node){nowx, --nowy});
}
int main() {
  for (int i = 0; i < 3; i++) read(a[i].x), read(a[i].y);
  sort(a, a + 3);
  work();
  printf("%d\n", (int)sol.size());
  for (int i = 0; i < sol.size(); i++) printf("%d %d\n", sol[i].x, sol[i].y);
  return 0;
}
