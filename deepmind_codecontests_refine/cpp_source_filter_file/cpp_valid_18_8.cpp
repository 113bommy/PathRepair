#include <bits/stdc++.h>
using namespace std;
int t = 1;
int n, k;
int a[110];
vector<vector<int>> v;
int if_intersect(int x1, int y1, int x2, int y2) {
  int cnt = 0;
  for (int i = x1; i <= y1; i++) {
    if (i == x2 || i == y2) cnt++;
  }
  return cnt == 1;
}
int main() {
  scanf("%d", &t);
  while (t--) {
    v.clear();
    fill(a, a + 101, 0);
    scanf("%d %d", &n, &k);
    for (int i = 0; i < k; i++) {
      int x, y;
      scanf("%d %d", &x, &y);
      v.push_back({min(x, y), max(x, y)});
      a[x] = 1;
      a[y] = 1;
    }
    int ans = ((n - k - 1) * (n - k)) / 2;
    for (int i = 0; i < k - 1; i++) {
      for (int j = i + 1; j < k; j++) {
        ans += if_intersect(v[i][0], v[i][1], v[j][0], v[j][1]);
      }
    }
    for (int i = 0; i < k; i++) {
      int x = v[i][0];
      int y = v[i][1];
      int cnt = 0;
      for (int i = x; i <= y; i++) {
        if (!a[i]) cnt++;
      }
      int m = min(cnt, 2 * n - 2 * k - cnt);
      ans += m;
    }
    printf("%d\n", ans);
  }
}
