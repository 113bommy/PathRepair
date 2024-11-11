#include <bits/stdc++.h>
using namespace std;
long long int mod = LLONG_MAX;
long long int power(long long int a, long long int b) {
  if (b == 0) return 1;
  long long int ans = power(a, b / 2);
  ans = (ans * ans) % mod;
  if (b % 2) ans *= a;
  return ans % mod;
}
long long int mul(long long int a, long long int n, long long int mod) {
  long long int ret;
  if (n == 0) return 0;
  ret = mul(a, n / 2, mod);
  ret = (ret + ret) % mod;
  if (n % 2) ret = (ret + a) % mod;
  return ret;
}
long long int n, a, r, m, val;
vector<long long int> v;
vector<long long int> rtol;
vector<long long int> ltor;
vector<long long int>::iterator it;
long long int findcost(long long int mid) {
  it = lower_bound(v.begin() + 1, v.begin() + 1 + n, mid);
  int idx = it - v.begin();
  long long int extra = rtol[idx] - (n - idx + 1) * mid;
  long long int req = (idx - 1) * mid - ltor[idx - 1];
  long long int cost = 0;
  if (r + a < m)
    cost = extra * r + req * a;
  else {
    if (extra >= req) {
      cost = req * m;
      cost += (extra - req) * r;
    } else {
      cost = extra * m;
      cost += (req - extra) * a;
    }
  }
  return cost;
}
int main() {
  ios_base::sync_with_stdio(false);
  cout.tie(NULL);
  cin.tie(NULL);
  cin >> n >> a >> r >> m;
  v.assign(n + 2, 0);
  rtol.assign(n + 2, 0);
  ltor.assign(n + 2, 0);
  for (int i = 1; i <= n; i++) cin >> v[i];
  sort(v.begin() + 1, v.begin() + 1 + n);
  for (int i = n; i >= 1; i--) rtol[i] = rtol[i + 1] + v[i];
  for (int i = 1; i <= n; i++) ltor[i] = ltor[i - 1] + v[i];
  long long int be = v[1], end = v[n], mid;
  long long int ans = LLONG_MAX;
  while (be <= end) {
    mid = (be + end) / 2;
    long long int cost = findcost(mid);
    long long int cost1 = findcost(mid - 1);
    long long int cost2 = findcost(mid + 1);
    ans = min(ans, cost);
    if (cost1 > cost2)
      be = mid + 1;
    else
      end = mid - 1;
  }
  cout << ans << "\n";
}
