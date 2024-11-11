#include <bits/stdc++.h>
using namespace std;
#pragma GCC target("avx2")
#pragma GCC optimization("O3")
#pragma GCC optimization("unroll-loops")
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long n, m, q;
  cin >> n >> m >> q;
  long long grid[n][m];
  for (long long i = 0; i < n; i++)
    for (long long j = 0; j < m; j++) cin >> grid[i][j];
  while (q--) {
    long long k;
    cin >> k;
    long long i = 0, j = k - 1;
    while (i < n) {
      if (grid[i][j] == 1) {
        grid[i][j] = 2;
        j++;
      } else if (grid[i][j] == 3) {
        grid[i][j] = 2;
        j--;
      } else {
        i++;
      }
    }
    cout << j + 1 << ' ';
  }
  return 0;
}
