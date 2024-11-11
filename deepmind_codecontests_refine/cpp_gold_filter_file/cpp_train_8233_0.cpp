#include <bits/stdc++.h>
using namespace std;
long long n, m, num[20][100100], pos[20][100100], last, ans;
inline bool check(long long u, long long v) {
  long long i, j;
  for (j = 2; j <= m; j++) {
    if (num[j][pos[j][u] + v] != num[j - 1][pos[j - 1][u] + v]) return 0;
  }
  return 1;
}
int main() {
  long long i, j, l, r, mid;
  cin >> n >> m;
  for (i = 1; i <= m; i++) {
    for (j = 1; j <= n; j++) {
      scanf("%lld", &num[i][j]);
      pos[i][num[i][j]] = j;
    }
  }
  for (i = 1; i <= n; i++) {
    for (j = max(1ll, last - 1); j + i <= n; j++) {
      if (!check(num[1][i], j)) break;
    }
    ans += j;
    last = j;
  }
  cout << ans;
}
