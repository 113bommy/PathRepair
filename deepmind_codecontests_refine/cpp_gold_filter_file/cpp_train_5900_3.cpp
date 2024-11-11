#include <bits/stdc++.h>
using namespace std;
const int INF = 2e9;
const int N = 1e5 + 7;
int n, m, k, s, arr[N], res[N][150];
struct emp {
  int x, y, c;
};
vector<vector<int> > vt;
queue<emp> Q;
int main(void) {
  scanf("%d %d %d %d", &n, &m, &k, &s);
  vt.resize(n + 1);
  for (int i = 1; i <= n; i++) {
    int T;
    scanf("%d", &T);
    Q.push({i, 0, T});
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= k; j++) res[i][j] = INF;
  }
  for (int i = 1; i <= m; i++) {
    int x, y;
    scanf("%d %d", &x, &y);
    vt[x].push_back(y);
    vt[y].push_back(x);
  }
  while (!Q.empty()) {
    emp fr = Q.front();
    Q.pop();
    if (res[fr.x][fr.c] <= fr.y) continue;
    res[fr.x][fr.c] = fr.y;
    for (auto next : vt[fr.x]) Q.push({next, fr.y + 1, fr.c});
  }
  for (int i = 1; i <= n; i++) {
    sort(res[i] + 1, res[i] + k + 1);
    int ans = 0;
    for (int j = 1; j <= s; j++) ans += res[i][j];
    printf("%d ", ans);
  }
}
