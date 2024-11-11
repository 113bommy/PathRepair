#include <bits/stdc++.h>
using namespace std;
int n, m, K;
char maze[2010][2010];
int up[2010][2010], down[2010][2010];
struct Segtree {
  int key[2010 * 4], ans[2010 * 4];
  void add(deque<pair<int, int> > &que, int pos, int val) {
    while (!que.empty() && val < que.back().second) que.pop_back();
    que.push_back(make_pair(pos, val));
  }
  void remove(deque<pair<int, int> > &que, int pos) {
    while (!que.empty() && que.front().first <= pos) que.pop_front();
  }
  void cal(int l, int r, int step) {
    int mid = l + r >> 1;
    deque<pair<int, int> > qU, qD;
    int i = 0, j = 0;
    key[step] = 0;
    for (; j < m; j++) {
      int a, b;
      add(qU, j, mid - max(l - 1, up[mid][j]));
      if (mid < r)
        add(qD, j, b = (min(r + 1, down[mid + 1][j]) - mid - 1));
      else
        add(qD, j, b = 0);
      key[step] =
          max(key[step], min(j - i + 1, qU.front().second + qD.front().second));
      while (i < j && j - i + 1 > qU.front().second + qD.front().second) {
        remove(qU, i);
        remove(qD, i);
        i++;
        key[step] = max(key[step],
                        min(j - i + 1, qU.front().second + qD.front().second));
      }
    }
  }
  void build(int l, int r, int step) {
    cal(l, r, step);
    if (l == r) return;
    int mid = l + r >> 1;
    build(l, mid, step * 2);
    build(mid + 1, r, step * 2 + 1);
    ans[step] = max(key[step], max(ans[step * 2], ans[step * 2 + 1]));
  }
  void update(int l, int r, int pos, int step) {
    cal(l, r, step);
    if (l == r) return;
    int mid = l + r >> 1;
    if (pos <= mid)
      update(l, mid, pos, step * 2);
    else
      update(mid + 1, r, pos, step * 2 + 1);
    ans[step] = max(key[step], max(ans[step * 2], ans[step * 2 + 1]));
  }
} tree;
int main() {
  scanf("%d%d%d", &n, &m, &K);
  for (int i = 0; i < (n); i++) scanf("%s", maze[i]);
  for (int j = 0; j < (m); j++) up[0][j] = maze[0][j] == '.' ? -1 : 0;
  for (int i = 1; i < n; i++)
    for (int j = 0; j < (m); j++)
      up[i][j] = maze[i][j] == '.' ? up[i - 1][j] : i;
  for (int j = 0; j < (m); j++)
    down[n - 1][j] = maze[n - 1][j] == '.' ? n : n - 1;
  for (int i = n - 2; i >= 0; i--)
    for (int j = 0; j < (m); j++)
      down[i][j] = maze[i][j] == '.' ? down[i + 1][j] : i;
  tree.build(0, n - 1, 1);
  while (K--) {
    int x, y;
    scanf("%d%d", &x, &y);
    x--, y--;
    maze[x][y] = '#';
    up[0][y] = maze[0][y] == '.' ? -1 : 0;
    for (int i = 1; i < n; i++) up[i][y] = maze[i][y] == '.' ? up[i - 1][y] : i;
    down[n - 1][y] = maze[n - 1][y] == '.' ? n : n - 1;
    for (int i = n - 2; i >= 0; i--)
      down[i][y] = maze[i][y] == '.' ? down[i + 1][y] : i;
    tree.update(0, n - 1, x, 1);
    printf("%d\n", tree.ans[1]);
  }
  return 0;
}
