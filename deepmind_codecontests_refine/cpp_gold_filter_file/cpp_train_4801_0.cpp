#include <bits/stdc++.h>
using namespace std;
map<int, int> s;
struct point {
  int x, y;
  point() {}
  point(int x, int y) : x(x), y(y) {}
};
queue<point> q;
int value[700][700], c[320][320], py[320][320];
vector<point> v[2 * 320 * 320];
point d[2 * 320 * 320];
int dx, dy;
int cmp(const point &a, const point &b) {
  return value[320 + a.x - dx][320 + a.y - dy] <
         value[320 + b.x - dx][320 + b.y - dy];
}
void lemon() {
  int color = 0;
  int n, m;
  scanf("%d%d", &n, &m);
  for (int i = (1); i <= (n); i++)
    for (int j = (1); j <= (m); j++) {
      scanf("%d", &c[i][j]);
      if (c[i][j]) {
        if (!s.count(c[i][j])) s[c[i][j]] = ++color;
        c[i][j] = s[c[i][j]];
      }
    }
  for (int i = (1); i <= (n); i++)
    for (int j = (1); j <= (m); j++) {
      scanf("%d", &py[i][j]);
      if (py[i][j] > 0) {
        if (!s.count(py[i][j])) s[py[i][j]] = ++color;
        py[i][j] = s[py[i][j]];
      }
    }
  int cx = 320, cy = 320, k = 1;
  value[cx][cy] = 1;
  cx--;
  for (int it = (1); it <= (310); it++) {
    for (int _ = (1); _ <= (it * 2); _++) value[cx][cy] = ++k, cy++;
    cy--;
    cx++;
    for (int _ = (1); _ <= (it * 2); _++) value[cx][cy] = ++k, cx++;
    cx--;
    cy--;
    for (int _ = (1); _ <= (it * 2); _++) value[cx][cy] = ++k, cy--;
    cy++;
    cx--;
    for (int _ = (1); _ <= (it * 2); _++) value[cx][cy] = ++k, cx--;
  }
  long long final = 0, s = 0;
  scanf("%d%d", &dx, &dy);
  q.push(point(dx, dy));
  color = c[dx][dy];
  for (int i = (1); i <= (n); i++)
    for (int j = (1); j <= (m); j++) v[c[i][j]].push_back(point(i, j));
  while (!q.empty()) {
    dx = q.front().x;
    dy = q.front().y;
    q.pop();
    if (!color || color == py[dx][dy]) continue;
    s += v[color].size();
    final += s;
    int cn = 0;
    for (typeof((v[color]).begin()) iter = (v[color]).begin();
         iter != (v[color]).end(); iter++)
      if (py[iter->x][iter->y] != -1 && (iter->x != dx || iter->y != dy)) {
        cn++;
        d[cn] = *iter;
      }
    sort(d + 1, d + cn + 1, cmp);
    v[color].clear();
    for (int i = (1); i <= (cn); i++) q.push(d[i]);
    color = py[dx][dy];
  }
  cout << final << endl;
}
int main() {
  ios::sync_with_stdio(true);
  lemon();
  return 0;
}
