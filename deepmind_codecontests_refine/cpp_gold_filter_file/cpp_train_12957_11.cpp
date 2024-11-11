#include <bits/stdc++.h>
using namespace std;
const int inf = 1e9 + 5;
const long long linf = 1e18 + 5;
const int N = 2000 + 5;
const int mod = 1e9 + 7;
int d, n, a[N], x, y, dp[N], st, ans;
vector<int> v[N];
int f(int root, int x) {
  int &r = dp[x];
  if (r != -1) return r;
  r = 1;
  for (__typeof(v[x].begin()) it = v[x].begin(); it != v[x].end(); it++)
    if (*it != root and (a[*it] < a[st] or (a[*it] == a[st] and *it > st)) and
        a[st] - a[*it] <= d)
      r = ((long long)r * (f(x, *it) + 1)) % mod;
  return r;
}
int main() {
  ios ::sync_with_stdio(0);
  cin >> d >> n;
  for (int i = 1; i <= n; i++) cin >> a[i];
  for (int i = 1; i <= n - 1; i++) {
    cin >> x >> y;
    v[x].push_back(y);
    v[y].push_back(x);
  }
  for (int i = 1; i <= n; i++) {
    st = i;
    memset(dp, -1, sizeof(dp));
    ans = (ans + f(0, i)) % mod;
  }
  cout << ans << '\n';
  0;
  return 0;
}
