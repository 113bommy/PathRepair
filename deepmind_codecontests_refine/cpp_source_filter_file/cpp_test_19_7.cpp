#include <bits/stdc++.h>
using namespace std;
const int N = 1e4 + 10, M = 2010;
const int INF = 0x3f3f3f3f;
int n;
int va[N];
int f[N][M];
void solve() {
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j <= 2000; j++) {
      f[i][j] = INF;
    }
  }
  f[0][0] = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j <= 2000; j++) {
      if (j + va[i] <= 2000)
        f[i][j + va[i]] = min(f[i][j + va[i]], max(f[i - 1][j], j + va[i]));
      if (j - va[i] >= 0)
        f[i][j - va[i]] = min(f[i][j - va[i]], max(f[i - 1][j], j));
      else
        f[i][0] = min(f[i][0], f[i - 1][j] + va[i] - j);
    }
  }
  cout << *min_element(f[n], f[n] + 2001) << endl;
}
int main() {
  ios::sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> va[i];
    solve();
  }
  return 0;
}
