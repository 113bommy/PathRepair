#include <bits/stdc++.h>
using namespace std;
const int size = 2100;
const long long inf = 0x3f3f3f3f3f3f;
int nex[2][4] = {0, 1, 0, -1, 1, 0, -1, 0};
long long ans;
vector<long long> sx, sy, px, py;
int cal(char* ch) {
  switch (ch[0]) {
    case 'R':
      return 0;
    case 'D':
      return 1;
    case 'L':
      return 2;
    case 'U':
      return 3;
  }
}
void add(int x, int y) {
  sx.push_back(x);
  sx.push_back(x + 1);
  sy.push_back(y);
  sy.push_back(y + 1);
}
int mark[size][size];
void dfs(int x, int y) {
  if (x < 0 || x >= sx.size() || y < 0 || y >= sy.size() || mark[x][y]) return;
  mark[x][y] = 2;
  int i;
  for (i = 0; i < 4; i++) dfs(x + nex[0][i], y + nex[1][i]);
}
void debug() {
  int i, j;
  for (i = 0; i < sx.size(); i++) {
    for (j = 0; j < sy.size(); j++) printf("%d", mark[i][j]);
    puts("");
  }
  puts("");
}
int locate(vector<long long> p, int va) {
  return lower_bound(p.begin(), p.end(), va) - p.begin();
}
int main() {
  int n, i, j, a, x = 0, y = 0, k;
  char ch[3];
  scanf("%d", &n);
  sx.push_back(-inf);
  sy.push_back(-inf);
  add(x, y);
  for (i = 0; i < n; i++) {
    scanf("%s%d", ch, &a);
    int dir = cal(ch);
    x += nex[0][dir] * a;
    y += nex[1][dir] * a;
    add(x, y);
  }
  px = sx, py = sy;
  sort(sx.begin(), sx.end()), sort(sy.begin(), sy.end());
  sx.erase(unique(sx.begin(), sx.end()), sx.end()),
      sy.erase(unique(sy.begin(), sy.end()), sy.end());
  for (i = 3; i < px.size(); i += 2) {
    int x1 = locate(sx, px[i - 2]), x2 = locate(sx, px[i]);
    int y1 = locate(sy, py[i - 2]), y2 = locate(sy, py[i]);
    if (x1 > x2) swap(x1, x2);
    if (y1 > y2) swap(y1, y2);
    for (j = x1; j <= x2; j++)
      for (k = y1; k <= y2; k++) mark[j][k] = 1;
  }
  dfs(0, 0);
  for (i = 0; i + 1 < sx.size(); i++)
    for (j = 0; j + 1 < sy.size(); j++) {
      if (mark[i][j] != 2) ans += (sx[i + 1] - sx[i]) * (sy[j + 1] - sy[j]);
    }
  printf("%I64d\n", ans);
  return 0;
}
