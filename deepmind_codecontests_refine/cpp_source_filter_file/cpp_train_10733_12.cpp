#include <bits/stdc++.h>
const int N = 1005;
int tot, head[N], vis[N];
struct edge {
  int to, nxt;
} e[N << 1];
void addedge(int x, int y) {
  e[++tot] = (edge){y, head[x]};
  head[x] = tot;
  e[++tot] = (edge){x, head[y]};
  head[y] = tot;
}
int col1[N], col2[N];
int bfs(int start) {
  std::queue<int> q;
  q.push(start);
  while (q.size()) {
    int tmp = q.front();
    q.pop();
    if (col1[tmp]) return tmp;
    for (int i = head[tmp]; i; i = e[i].nxt)
      if (!vis[e[i].to]) {
        vis[e[i].to] = 1, q.push(e[i].to);
      }
  }
  return -1;
}
int n, x, y;
void solve() {
  std::cin >> n;
  tot = 0;
  for (int i = 1; i <= n; i++) head[i] = col1[i] = col2[i] = vis[i] = 0;
  for (int i = 1; i < n; i++) std::cin >> x >> y, addedge(x, y);
  int k1, k2;
  std::cin >> k1;
  for (int i = 1; i <= k1; i++) std::cin >> x, col1[x] = 1;
  std::cin >> k2;
  for (int i = 1; i <= k2; i++) std::cin >> x, col2[x] = 1;
  std::cout << "B " << x << std::endl;
  std::cout.flush();
  int p;
  std::cin >> p;
  p = bfs(p);
  std::cout << "A " << p << std::endl;
  std::cout.flush();
  int back;
  std::cin >> back;
  if (col1[back])
    std::cout << "C " << p << std::endl;
  else
    std::cout << "C -1" << std::endl;
}
int main() {
  std::ios::sync_with_stdio(0);
  std::cin.tie(0);
  int tc;
  std::cin >> tc;
  while (tc--) solve();
  return 0;
}
