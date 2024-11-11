#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10, M = 510;
int n;
int va[N];
int f[N][M];
void solve() {
  memset(f, 0x3f, sizeof f);
  f[0][0] = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j <= 500; j++) {
      int tmp = j ^ va[i];
      if (tmp < M && va[i] > f[i - 1][tmp]) f[i][j] = min(f[i][j], va[i]);
      f[i][j] = min(f[i][j], f[i - 1][j]);
    }
  }
  int cnt = 0;
  for (int j = 0; j < M; j++) cnt += f[n][j] < 0x3f3f3f3f;
  cout << cnt << endl;
  for (int j = 0; j < M; j++) {
    if (f[n][j] < 0x3f3f3f3f) cout << j << " ";
  }
  cout << endl;
}
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> va[i];
  solve();
  return 0;
}
