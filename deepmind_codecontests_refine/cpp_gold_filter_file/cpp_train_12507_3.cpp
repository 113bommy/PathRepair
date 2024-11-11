#include <bits/stdc++.h>
using namespace std;
const long long N = 101;
long long n;
pair<long long, long long> a[N];
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for (long long i = 0; i < n; ++i) cin >> a[i].first >> a[i].second;
  long long p;
  cin >> p;
  for (long long i = n - 1; i >= 0; --i) {
    if (a[i].first <= p) {
      cout << n - i << '\n';
      exit(0);
    }
  }
}
