#include <bits/stdc++.h>
using namespace std;
const long long M = 1e9 + 7;
void inp(long long a[], long long n) {
  for (long long i = 0; i < n; i++) cin >> a[i];
}
void solve() {
  long long n, ans = 0;
  cin >> n;
  long long a[n];
  inp(a, n);
  map<long long, long long> m;
  for (long long i = 0; i < n; i++) m[a[i]]++;
  for (long long i = 0; i < n; i++) {
    for (long long j = 1; j < 30; j++) {
      long long k = pow(2, j) - a[i];
      ans = ans + m[k];
      if (k == a[i]) ans--;
    }
  }
  cout << ans / 2;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long t = 1;
  while (t--) solve();
}
