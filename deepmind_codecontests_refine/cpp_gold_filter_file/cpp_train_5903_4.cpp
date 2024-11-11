#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
vector<int> v[N], e[N];
int dis[N][110], a[N];
queue<int> Q;
int main() {
  int n, m, k, s;
  scanf("%d%d%d%d", &n, &m, &k, &s);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]), v[a[i]].push_back(i);
  for (int i = 1; i <= m; i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    e[x].push_back(y);
    e[y].push_back(x);
  }
  memset(dis, -1, sizeof(dis));
  for (int c = 1; c <= k; c++) {
    for (auto i : v[c]) {
      Q.push(i);
      dis[i][c] = 0;
    }
    while (!Q.empty()) {
      int x = Q.front();
      Q.pop();
      for (auto i : e[x]) {
        if (dis[i][c] == -1) {
          dis[i][c] = dis[x][c] + 1;
          Q.push(i);
        }
      }
    }
  }
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    ans = 0;
    sort(dis[i] + 1, dis[i] + 1 + k);
    for (int j = 1; j <= s; j++) {
      ans += dis[i][j];
    }
    printf("%d ", ans);
  }
  return 0;
}
