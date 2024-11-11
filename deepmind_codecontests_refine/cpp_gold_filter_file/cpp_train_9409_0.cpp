#include <bits/stdc++.h>
using namespace std;
const long long N = 505;
long long n, dis[N][N], x[N];
vector<long long> ans;
bitset<N> b;
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for (long long i = 1; i <= n; i++)
    for (long long j = 1; j <= n; j++) cin >> dis[i][j];
  for (long long i = n; i >= 1; i--) cin >> x[i];
  for (long long k = 1; k <= n; k++) {
    long long sum = 0;
    b[x[k]] = 1;
    for (long long i = 1; i <= n; i++) {
      for (long long j = 1; j <= n; j++) {
        dis[i][j] = min(dis[i][j], dis[i][x[k]] + dis[x[k]][j]);
        if (b[i] && b[j]) sum += dis[i][j];
      }
    }
    ans.emplace_back(sum);
  }
  for (long long i = n - 1; i >= 0; i--) cout << ans[i] << ' ';
}
