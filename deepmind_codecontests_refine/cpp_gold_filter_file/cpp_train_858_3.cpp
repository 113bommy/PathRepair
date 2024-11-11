#include <bits/stdc++.h>
using namespace std;
const int MAXN = 110005;
vector<int> g[MAXN];
int t, n, son[MAXN], balance, tag[MAXN], root[MAXN], cnt;
void init() {
  for (int i = 0; i < n + 10; i++) {
    g[i].clear();
    root[i] = son[i] = tag[i] = 0;
  }
  balance = n / 2;
  cnt = 0;
}
void dfs(int x, int pre) {
  son[x] = 1;
  int res = 0;
  for (int i = 0; i < g[x].size(); i++) {
    int v = g[x][i];
    if (v != pre) {
      dfs(v, x);
      son[x] += son[v];
      res = max(res, son[v]);
    }
  }
  res = max(res, n - son[x]);
  if (res < balance) {
    cnt = 0;
    root[cnt++] = x;
    balance = res;
  } else if (res == balance)
    root[cnt++] = x;
}
void dfs2(int x, int pre) {
  for (int i = 0; i < g[x].size(); i++) {
    int v = g[x][i];
    if (v != pre) {
      tag[x] = x;
      dfs(v, x);
    }
  }
}
int main() {
  cin >> t;
  while (t--) {
    cin >> n;
    init();
    for (int i = 1; i < n; i++) {
      int a, b;
      cin >> a >> b;
      g[a].push_back(b);
      g[b].push_back(a);
    }
    dfs(1, 0);
    if (cnt == 1) {
      int v1 = 1;
      int t1 = g[1][0];
      cout << v1 << " " << t1 << endl;
      cout << v1 << " " << t1 << endl;
    } else if (cnt == 2) {
      int x1 = root[0];
      int x2 = root[1];
      int x3;
      dfs(x1, -1);
      for (int i = 0; i < g[x1].size(); i++) {
        int v = g[x1][i];
        if (v != x2) {
          x3 = v;
          break;
        }
      }
      cout << x1 << " " << x3 << endl;
      cout << x2 << " " << x3 << endl;
    }
  }
  return 0;
}
