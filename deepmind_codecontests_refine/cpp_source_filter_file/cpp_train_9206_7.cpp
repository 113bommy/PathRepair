#include <bits/stdc++.h>
using namespace std;
const double EPS = 1e-9;
const double PI = acos(-1.0);
int GCD(int x, int y) {
  if (x % y == 0)
    return y;
  else
    return (GCD(y, x % y));
}
const int INF = 1e9 + 5;
vector<int> vi[1005];
int ara[1005];
int cost[1005];
bool taken[1005];
int main() {
  int n, m, i, j, x, y;
  scanf("%d %d", &n, &m);
  for (i = 1; i <= n; i++) {
    scanf("%d", &ara[i]);
  }
  for (i = 0; i < m; i++) {
    scanf("%d %d", &x, &y);
    vi[x].push_back(y);
    vi[y].push_back(x);
  }
  for (i = 1; i <= n; i++) {
    x = 0;
    for (j = 0; j < vi[i].size(); j++) {
      y = vi[i][j];
      x += ara[y];
    }
    cost[i] = x;
  }
  long long int ans = 0LL;
  int mx = 0, mxi = 0;
  for (i = 1; i < n; i++, mx = 0) {
    for (j = 1; j <= n; j++) {
      if (!taken[j] && ara[j] > mx) {
        mx = ara[j];
        mxi = j;
      } else if (!taken[j] && ara[j] == mx && cost[j] < cost[mxi]) {
        mxi = j;
      }
    }
    taken[mxi] = 1;
    ans += cost[mxi];
    for (j = 0; j < vi[mxi].size(); j++) {
      x = vi[mxi][j];
      cost[x] -= ara[mxi];
    }
  }
  printf("%I64d\n", ans);
  return 0;
}
