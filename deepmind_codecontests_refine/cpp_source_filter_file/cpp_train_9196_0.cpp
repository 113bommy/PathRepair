#include <bits/stdc++.h>
using namespace std;
const int N = 300010;
int n, k, S, T;
char s[2][N];
vector<int> g[N];
void Build(void) {
  S = 1;
  for (int i = 1; i <= n; ++i) {
    if (s[0][i] == '-') {
      if (i > 1 && s[0][i - 1] == '-')
        g[i].push_back(i - 1), g[i - 1].push_back(i);
      if (i < n && s[0][i + 1] == '-')
        g[i].push_back(i + 1), g[i + 1].push_back(i);
      if (i + k <= n && s[1][i + k] == '-')
        g[i].push_back(i + k + n), g[i + k + n].push_back(i);
    }
    if (s[1][i] == '-') {
      if (i > 1 && s[1][i - 1] == '-')
        g[i + n].push_back(i - 1 + n), g[i - 1 + n].push_back(i + n);
      if (i < n && s[1][i + 1] == '-')
        g[i + n].push_back(i + 1 + n), g[i + 1 + n].push_back(i + n);
      if (i + k <= n && s[0][i + k] == '-')
        g[i + n].push_back(i + k), g[i + k].push_back(i + n);
    }
  }
  T = 2 * n + 1;
  for (int i = n - k; i <= n; ++i)
    if (s[0][i] == '-') g[i].push_back(T), g[T].push_back(i);
  for (int i = n - k; i <= n; ++i)
    if (s[1][i] == '-') g[i + n].push_back(T), g[T].push_back(i + n);
}
int dis[N];
queue<int> q;
bool Solve(void) {
  memset(dis, 0x3f, sizeof dis);
  dis[S] = 1;
  q.push(S);
  while (!q.empty()) {
    int x = q.front();
    q.pop();
    for (int i = 0; i < (int)g[x].size(); ++i) {
      int y = g[x][i];
      if (dis[y] > dis[x] + 1) {
        int num = y;
        if (y > n) num -= n;
        if (dis[x] + 1 <= num) dis[y] = dis[x] + 1, q.push(y);
      }
    }
  }
  return dis[T] <= n + 1;
}
int main(void) {
  scanf("%d%d", &n, &k);
  scanf("%s%s", s[0] + 1, s[1] + 1);
  Build();
  if (Solve())
    puts("YES");
  else
    puts("NO");
  return 0;
}
