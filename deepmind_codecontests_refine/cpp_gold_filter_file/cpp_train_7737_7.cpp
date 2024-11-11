#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 7, M = 2e5 + 7;
int n, m, k, t;
long long p[N][N], a[N][N], f[N][N];
int fen[N][N];
void add(int x, int y2, int v) {
  for (; x <= n; x += x & -x)
    for (int y = y2; y <= m; y += y & -y) fen[x][y] += v;
}
int getFen(int x, int y2) {
  long long res = 0;
  for (; x > 0; x -= x & -x)
    for (int y = y2; y > 0; y -= y & -y) res += fen[x][y];
  return res;
}
int get(int x1, int y1, int x2, int y2) {
  return getFen(x2, y2) - getFen(x2, y1 - 1) - getFen(x1 - 1, y2) +
         getFen(x1 - 1, y1 - 1);
}
long long getPrefix(int x1, int y1, int x2, int y2) {
  return p[x2][y2] - p[x2][y1 - 1] - p[x1 - 1][y2] + p[x1 - 1][y1 - 1];
}
struct Node {
  int x, y;
  long long w;
  Node() {}
  Node(int _x, int _y, long long _w) : x(_x), y(_y), w(_w) {}
};
vector<Node> nod;
bool operator<(const Node &a, const Node &b) {
  if (a.w == b.w) {
    if (a.x == b.x) return a.y < b.y;
    return a.x < b.x;
  }
  return a.w < b.w;
}
signed main() {
  int h, w;
  scanf("%d%d%d%d", &n, &m, &h, &w);
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      scanf("%lld", &a[i][j]);
      p[i][j] = a[i][j] + p[i][j - 1] + p[i - 1][j] - p[i - 1][j - 1];
    }
  }
  for (int j = 1; j <= m; j++) {
    deque<int> d;
    for (int i = 1; i <= n; i++) {
      while (!d.empty() && d.front() <= i - h) d.pop_front();
      while (!d.empty() && a[d.back()][j] >= a[i][j]) d.pop_back();
      d.push_back(i), f[i][j] = a[d.front()][j];
    }
    while (!d.empty()) d.pop_back();
  }
  for (int i = h; i <= n; i++) {
    deque<int> d;
    for (int j = 1; j <= m; j++) {
      while (!d.empty() && d.front() <= j - w) d.pop_front();
      while (!d.empty() && f[i][d.back()] >= f[i][j]) d.pop_back();
      d.push_back(j), a[i][j] = f[i][d.front()];
      if (j >= w)
        nod.push_back(Node(i - h + 1, j - w + 1,
                           getPrefix(i - h + 1, j - w + 1, i, j) -
                               a[i][j] * (h * 1LL) * (w * 1LL)));
    }
    while (!d.empty()) d.pop_back();
  }
  sort(nod.begin(), nod.end());
  vector<int> ans;
  for (int x, y, i = 0; i < (int)nod.size(); i++) {
    x = nod[i].x, y = nod[i].y;
    if (get(x, y, x + h - 1, y + w - 1)) continue;
    for (int xo = 1; xo <= h; xo++)
      for (int yo = 1; yo <= w; yo++) add(x + xo - 1, y + yo - 1, 1);
    ans.push_back(i);
  }
  printf("%d\n", (int)ans.size());
  for (int j, i = 0; i < (int)ans.size(); i++) {
    j = ans[i];
    printf("%d %d %lld\n", nod[j].x, nod[j].y, nod[j].w);
  }
  return 0;
}
