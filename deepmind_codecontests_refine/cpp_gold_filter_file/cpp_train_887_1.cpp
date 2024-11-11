#include <bits/stdc++.h>
using namespace std;
const int N = 1005;
int read() {
  int f = 1, g = 0;
  char ch = getchar();
  for (; !isdigit(ch); ch = getchar())
    if (ch == '-') f = -1;
  for (; isdigit(ch); ch = getchar()) g = g * 10 + ch - '0';
  return f * g;
}
int n, m, ans;
struct vec {
  int x, y;
} a[10], b[N];
vec operator+(vec a, vec b) { return (vec){a.x + b.x, a.y + b.y}; }
vec operator-(vec a, vec b) { return (vec){a.x - b.x, a.y - b.y}; }
long long operator^(vec a, vec b) {
  return (long long)a.x * b.y - (long long)a.y * b.x;
}
long long operator&(vec a, vec b) {
  return (long long)a.x * b.x + (long long)a.y * b.y;
}
bool on(vec a, vec b, vec c) {
  if ((c - b) ^ (b - a)) return false;
  return ((c - b) & (b - a)) >= 0;
}
vector<int> g[10][N];
int ha[N], h[10], cur[10];
bool work(int dep, int num) {
  if (dep > num) return true;
  int x = cur[dep];
  for (int i = 1; i <= n; i++)
    if ((!h[i]) && (g[i][x].size() <= n)) {
      h[i] = 1;
      int cnt = num, fl = 0;
      for (auto y : g[i][x])
        if (!ha[y]) {
          ha[y] = 1;
          cur[++cnt] = y;
          if (cnt > n) break;
        }
      if (cnt <= n) fl = work(dep + 1, cnt);
      while (cnt > num) ha[cur[cnt--]] = 0;
      h[i] = 0;
      if (fl) return true;
    }
  return false;
}
int main() {
  n = read();
  m = read();
  for (int i = 1; i <= n; i++) a[i].x = read(), a[i].y = read();
  for (int i = 1; i <= m; i++) b[i].x = read(), b[i].y = read();
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
      for (int k = 1; k <= m; k++)
        if ((j != k) && on(a[i], b[k], b[j])) {
          g[i][j].push_back(k);
          if (g[i][j].size() > n) break;
        }
  for (int i = 1; i <= m; i++) {
    cur[1] = i;
    ha[i] = 1;
    if (work(1, 1)) ans++;
    ha[i] = 0;
  }
  printf("%d\n", ans);
  return 0;
}
