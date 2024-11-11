#include <bits/stdc++.h>
using namespace std;
const int N = 2e3;
const int INF = 1e9 + 9;
int n, x;
int ans[N][N], cnt;
int main() {
  ios_base ::sync_with_stdio(0);
  cin.tie(0);
  cin >> x;
  for (int i = int(1); i <= int(x); ++i) {
    if (i * (i - 1) / 2 > x) {
      n = i - 1;
      break;
    }
  }
  cout << n << "\n";
  for (int i = int(1); i <= int(n); ++i) {
    for (int j = int(1); j <= int(n); ++j) {
      if (i == j) continue;
      if (ans[j][i] > 0)
        ans[i][j] = ans[j][i];
      else
        ans[i][j] = ++cnt;
      cout << ans[i][j] << " ";
    }
    cout << "\n";
  }
  return 0;
}
