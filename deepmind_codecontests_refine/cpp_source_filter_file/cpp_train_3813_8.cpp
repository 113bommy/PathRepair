#include <bits/stdc++.h>
using namespace std;
void mahakal() {}
long long dx[4] = {1, 0, -1, 0};
long long dy[4] = {0, 1, 0, -1};
char c[4] = {'D', 'R', 'U', 'L'};
const long long maxN = 2e2 + 5;
long long n, m, k;
long long a[maxN][maxN], b[maxN][maxN];
void solve() {
  cin >> n >> m >> k;
  for (long long i = 1; i <= n; i++) {
    for (long long j = 1; j <= m; j++) {
      cin >> a[i][j];
    }
  }
  for (long long i = 1; i <= m; i++) {
    for (long long j = 1; j <= n; j++) {
      b[j][i] = b[j - 1][i] + a[j][i];
    }
  }
  long long fcost = 0, ans = 0;
  for (long long i = 1; i <= m; i++) {
    long long cost = 0, mx = 0, mxcost = 0;
    for (long long j = 1; j <= n; j++) {
      if (a[j][i] == 1) {
        long long ps = b[j + k - 1][i] - b[j - 1][i];
        ;
        if (ps > mx) {
          mx = ps;
          mxcost = cost;
        }
        cost++;
      }
    }
    fcost += mxcost;
    ans += mx;
  }
  cout << ans << ' ' << fcost << endl;
}
int main() {
  mahakal();
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  long long t = 1;
  while (t--) solve();
  cerr << "\ntime taken : " << (float)clock() / CLOCKS_PER_SEC << " secs"
       << endl;
  return 0;
}
