#include <bits/stdc++.h>
using namespace std;
long long a[1000010], b[1010][1010], d[100010], dp[1010][1010], p[1000010];
long long mn = 1e9, mx = -1e9, ans, cnt, sm = 1, n, m;
bool ok, okk, u[1000010], uu[510][510];
char ck[100010], ch[1010][1010];
int dx[5] = {0, 1, 0, -1}, dy[5] = {-1, 0, 1, 0};
vector<long long> g[100010], v, vv;
int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i < 1e5 + 1; i++) {
    if (i >= m) {
      cnt = i;
      break;
    }
    m -= i;
  }
  cout << a[m];
  return 0;
}
