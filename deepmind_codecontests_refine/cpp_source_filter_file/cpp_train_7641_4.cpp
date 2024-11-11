#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const long long MOD = 1000000007;
const int N = 505;
int a[N][N];
bool v[N][N];
vector<char> road;
char ty[] = {'E', 'W', 'D', 'U'};
int X[] = {0, 0, 1, -1};
int Y[] = {1, -1, 0, 0};
int n, xx0, yy0;
int num;
void dfs(int x1, int y1) {
  v[x1][y1] = true;
  if (a[x1][y1] == 1) ++num;
  if (a[x1][y1] == 0) {
    a[x1][y1] = 1;
    road.push_back('1');
  }
  for (int i = 0; i < 4; ++i) {
    int x = x1 + X[i];
    int y = y1 + Y[i];
    bool flag = false;
    int x2 = x, y2 = y;
    while (x2 >= 1 && x2 <= n && y2 >= 1 && y2 <= n && !v[x2][y2]) {
      if (a[x2][y2] == 1) {
        flag = true;
        break;
      }
      x2 = x2 + X[i];
      y2 = y2 + Y[i];
    }
    if (flag) {
      road.push_back(ty[i]);
      dfs(x, y);
      road.push_back(ty[i ^ 1]);
    }
  }
  a[x1][y1] = 0;
  road.push_back('2');
}
int main() {
  while (scanf("%d %d %d", &n, &xx0, &yy0) != EOF) {
    int m = 0;
    for (int i = 1; i <= n; ++i)
      for (int j = 1; j <= n; ++j) {
        scanf("%d", &a[i][j]);
        if (a[i][j] == 1) ++m;
      }
    road.clear();
    memset(v, false, sizeof(v));
    num = 0;
    dfs(xx0, yy0);
    if (m != num)
      printf("NO\n");
    else {
      printf("YES\n");
      for (unsigned int i = 0; i < road.size(); ++i) printf("%c", road[i]);
      printf("\n");
    }
  }
  return 0;
}
