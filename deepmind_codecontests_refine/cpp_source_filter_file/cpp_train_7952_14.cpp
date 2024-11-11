#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long n, m;
  cin >> n >> m;
  long long ar[m];
  vector<pair<long long, long long> > v;
  vector<long long> v1;
  for (long long i = 0; i < m; i++) {
    long long a, b;
    cin >> a >> b;
    v.push_back({a, b});
    v1.push_back(a);
    v1.push_back(b);
  }
  sort(v1.begin(), v1.end());
  long long j = 0;
  for (long long i = 0; i < v1.size(); i++) {
    if (v1[i] != (i + 1)) {
      j = i + 1;
      break;
    }
  }
  cout << n - 1 << endl;
  for (long long i = 1; i <= n; i++) {
    if (i != j) cout << i << " " << j << endl;
  }
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long t = 1;
  while (t--) {
    solve();
  }
  return 0;
}
