#include <bits/stdc++.h>
using namespace std;
struct node {
  int pre, y;
};
node a[2005 * 2005];
int len, pre[2005 * 2005];
int sign[2005 * 2005];
int stage[2005 * 2005];
int n, m;
void init() {
  len = 0;
  memset(pre, -1, sizeof(pre));
  memset(sign, 0, sizeof(sign));
  memset(stage, -1, sizeof(stage));
}
void addpage(int x, int y) {
  a[len].pre = pre[x];
  a[len].y = y;
  pre[x] = len++;
}
void fun(int i, int j, char p) {
  if (p == '#') sign[i * n + j] = 1;
  if (p == '>')
    if (j < m - 1) addpage(i * n + j + 1, i * n + j);
  if (p == '<')
    if (j > 0) addpage(i * n + j - 1, i * n + j);
  if (p == '^')
    if (i > 0) addpage((i - 1) * n + j, i * n + j);
  if (p == 'v')
    if (i < n - 1) addpage((i + 1) * n + j, i * n + j);
}
struct no {
  int b[2];
  void insert(int x) {
    if (x > b[0])
      b[1] = b[0], b[0] = x;
    else if (x > b[1])
      b[1] = x;
  }
};
no Max[2005 * 2005];
no ans;
int flag;
no dfs(int fa, int s) {
  if (stage[s] == fa) flag = 1;
  if (flag == 1) return ans;
  if (stage[s] != -1) return Max[s];
  stage[s] = fa;
  for (int i = pre[s]; i != -1; i = a[i].pre) {
    int y = a[i].y;
    dfs(fa, y);
    Max[s].insert(1 + Max[y].b[0]);
  }
  ans.insert(Max[s].b[0]);
  if (sign[s] == 1) ans.insert(Max[s].b[1]);
  return Max[s];
}
int main() {
  while (~scanf("%d%d", &n, &m)) {
    flag = 0;
    ans.b[0] = ans.b[1] = 0;
    init();
    char s[2005];
    for (int i = 0; i < (n); ++i) {
      scanf("%s", s);
      for (int j = 0; j < (m); ++j) fun(i, j, s[j]);
    }
    for (int i = 0; i < (n * m); ++i) Max[i].b[0] = Max[i].b[1] = 0;
    for (int i = 0; i < (n * m); ++i) {
      dfs(i, i);
      if (flag == 1) break;
    }
    if (flag == 1)
      puts("-1");
    else
      printf("%d\n", max(0, max(ans.b[0] * 2 - 1, ans.b[0] + ans.b[1])));
  }
  return 0;
}
