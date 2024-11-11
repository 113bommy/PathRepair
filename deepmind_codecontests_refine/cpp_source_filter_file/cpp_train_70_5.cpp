#include <bits/stdc++.h>
using namespace std;
long long int power(long long int x, long long int y, long long int p) {
  long long int r = 1;
  x = x % p;
  while (y) {
    if (y & 1) r = r * x % p;
    y = y >> 1;
    x = x * x % p;
  }
  return r;
}
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int csrand(int l = 0, int r = 1e9) {
  uniform_int_distribution<int> uid(l, r);
  return uid(rng);
}
const int N = 1e6 + 99;
int road[N], prev1[N];
long long int cost[N];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n, m, k;
  cin >> n >> m >> k;
  for (int i = 0; i < m; i++) {
    int x;
    cin >> x;
    road[x] = 1;
  }
  for (int i = 0; i < k; i++) cin >> cost[i + 1];
  if (road[0] == 1) {
    cout << -1 << endl;
    return 0;
  }
  for (int i = 0; i < n; i++) {
    if (road[i] == 0)
      prev1[i] = i;
    else
      prev1[i] = prev1[i - 1];
  }
  long long int ans = 1e17;
  for (int i = 1; i <= k; i++) {
    long long int ta = 0;
    int j = 0;
    while (j < n) {
      ta += cost[i];
      if (road[j] == 1)
        if (j - prev1[j] + 1 >= i) {
          ta = 1e17;
          break;
        } else
          j = prev1[j];
      j += i;
    }
    ans = min(ans, ta);
  }
  if (ans > 1e16) ans = -1;
  cout << ans << endl;
}
