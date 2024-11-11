#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const int N = 105;
int a[N][N];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 2 * m; j++) cin >> a[i][j];
  }
  int cnt = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 2 * m; j += 2) {
      if (a[i][j] || a[i][j + 1]) cnt++;
    }
  }
  cout << cnt << endl;
  return 0;
}
