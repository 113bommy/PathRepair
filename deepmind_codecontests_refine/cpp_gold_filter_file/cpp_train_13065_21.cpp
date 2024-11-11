#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  const int N = 1e2 + 10;
  int n, m;
  int v[N][2 * N];
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 2 * m; j++) {
      cin >> v[i][j];
    }
  }
  int ans = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 2 * m; j += 2) {
      if (v[i][j] == 1 or v[i][j + 1] == 1) ans++;
    }
  }
  cout << ans << endl;
  return 0;
}
