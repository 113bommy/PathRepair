#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5;
const int inf = 1e9 + 5;
const double pi = acos(-1);
const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};
const int mod = 1e9 + 7;
int n, h, l, r, a[2005];
int can[2005][2005], mx[2005][2005];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ;
  cin >> n >> h >> l >> r;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  can[0][0] = 1;
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < h; j++) {
      if (can[i - 1][j]) {
        int to1 = (j + a[i]) % h, to2 = (j + a[i] - 1) % h;
        can[i][to1] = 1;
        mx[i][to1] =
            max(mx[i - 1][j] + (l <= to1 && to1 <= r ? 1 : 0), mx[i][to1]);
        can[i][to2] = 1;
        mx[i][to2] =
            max(mx[i - 1][j] + (l <= to2 && to2 <= r ? 1 : 0), mx[i][to1]);
      }
    }
  }
  int ans = 0;
  for (int i = 0; i < h; i++) {
    ans = max(ans, mx[n][i]);
  }
  cout << ans;
  return 0;
}
