#include <bits/stdc++.h>
using namespace std;
const int N = 1010;
int n, m, cntRow[N], cntCol[N];
char grid[N][N];
long long ans;
int main() {
  cin >> n >> m;
  for (int i = 0; i < n; ++i) {
    scanf("%s", grid[i]);
    for (int j = 0; j < m; ++j) {
      cntRow[i] += (grid[i][j] == '*');
      cntCol[j] += (grid[i][j] == '*');
    }
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (grid[i][j] == '*') {
        ans += (cntRow[i] - 1LL) * (cntCol[j] - 1LL);
      }
    }
  }
  cout << ans;
  return 0;
}
