#include <bits/stdc++.h>
using namespace std;
inline int read() {
  char ch = getchar();
  int nega = 1;
  while (!isdigit(ch)) {
    if (ch == '-') nega = -1;
    ch = getchar();
  }
  int ans = 0;
  while (isdigit(ch)) {
    ans = ans * 10 + ch - 48;
    ch = getchar();
  }
  if (nega == -1) return -ans;
  return ans;
}
void print(vector<int> x) {
  for (int i = 0; i < (int)x.size(); i++)
    printf("%d%c", x[i], " \n"[i == (int)x.size() - 1]);
}
vector<int> G[100005], H[100005];
int dgr[100005], vis[100005], used[100005];
void dfs(int u, int f) {
  used[u] = 1, vis[u] = 1;
  for (int v : G[u]) {
    if (!vis[v]) H[u].push_back(v), dgr[v]++;
    if (!used[v]) dfs(v, u);
  }
  vis[u] = 0;
}
int query(int x, int y) {
  cout << "? " << x << " " << y << endl;
  return read();
}
signed main() {
  int n = read(), m = read();
  for (int i = 1; i <= m; i++) {
    int u = read(), v = read();
    G[u].push_back(v);
  }
  for (int i = 1; i <= n; i++)
    if (!used[i]) dfs(i, 0);
  queue<int> q;
  for (int i = 1; i <= n; i++)
    if (!dgr[i]) q.push(i);
  while (q.size() > 1) {
    int u = q.front();
    q.pop();
    int v = q.front();
    q.pop();
    if (!query(u, v)) swap(u, v);
    for (int v : H[u]) {
      dgr[v]--;
      if (!dgr[v]) q.push(v);
    }
    q.push(u);
  }
  cout << "! " << q.front() << endl;
  return 0;
}
