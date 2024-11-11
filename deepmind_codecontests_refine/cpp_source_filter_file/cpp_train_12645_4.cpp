#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
const int maxm = 3e4 + 10;
const long long inf = 1e16 + 10;
const int mod = 1e9 + 7;
int getint() {
  char c;
  while ((c = getchar()) && !(c >= '0' && c <= '9') && c != '-')
    ;
  int ret = c - '0', sgn = 0;
  if (c == '-') sgn = 1, ret = 0;
  while ((c = getchar()) && c >= '0' && c <= '9') ret = ret * 10 + c - '0';
  if (sgn) ret = -ret;
  return ret;
}
int a[maxn], n;
int len[3];
struct node {
  int x, y;
  bool operator<(const node aa) const {
    if (x != aa.x) return x < aa.x;
    return y < aa.y;
  }
  node(int x1, int y1) { x = x1, y = y1; }
  node() {}
} ans[maxn], g[maxn];
int pos[3][maxn], p[3][maxn];
int main() {
  n = getint();
  len[1] = len[2] = 0;
  for (int i = 1; i <= n * 2; i++) {
    pos[1][i] = pos[2][i] = n + 1;
  }
  for (int i = 1; i <= n; i++) {
    a[i] = getint();
    p[a[i]][i] = len[a[i]];
    p[3 - a[i]][i] = len[3 - a[i]];
    pos[a[i]][++len[a[i]]] = i;
  }
  int tot = 0;
  p[1][0] = p[2][0] = 0;
  for (int t = 1; t <= n; t++) {
    int last = 0;
    int w1 = 0, w2 = 0;
    int flag = 1, x, y;
    while (1) {
      x = p[1][last + 1] + t;
      x = pos[1][x];
      y = p[2][last + 1] + t;
      y = pos[2][y];
      if (x > n && y > n) {
        flag = 0;
        break;
      }
      if (x < y) {
        last = x;
        w1++;
      } else
        last = y, w2++;
      if (last == n) {
        break;
      }
    }
    if (flag && ((last == x && w1 > w2) || (last == y && w2 > w1)))
      ans[++tot] = node(max(w1, w2), t);
  }
  sort(ans + 1, ans + tot + 1);
  int le = 0;
  ans[0].x = ans[1].x - 1;
  for (int i = 1; i <= tot; i++) {
    if (ans[i].x != ans[i - 1].x && ans[i].y != ans[i - 1].y) {
      g[++le] = ans[i];
    }
  }
  tot = le;
  cout << tot << endl;
  for (int i = 1; i <= tot; i++) {
    cout << g[i].x << " " << g[i].y << endl;
  }
  return 0;
}
