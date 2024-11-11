#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  scanf("%d\n", &n);
  pair<int, int> target[10001];
  vector<int> V[42001];
  for (int i = 1; i <= n; i++) {
    scanf("%d %d\n", &(target[i].first), &(target[i].second));
    target[i].first += 21000;
    for (int j = target[i].first - target[i].second;
         j <= target[i].first + target[i].second; j++)
      V[j].push_back(i);
  }
  int m;
  scanf("%d\n", &m);
  int res[10001 * 2];
  memset(res, -1, sizeof(res));
  int cnt = 0;
  for (int i = 1; i <= m; i++) {
    int x, y;
    scanf("%d %d\n", &x, &y);
    x += 21000;
    for (int j = 0; j < V[x].size(); j++)
      if (res[V[x][j]] == -1 &&
          hypot(x - target[V[x][j]].first, y) <= target[V[x][j]].second) {
        res[V[x][j]] = i;
        cnt++;
      }
  }
  printf("%d\n", cnt);
  for (int i = 1; i <= n; i++) printf("%d ", res[i]);
exit:
  return (0);
}
