#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:16777216")
using namespace std;
const double eps = 1e-9;
const double pi = acos(-1.0);
const int maxn = (int)1e5 + 10;
vector<int> g[maxn];
bool used[maxn];
int size[2], res[maxn];
vector<int> w[2];
void dfs(int v, int e) {
  used[v] = true;
  w[e].push_back(v);
  for (__typeof((g[v]).begin()) it = (g[v]).begin(); it != (g[v]).end(); it++)
    if (!used[*it]) {
      dfs(*it, e ^ 1);
    }
}
int main() {
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int a, b;
    scanf("%d%d", &a, &b);
    g[a].push_back(b);
    g[b].push_back(a);
  }
  for (int i = 1; i <= n; i++)
    if (!used[i]) {
      dfs(i, 0);
    }
  for (int i = 0; i < 2; i++) {
    size[i] = (int)(w[i]).size();
  }
  if (size[0] % 3 == 0) {
    int it = 1;
    for (int i = 0; i < 2; i++) {
      for (int j = 0; j < size[i]; j += 3) {
        for (int k = 0; k < 3; k++) {
          res[w[i][j + k]] = it;
        }
        it++;
      }
    }
    puts("YES");
    for (int i = 1; i <= n; i++) {
      printf("%d ", res[i]);
    }
    return 0;
  } else {
    int it = 1;
    int e = size[0] % 3 == 1 ? 0 : 1;
    for (int i = 0; i < size[e]; i++) {
      int v = w[0][i];
      if ((int)(g[v]).size() >= size[e ^ 1] - 1) continue;
      res[v] = it;
      memset(used, false, sizeof(used));
      for (int j = 0; j < (int)(g[v]).size(); j++) {
        used[g[v][j]] = true;
      }
      int cnt = 0;
      for (int j = 0; j < size[e ^ 1]; j++) {
        int u = w[e ^ 1][j];
        if (used[u]) continue;
        res[u] = it;
        ++cnt;
        if (cnt == 2) {
          it++;
          break;
        }
      }
      cnt = 0;
      for (int j = 0; j < 2; j++) {
        for (int k = 0; k < size[j]; k++) {
          int v = w[j][k];
          if (res[v]) continue;
          res[v] = it;
          ++cnt;
          if (cnt == 3) {
            it++;
            cnt = 0;
          }
        }
      }
      puts("YES");
      for (int j = 1; j <= n; j++) {
        printf("%d ", res[i]);
      }
      return 0;
    }
    e ^= 1;
    vector<int> good;
    for (int i = 0; i < size[e]; i++) {
      int v = w[e][i];
      if ((int)(g[v]).size() >= size[e ^ 1] - 1) continue;
      good.push_back(v);
      if ((int)(good).size() == 2) break;
    }
    if ((int)(good).size() < 2) {
      puts("NO");
      return 0;
    }
    puts("YES");
    for (int i = 0; i < 2; i++) {
      int v = good[i];
      res[v] = it;
      memset(used, false, sizeof(used));
      for (int j = 0; j < (int)(g[v]).size(); j++) {
        used[g[v][j]] = true;
      }
      int cnt = 0;
      for (int j = 0; j < size[e ^ 1]; j++) {
        int u = w[e ^ 1][j];
        if (used[u]) continue;
        res[u] = it;
        cnt++;
        if (cnt == 2) {
          it++;
          break;
        }
      }
    }
    int cnt = 0;
    for (int i = 0; i < 2; i++) {
      for (int j = 0; j < size[i]; j++) {
        int v = w[i][j];
        if (res[v]) continue;
        res[v] = it;
        cnt++;
        if (cnt == 3) {
          cnt = 0;
          it++;
        }
      }
    }
    for (int i = 1; i <= n; i++) {
      printf("%d ", res[i]);
    }
    return 0;
  }
  return 0;
}
