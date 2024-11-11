#include <bits/stdc++.h>
using namespace std;
const int NR = 1005;
int read() {
  int x = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = (x << 3) + (x << 1) + (ch ^ 48);
    ch = getchar();
  }
  return x * f;
}
int n, m, a, b;
int h[NR][NR];
int num[NR][NR];
int mn[NR][NR];
struct Nd {
  int id, x;
};
Nd md(int id, int x) {
  Nd tmp;
  tmp.id = id, tmp.x = x;
  return tmp;
}
int all;
struct Mashiro {
  int x, y;
  long long ans;
  bool operator<(const Mashiro& A) const {
    return (ans == A.ans) ? ((y == A.y) ? x < A.x : y < A.y) : ans < A.ans;
  }
} p[NR * NR];
bool flag[NR][NR];
Mashiro Md(int x, int y, long long ans) {
  Mashiro tmp;
  tmp.x = x, tmp.y = y, tmp.ans = ans;
  return tmp;
}
long long sum[NR][NR];
long long getsum(int l1, int r1, int l2, int r2) {
  return sum[l2][r2] + sum[l1 - 1][r1 - 1] - sum[l2][r1 - 1] - sum[l1 - 1][r2];
}
int tot;
int posx[NR * NR], posy[NR * NR];
long long ans[NR * NR];
void add(int x, int y, long long num) {
  tot++;
  posx[tot] = x, posy[tot] = y, ans[tot] = num;
}
void print() {
  printf("%d\n", tot);
  for (int i = 1; i <= tot; i++)
    printf("%d %d %lld\n", posx[i], posy[i], ans[i]);
}
int main() {
  n = read(), m = read(), a = read(), b = read();
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) h[i][j] = read();
  for (int i = 1; i <= n; i++) {
    deque<Nd> q;
    for (int j = 1; j <= b; j++) {
      while (!q.empty() && h[i][j] < q.back().x) q.pop_back();
      q.push_back(md(j, h[i][j]));
    }
    num[i][1] = q.front().x;
    for (int j = b + 1; j <= m; j++) {
      while (!q.empty() && q.front().id <= j - b) q.pop_front();
      while (!q.empty() && h[i][j] < q.back().x) q.pop_back();
      q.push_back(md(j, h[i][j]));
      num[i][j - b + 1] = q.front().x;
    }
  }
  for (int i = 1; i <= m - b + 1; i++) {
    deque<Nd> q;
    for (int j = 1; j <= a; j++) {
      while (!q.empty() && num[j][i] < q.back().x) q.pop_back();
      q.push_back(md(j, num[j][i]));
    }
    mn[1][i] = q.front().x;
    for (int j = a + 1; j <= n; j++) {
      while (!q.empty() && q.front().id <= j - a) q.pop_front();
      while (!q.empty() && num[j][i] < q.back().x) q.pop_back();
      q.push_back(md(j, num[j][i]));
      mn[j - a + 1][i] = q.front().x;
    }
  }
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
      sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + h[i][j];
  for (int i = 1; i <= n - a + 1; i++)
    for (int j = 1; j <= m - b + 1; j++)
      p[++all] =
          Md(i, j, getsum(i, j, i + a - 1, j + b - 1) - 1ll * mn[i][j] * a * b);
  sort(p + 1, p + all + 1);
  for (int i = 1; i <= all; i++) {
    if (flag[p[i].x][p[i].y]) continue;
    add(p[i].x, p[i].y, p[i].ans);
    for (int j = max(1, p[i].x - a + 1); j <= min(n, p[i].x + a - 1); j++)
      for (int k = max(1, p[i].y - b + 1); k <= min(m, p[i].y + b - 1); k++)
        flag[j][k] = 1;
  }
  print();
  return 0;
}
