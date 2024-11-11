#include <bits/stdc++.h>
using namespace std;
const int N = 100000;
int n, m;
struct side {
  int y, next;
} e[N * 2 + 9];
int lin[N + 9], cs;
void Ins(int x, int y) {
  e[++cs].y = y;
  e[cs].next = lin[x];
  lin[x] = cs;
}
void into() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= m; ++i) {
    int x, y;
    scanf("%d%d", &x, &y);
    Ins(x, y);
  }
}
int vis[2][N + 9];
vector<int> ans;
void Get_ans() {
  for (int i = 1; i <= n; ++i) {
    if (vis[0][i]) continue;
    vis[0][i] = vis[1][i] = 1;
    for (int j = lin[i]; j; j = e[j].next) vis[0][e[j].y] = 1;
  }
  for (int i = n; i >= 1; --i) {
    if (!vis[1][i]) continue;
    for (int j = lin[i]; j; j = e[j].next) vis[1][e[j].y] = 0;
  }
  for (int i = 1; i <= n; ++i)
    if (vis[1][i]) ans.push_back(i);
}
void work() { Get_ans(); }
void outo() {
  printf("%d\n", ans.size());
  for (int vs = ans.size(), i = 0; i < vs; ++i) printf("%d ", ans[i]);
  puts("");
}
int main() {
  int T = 1;
  for (; T--;) {
    into();
    work();
    outo();
  }
  return 0;
}
