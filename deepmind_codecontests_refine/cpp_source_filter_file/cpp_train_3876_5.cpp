#include <bits/stdc++.h>
const int MAXN = 3e5 + 10;
const double eps = 1e-8;
using namespace std;
struct edge {
  int t, v;
  edge *next;
} e[MAXN << 1], *h[MAXN], *o = e;
void add(int x, int y, int vul) {
  o->t = y;
  o->v = vul;
  o->next = h[x];
  h[x] = o++;
}
long long read() {
  long long x = 0, f = 1;
  char ch = getchar();
  while (!isdigit(ch)) {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (isdigit(ch)) x = x * 10 + ch - '0', ch = getchar();
  return x * f;
}
int n, m, q;
int dirx[] = {-1, 1, 0, 0};
int diry[] = {0, 0, -1, 1};
int del[2000005], pos[MAXN];
int a[305][305];
vector<pair<int, int> > q1[2000006], q2[2000005];
int f[MAXN];
int find1(int x) {
  if (x == f[x])
    return x;
  else
    return f[x] = find1(f[x]);
}
void cal_add(int x) {
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
      a[i][j] = 0, f[(i - 1) * m + j] = (i - 1) * m + j;
  for (int i = 0; i < q1[x].size(); i++) {
    int x1 = (q1[x][i].first - 1) / m + 1;
    int x2 = q1[x][i].first - (x1 - 1) * m;
    a[x1][x2] = 1;
    int num = 1;
    for (int j = 0; j < 4; j++) {
      int xx = x1 + dirx[j];
      int yy = x2 + diry[j];
      if (xx >= 1 && xx <= n && yy >= 1 && yy <= m && a[xx][yy] == 1) {
        int y = (xx - 1) * m + yy;
        int t1 = find1(q1[x][i].first);
        int t2 = find1(y);
        if (t1 == t2) continue;
        f[t1] = t2;
        num--;
      }
    }
    del[q1[x][i].second] += num;
  }
}
void cal_del(int x) {
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
      a[i][j] = 0, f[(i - 1) * m + j] = (i - 1) * m + j;
  for (int i = 0; i < q2[x].size(); i++) {
    int x1 = (q2[x][i].first - 1) / m + 1;
    int x2 = q2[x][i].first - (x1 - 1) * m;
    a[x1][x2] = 1;
    int num = 1;
    for (int j = 0; j < 4; j++) {
      int xx = x1 + dirx[j];
      int yy = x2 + diry[j];
      if (xx >= 1 && xx <= n && yy >= 1 && yy <= m && a[xx][yy] == 1) {
        int y = (xx - 1) * m + yy;
        int t1 = find1(q2[x][i].first);
        int t2 = find1(y);
        if (t1 == t2) continue;
        f[t1] = t2;
        num--;
      }
    }
    del[q2[x][i].second] -= num;
  }
}
int main() {
  n = read();
  m = read();
  q = read();
  int num = 0;
  int x, y, c;
  for (int i = 1; i <= q; i++) {
    x = read();
    y = read();
    c = read();
    pos[i] = (x - 1) * m + y;
    num = c;
    if (a[x][y] == c) continue;
    q1[c].push_back(make_pair(pos[i], i));
    q2[a[x][y]].push_back(make_pair(pos[i], i));
    a[x][y] = c;
  }
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
      q2[a[i][j]].push_back(make_pair((i - 1) * m + j, q + 1));
  for (int i = 0; i <= num; i++) reverse(q2[i].begin(), q2[i].end());
  for (int i = 0; i <= num; i++) cal_add(i);
  for (int i = 0; i <= num; i++) cal_del(i);
  int ans = 1;
  for (int i = 1; i <= q; i++) ans += del[i], printf("%d\n", ans);
  return 0;
}
