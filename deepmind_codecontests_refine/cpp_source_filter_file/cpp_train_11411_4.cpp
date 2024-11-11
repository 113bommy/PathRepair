#include <bits/stdc++.h>
using namespace std;
int n, q, c;
int x, y, s;
int t, r1, c1, r2, c2;
int ans = 0;
int mp[17][107][107];
void cl() {
  for (int i = 1; i <= 100; i++) {
    for (int j = 2; j <= 100; j++) {
      for (int k = 0; k <= c; k++) {
        mp[k][i][j] += mp[k][i][j - 1];
      }
    }
  }
}
int main() {
  cin >> n >> q >> c;
  for (int i = 0; i < n; i++) {
    scanf("%d %d %d", &x, &y, &s);
    for (int j = 0; j <= c; j++) {
      mp[j][x][y] = (s + j) % (c + 1);
    }
  }
  cl();
  for (int i = 0; i < q; i++) {
    scanf("%d %d %d %d %d", &t, &r1, &c1, &r2, &c2);
    t = t % (c + 1);
    ans = 0;
    for (int j = r1; j <= r2; j++) {
      ans += mp[t][j][c2] - mp[t][j][c1 - 1];
    }
    printf("%d\n", ans);
  }
  return 0;
}
