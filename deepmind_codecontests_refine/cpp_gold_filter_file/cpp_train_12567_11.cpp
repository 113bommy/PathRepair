#include <bits/stdc++.h>
using namespace std;
const int N = 100;
int n, m, c[6][N + 9];
struct postion {
  int x, y;
  postion(int X = 0, int Y = 0) {
    x = X;
    y = Y;
  }
} b[N + 9];
void into() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= 4; ++i)
    for (int j = 1; j <= n; ++j) {
      int x;
      scanf("%d", &x);
      c[i][j] = x;
      if (!x) continue;
      if (i == 1 || i == 4) b[x] = postion(i, j);
    }
}
struct answer {
  int id, x, y;
  answer(int Id = 0, int X = 0, int Y = 0) {
    id = Id;
    x = X;
    y = Y;
  }
};
vector<answer> ans;
int tag[N + 9], vis[N + 9];
void Get() {
  int x;
  for (int i = 1; i < n; ++i) {
    x = c[2][i];
    if (!x) continue;
    if (vis[x]) continue;
    if (c[2][i + 1]) continue;
    vis[x] = 1;
    ans.push_back(answer(x, 2, i + 1));
    swap(c[2][i], c[2][i + 1]);
    return;
  }
  x = c[2][n];
  if (x && !vis[x] && !c[3][n]) {
    vis[x] = 1;
    ans.push_back(answer(x, 3, n));
    swap(c[2][n], c[3][n]);
    return;
  }
  for (int i = n; i > 1; --i) {
    x = c[3][i];
    if (!x) continue;
    if (vis[x]) continue;
    if (c[3][i - 1]) continue;
    vis[x] = 1;
    ans.push_back(answer(x, 3, i - 1));
    swap(c[3][i], c[3][i - 1]);
    return;
  }
  x = c[3][1];
  if (x && !vis[x] && !c[2][1]) {
    vis[x] = 1;
    ans.push_back(answer(x, 2, 1));
    swap(c[3][1], c[2][1]);
    return;
  }
}
void Get_ans() {
  for (int gg = 1; gg <= n << 1; ++gg) {
    for (int i = 1; i <= n; ++i) {
      int x = c[2][i];
      if (x && b[x].x == 1 && b[x].y == i) {
        ans.push_back(answer(x, 1, i));
        tag[x] = 1;
        c[2][i] = 0;
      }
      x = c[3][i];
      if (x && b[x].x == 4 && b[x].y == i) {
        ans.push_back(answer(x, 4, i));
        tag[x] = 1;
        c[3][i] = 0;
      }
    }
    int flag = 1;
    for (int i = 1; i <= m; ++i) flag &= tag[i];
    if (flag) break;
    flag = 0;
    for (int i = 1; i <= n; ++i) flag |= !c[2][i] || !c[3][i];
    for (int i = 1; i <= m; ++i) vis[i] = tag[i];
    for (int i = 1; i <= m; ++i) Get();
    if (!flag) {
      puts("-1");
      return;
    }
  }
  printf("%d\n", ans.size());
  for (auto x : ans) printf("%d %d %d\n", x.id, x.x, x.y);
}
void work() { Get_ans(); }
void outo() {}
int main() {
  int T = 1;
  for (; T--;) {
    into();
    work();
    outo();
  }
  return 0;
}
