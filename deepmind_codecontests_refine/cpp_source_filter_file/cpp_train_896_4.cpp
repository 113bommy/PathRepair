#include <bits/stdc++.h>
using namespace std;
const long long N = 5e5 + 5;
long long arr[N];
long long brr[N];
long long dp[N];
long long clr[N];
vector<long long> adj[N];
long long vis[N] = {0};
long long ans[N];
long long cnt = 0;
void fast() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
}
void solve() {
  long long n, m;
  cin >> n >> m;
  long long a, b, ans, p;
  cin >> a >> b;
  if (a) ans = 0;
  p = b;
  for (long long i = 1; i < n; i++) {
    cin >> a >> b;
    if (a <= p)
      p = max(p, b);
    else if (p < m)
      ans = 0;
  }
  if (p < m) ans = 0;
  if (ans)
    cout << "YES"
         << "\n";
  else
    cout << "NO"
         << "\n";
}
int32_t main() {
  fast();
  long long t = 1;
  while (t--) solve();
}
