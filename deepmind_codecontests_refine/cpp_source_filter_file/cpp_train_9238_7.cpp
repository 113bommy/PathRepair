#include <bits/stdc++.h>
using namespace std;
bool sortinrev(const pair<long long, long long> &a,
               const pair<long long, long long> &b) {
  return (a.first > b.first);
}
long long vis[101] = {0};
vector<long long> v[101];
map<long long, long long> mp;
long long ans = 0;
void solve() {
  long long n, vb, vc;
  cin >> n >> vb >> vc;
  long long a[n];
  for (long long i = 0; i < n; i++) cin >> a[i];
  long long x, y, min = 0;
  cin >> x >> y;
  double c, d, p, b[n];
  b[0] = 1000000000;
  for (long long i = 1; i < n; i++) {
    c = ((a[i] - a[i - 1]) * 1.0) / vb;
    double e = abs(a[i] - x);
    double f = abs(y - 0);
    double g = (pow(e, 2) + pow(f, 2)) * 1.0;
    d = (sqrt(g)) / vb;
    b[i] = c + d;
    if (b[i] <= b[min]) min = i;
  }
  cout << min + 1;
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long t = 1;
  while (t--) {
    solve();
  }
  return 0;
}
