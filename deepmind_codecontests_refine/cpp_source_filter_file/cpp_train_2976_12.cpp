#include <bits/stdc++.h>
using namespace std;
long long const mod = 1000000000 + 7;
bool ifprime(long long n) {
  if (n == 1) return false;
  long long i;
  for (i = 2; i * i <= n; i++) {
    if (n % i == 0) return false;
  }
  return true;
}
long long fast_expo(long long n, long long m) {
  if (m == 1) return n % mod;
  long long ans = fast_expo(n, m / 2);
  ans = (ans * ans) % mod;
  if (m & 1) return (ans * n) % mod;
  return ans;
}
long long invMod(long long a) { return fast_expo(a, mod - 2); }
int main() {
  ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
  cout << fixed << setprecision(10);
  vector<pair<double, double>> v;
  vector<double> prefix_a;
  double n, p, a, b;
  double time_gone = 0;
  cin >> n >> p;
  for (long long i = 0; i < n; i++) {
    cin >> a >> b;
    v.push_back(make_pair(b / a, a));
  }
  sort(v.begin(), v.end());
  prefix_a.push_back(v[0].second);
  for (long long i = 1; i < n; i++)
    prefix_a.push_back(prefix_a[i - 1] + v[i].second);
  if (prefix_a[n - 1] <= p) {
    cout << -1 << endl;
    return 0;
  }
  for (long long i = 1; i < n; i++) {
    double eq_time = (prefix_a[i - 1] / p) * (v[i].first - v[i - 1].first);
    double allowed_time = 0;
    if (prefix_a[i - 1] == p)
      allowed_time = eq_time + 1;
    else
      allowed_time = (prefix_a[i - 1] * (v[i - 1].first - time_gone)) /
                     (prefix_a[i - 1] - p);
    if (allowed_time < eq_time) {
      cout << allowed_time + time_gone << endl;
      return 0;
    }
    time_gone += eq_time;
  }
  time_gone +=
      (prefix_a[n - 1] * (v[n - 1].first - time_gone)) / (prefix_a[n - 1] - p);
  cout << time_gone << endl;
  return 0;
}
