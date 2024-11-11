#include <bits/stdc++.h>
using namespace std;
long long a[200005];
long long b[200005];
void solve() {
  long long n;
  cin >> n;
  long long c = 0, t, c1 = 0;
  cin >> t;
  for (long long i = 0; i < t; i++) {
    cin >> a[i];
  }
  for (long long i = 1; i < t; i++) {
    if (n - a[i] > 0) c += n - a[i];
  }
  cout << c;
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t = 1;
  for (int i = 1; i <= t; i++) solve();
  return 0;
}
