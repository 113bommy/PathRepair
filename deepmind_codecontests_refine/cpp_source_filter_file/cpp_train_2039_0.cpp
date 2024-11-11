#include <bits/stdc++.h>
using namespace std;
const int maxn = 1010;
struct Two_Set {
  int n;
  vector<int> G[maxn << 1];
  bool mark[maxn << 1];
  int s[maxn], c;
  void init(int n) {
    this->n = n;
    for (int i = 0; i < (n << 1); i++) G[i].clear();
    memset(mark, 0, sizeof(mark));
  }
  void add(int x, int v1, int y, int v2) {
    int X = (x << 1) + v1;
    int Y = (y << 1) + v2;
    G[X ^ 1].push_back(Y);
    G[Y ^ 1].push_back(X);
  }
  bool dfs(int u) {
    if (mark[u ^ 1]) return false;
    if (mark[u]) return true;
    mark[u] = true;
    s[c++] = u;
    for (int i = 0; i < (int)G[u].size(); i++)
      if (!dfs(G[u][i])) return false;
    return true;
  }
  bool solve() {
    for (int i = 0; i < (n << 1); i += 2) {
      if (!mark[i] && !mark[i + 1]) {
        c = 0;
        if (!dfs(i)) {
          while (c > 0) mark[s[c--]] = false;
          if (!dfs(i + 1)) return false;
        }
      }
    }
    return true;
  }
} SET2;
int n;
string tn[maxn], hn[maxn];
string tp(int x, int y) {
  if (y == 1)
    return tn[x].substr(0, 3);
  else {
    string ret = tn[x].substr(0, 2);
    ret.push_back(hn[x][0]);
    return ret;
  }
}
int main() {
  scanf("%d", &n);
  SET2.init(n);
  for (int i = 0; i < n; i++) cin >> tn[i] >> hn[i];
  for (int i = 0; i < n; i++)
    for (int j = i + 1; j < n; j++) {
      if (tn[i].substr(0, 3) == tn[j].substr(0, 3))
        SET2.add(i, 1, j, 1), SET2.add(i, 0, j, 1), SET2.add(i, 1, j, 0);
      if (tn[i].substr(0, 3) == tp(j, 2)) SET2.add(i, 1, j, 0);
      if (tp(i, 2) == tn[j].substr(0, 3)) SET2.add(i, 0, j, 1);
      if (tp(i, 2) == tp(j, 2)) SET2.add(i, 0, j, 0);
    }
  if (!SET2.solve())
    puts("NO");
  else {
    puts("YES");
    for (int i = 0; i < n; i++) {
      if (SET2.mark[i << 1])
        cout << tn[i].substr(0, 3) << endl;
      else
        cout << tp(i, 2) << endl;
    }
  }
  return 0;
}
