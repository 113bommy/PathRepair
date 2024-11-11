#include <bits/stdc++.h>
using namespace std;
char vis[2005][2005];
long long a[1000005];
long long temp2[1005][1005];
long long n, m, k, p;
vector<pair<long long, long long>> ans;
bool check(double time) {
  double energy = 0;
  for (long long i = 0; i < n; i++) {
    double pp = 0;
    energy += max(pp, ans[i].first * time - ans[i].second);
  }
  if (energy <= p * time)
    return 1;
  else
    return 0;
}
double binsearch(double l, double h) {
  long long count = 1000;
  while (count--) {
    double mid = (l + h) / 2;
    if (check(mid)) {
      l = mid;
    } else
      h = mid;
  }
  return l;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  cin >> n >> p;
  long long sum = 0;
  for (long long i = 0; i < n; i++) {
    long long x, y;
    cin >> x >> y;
    sum += x;
    ans.push_back(make_pair(x, y));
  }
  if (p >= sum) {
    cout << -1;
    return 0;
  }
  double ans = binsearch(0, 1e18);
  cout << fixed << setprecision(4) << ans << "\n";
  return 0;
}
