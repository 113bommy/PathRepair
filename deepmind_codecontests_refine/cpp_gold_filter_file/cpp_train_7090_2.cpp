#include <bits/stdc++.h>
using namespace std;
int SIZE;
int nxt[300005], vis[300005], cnt;
int *str[300005], s1[300005], len[300005];
vector<int> sid[300005];
bool check1(int x) {
  cnt++;
  for (int i = 0; i < sid[x].size(); i++) {
    int u = sid[x][i], pos = 0;
    for (int j = 1; j <= len[u]; j++)
      if (str[u][j] == x) {
        pos = j;
        break;
      }
    int t = str[u][pos + 1];
    for (int j = pos + 1; j <= len[u]; j++) {
      int v = str[u][j];
      if (vis[v] < cnt) {
        vis[v] = cnt;
        nxt[v] = t;
      } else if (nxt[v] != t)
        return 0;
    }
  }
  return 1;
}
int id[300005];
bool check2(int x, int n, int m) {
  for (int i = 1; i <= n; i++) id[i] = 0;
  for (int i = 1; i <= len[x]; i++) id[str[x][i]] = i;
  for (int i = 1; i <= m; i++)
    if (i != x) {
      int minn = len[x] + 1;
      for (int j = 1; j <= len[i]; j++)
        if (id[str[i][j]]) {
          int v = str[i][j];
          if (id[v] < minn)
            minn = id[v];
          else if (id[v] != id[str[i][j - 1]] + 1)
            return 0;
        }
    }
  return 1;
}
bool solve(int n, int m) {
  SIZE = (int)sqrt(n);
  for (int i = 1; i <= m; i++)
    if (len[i] <= SIZE) {
      for (int j = 1; j <= len[i]; j++) sid[str[i][j]].push_back(i);
    }
  for (int i = 1; i <= n; i++)
    if (!check1(i)) return 0;
  for (int i = 1; i <= m; i++)
    if (len[i] > SIZE && !check2(i, n, m)) return 0;
  return 1;
}
void init(int n, int m) {
  for (int i = 1; i <= n; i++) sid[i].clear();
  for (int i = 1; i <= m; i++) {
    delete str[i];
    len[i] = 0;
  }
}
int main() {
  int cases;
  scanf("%d", &cases);
  for (; cases; cases--) {
    int n, m;
    scanf("%d%d", &n, &m);
    init(n, m);
    for (int i = 1; i <= m; i++) {
      scanf("%d", &len[i]);
      str[i] = new int[len[i] + 1];
      str[i][0] = 0;
      for (int j = 1; j <= len[i]; j++) scanf("%d", &str[i][j]);
    }
    puts((solve(n, m)) ? "Robot" : "Human");
  }
  return 0;
}
