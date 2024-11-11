#include <bits/stdc++.h>
using namespace std;
long long int n, i, j, k, y, x, ans1, ans2, sum, lo, hi, ans;
long long int inf = 1000000000000000000;
long long int dp[2][1005], a[2000000], b[200000], xx, yy, zz, vis[200000];
pair<long long int, long long int> p[300000];
vector<long long int> v[300002];
map<pair<long long int, long long int>, long long int> m;
long long int s;
int main() {
  ios::sync_with_stdio(false);
  cin >> s >> x;
  y = (s - x) / 2;
  if ((s - x) % 2 != 0 || y < 0 || (x & y) != 0) {
    cout << "0\n";
    return 0;
  }
  k = 0;
  while (x) {
    k += (x % 2);
    x /= 2;
  }
  ans = (1ll << k);
  if (y == 0) {
    ans -= 2;
  }
  cout << ans << endl;
}
