#include <bits/stdc++.h>
using namespace std;
const int MAX = 11;
long long r, c, n, k, cnt[MAX][MAX], ans, x, y;
bool arr[MAX][MAX];
int main() {
  ios::sync_with_stdio(0);
  cin >> r >> c >> n >> k;
  for (int i = 0; i < n; ++i) {
    cin >> x >> y;
    arr[x][y] = true;
  }
  for (int i = 1; i <= r; ++i) {
    for (int j = 1; j <= r; ++j) {
      cnt[i][j] = arr[i][j] + cnt[i - 1][j] + cnt[i][j - 1] - cnt[i - 1][j - 1];
    }
  }
  for (int i1 = 1; i1 <= r; ++i1) {
    for (int j1 = 1; j1 <= c; ++j1) {
      for (int i2 = i1; i2 <= r; ++i2) {
        for (int j2 = j1; j2 <= c; ++j2) {
          if (cnt[i2][j2] - cnt[i1 - 1][j2] - cnt[i2][j1 - 1] +
                  cnt[i1 - 1][j1 - 1] >=
              k)
            ans++;
        }
      }
    }
  }
  cout << ans;
  return 0;
}
