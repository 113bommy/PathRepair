#include <bits/stdc++.h>
using namespace std;
const int offset = 1e3;
const int maxn = offset << 1 | 1;
bool vis[maxn][maxn];
int n;
pair<int, int> pt[3000];
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d %d", &pt[i].first, &pt[i].second);
    pt[i].first += offset;
    pt[i].second += offset;
    vis[pt[i].first][pt[i].second] = true;
  }
  int ans = 0;
  for (int i = 0; i < n; ++i)
    for (int j = i + 1; j < n; ++j) {
      int x = pt[i].first + pt[j].first;
      int y = pt[i].second + pt[j].second;
      ans += (x % 2 == 0 && y % 2 == 0 && vis[x / 2][y / 2]);
    }
  printf("%d\n", ans);
}
