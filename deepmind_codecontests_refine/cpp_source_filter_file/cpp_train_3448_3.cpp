#include <bits/stdc++.h>
using namespace std;
long long int power(long long int a, long long int b, long long int m) {
  long long int ans = 1;
  while (b) {
    if (b & 1) ans = (ans * a) % m;
    b /= 2;
    a = (a * a) % m;
  }
  return ans;
}
long long int a[300009];
vector<pair<long long int, long long int> > v[300009];
long long int ans = 0;
long long int dfs(long long int num, long long int par) {
  vector<long long int> vv;
  vv.push_back(0);
  vv.push_back(0);
  for (auto it : v[num]) {
    if (it.first == par) continue;
    vv.push_back(-(dfs(it.first, num) - it.second));
  }
  sort((vv).begin(), (vv).end());
  ans = max(ans, a[num] - (vv[0] + vv[1]));
  return a[num] + vv[0];
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long int n;
  cin >> n;
  for (long long int i = 1; i < n + 1; i++) cin >> a[i];
  for (long long int i = 1; i < n; i++) {
    long long int l, r, w;
    cin >> l >> r >> w;
    v[l].push_back({r, w});
    v[r].push_back({l, w});
  }
  dfs(1, 0);
  cout << ans << endl;
  return 0;
}
