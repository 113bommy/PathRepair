#include <bits/stdc++.h>
using namespace std;
const int N = 200100;
const int P = 1000000007;
int H[N], to[N], type[N], nxt[N], e = 1;
void addedge(int t, int v, int s) {
  e++, to[e] = v, type[e] = s, nxt[e] = H[t], H[t] = e;
  e++, to[e] = t, type[e] = s, nxt[e] = H[v], H[v] = e;
}
int vis[N], col[N];
void dfs(int u, int c) {
  if (vis[u]) {
    if (col[u] == c)
      return;
    else {
      puts("0");
      exit(0);
    }
  }
  vis[u] = 1;
  col[u] = c;
  for (int i = H[u], v = to[i]; i; i = nxt[i], v = to[i]) {
    dfs(v, c ^ type[i]);
  }
}
int main() {
  int n, m;
  cin >> n >> m;
  while (m--) {
    char c;
    int i, j;
    scanf("%d%d %c", &i, &j, &c);
    int k = c == 'o';
    if (i + j > n + 1) i = n + 1 - i, j = n + 1 - j;
    if (i > j) swap(i, j);
    int t = max(j - i - 1, 0);
    int v = j + i - 1;
    addedge(t, v, k);
  }
  int cnt = -1;
  for (int i = 0; i <= n; i++)
    if (!vis[i]) {
      cnt++;
      dfs(i, 0);
    }
  int ans = 1;
  while (cnt--) ans = ans * 2 % P;
  cout << ans << endl;
  return 0;
}
