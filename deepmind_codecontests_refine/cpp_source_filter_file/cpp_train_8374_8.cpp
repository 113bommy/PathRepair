#include <bits/stdc++.h>
using namespace std;
const int INF = 2e9;
const double eps = 1e-12;
template <typename T>
inline void read(T &x) {
  x = 0;
  int f = 1;
  char ch = getchar();
  while ((ch < '0' || ch > '9') && ch != '-') ch = getchar();
  if (ch == '-') {
    f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') x = x * 10 + ch - '0', ch = getchar();
  x *= f;
}
const int N = 100010, P = 1e9 + 7;
int n, k;
char s[10];
int fat[N << 1], val[N << 1];
bool fl = 1;
inline int father(int x) {
  if (fat[x] == x) return x;
  int tmp = father(fat[x]);
  val[x] ^= val[fat[x]];
  return fat[x] = tmp;
}
inline void Merge(int x, int y, int z) {
  int fx = father(x), fy = father(y);
  if (fx == fy) {
    if ((val[x] ^ val[y]) != z) fl = 0;
    return;
  }
  if (fx > fy) swap(fx, fy);
  fat[fx] = fy;
  val[fx] = val[x] ^ val[y] ^ z;
}
int main() {
  read(n);
  read(k);
  for (int i = 1; i <= n * 2; i++) fat[i] = i;
  for (int i = 1; i <= k; i++) {
    int x, y;
    read(x);
    read(y);
    scanf("%s", s + 1);
    if (x + y > n + 1) x = n + 1 - x, y = n + 1 - y;
    if (x > y) swap(x, y);
    Merge(y - x + 1, y + x + 1, s[1] == 'o');
  }
  int ans = fl;
  for (int i = 1; i <= n; i++)
    if (fat[i] == i) ans = ans * 2 % P;
  printf("%d\n", ans);
  return 0;
}
