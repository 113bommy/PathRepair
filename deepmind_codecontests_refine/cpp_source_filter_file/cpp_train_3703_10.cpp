#include <bits/stdc++.h>
using namespace std;
const int N = 1000010;
int n, part[N], a[N], b[N];
vector<int> g[N];
queue<int> q;
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= 2 * n - 1; i += 2) {
    g[i].push_back(i + 1);
    g[i + 1].push_back(i);
  }
  for (int i = 1; i <= n; i++) {
    scanf("%d%d", &a[i], &b[i]);
    g[a[i]].push_back(b[i]);
    g[b[i]].push_back(a[i]);
  }
  memset(part, -1, sizeof(part));
  for (int i = 1; i <= n; i++)
    if (part[i] == -1) {
      q.push(i);
      part[i] = 0;
      while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (int j = 0; j < g[v].size(); j++)
          if (part[g[v][j]] == -1) {
            part[g[v][j]] = part[v] ^ 1;
            q.push(g[v][j]);
          }
      }
    }
  for (int i = 1; i <= n; i++)
    printf("%d %d\n", part[a[i]] + 1, part[b[i]] + 1);
  return 0;
}
