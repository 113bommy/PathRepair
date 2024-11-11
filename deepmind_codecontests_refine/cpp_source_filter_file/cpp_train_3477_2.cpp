#include <bits/stdc++.h>
using namespace std;
const int N = 110;
int sg[N][4];
int cal(int x, int y) {
  if (x <= 0) return 0;
  if (x == 1 && y == 3) return 0;
  if (sg[x][y] != -1) return sg[x][y];
  bool vis[110];
  memset(vis, 0, sizeof(vis));
  if (y == 0) {
    for (int i = 0; i < x; i++) {
      int s1 = cal(i, 1);
      int s2 = cal(x - i - 1, 1);
      vis[s1 ^ s2] = true;
    }
    int cnt = 0;
    while (vis[cnt]) cnt++;
    return sg[x][y] = cnt;
  }
  if (y == 1) {
    for (int i = 0; i < x; i++) {
      int s1 = cal(i, 1);
      int s2 = cal(x - i - 1, 2);
      vis[s1 ^ s2] = true;
    }
    for (int i = 0; i < x - 1; i++) {
      int s1 = cal(i, 1);
      int s2 = cal(x - i - 1, 3);
      vis[s1 ^ s2] = true;
    }
    int cnt = 0;
    while (vis[cnt]) cnt++;
    return sg[x][y] = cnt;
  }
  if (y == 2) {
    for (int i = 0; i < x; i++) {
      int s1 = cal(i, 2);
      int s2 = cal(x - i - 1, 2);
      vis[s1 ^ s2] = true;
    }
    for (int i = 1; i < x - 1; i++) {
      int s1 = cal(i, 3);
      int s2 = cal(x - 1 - i, 3);
      vis[s1 ^ s2] = true;
    }
    int cnt = 0;
    while (vis[cnt]) cnt++;
    return sg[x][y] = cnt;
  }
  if (y == 3) {
    for (int i = 1; i < x; i++) {
      int s1 = cal(i, 3);
      int s2 = cal(x - i - 1, 2);
      vis[s1 ^ s2] = true;
    }
    for (int i = 0; i < x - 1; i++) {
      int s1 = cal(i, 2);
      int s2 = cal(x - i - 1, 3);
      vis[s1 ^ s2] = true;
    }
    int cnt = 0;
    while (vis[cnt]) cnt++;
    return sg[x][y] = cnt;
  }
  return 0;
}
pair<int, int> p[N];
int main() {
  memset(sg, -1, sizeof(sg));
  for (int i = 0; i <= 100; i++)
    for (int j = 0; j < 4; j++) sg[i][j] = cal(i, j);
  int r, n;
  scanf("%d%d", &r, &n);
  for (int i = 0; i < n; i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    x--;
    y--;
    p[i] = make_pair(x, y);
  }
  sort(p, p + n);
  int ans = 0;
  if (n == 0)
    ans = cal(n, 0);
  else {
    ans ^= cal(p[0].first, 1);
    for (int i = 1; i < n; i++) {
      int x = p[i].first - p[i - 1].first - 1;
      int y;
      if (p[i].second == p[i - 1].second)
        y = 2;
      else
        y = 3;
      ans ^= cal(x, y);
    }
    ans ^= cal(r - 1 - p[n - 1].first, 1);
  }
  if (ans)
    printf("WIN\n");
  else
    printf("LOSE\n");
  return 0;
}
