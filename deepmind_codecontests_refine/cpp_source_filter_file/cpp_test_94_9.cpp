#include <bits/stdc++.h>
using namespace std;
const double Pi = acos(-1.0);
const long long dx[] = {0, 0, 1, -1};
const long long dy[] = {1, -1, 0, 0};
const long long N = (long long)1e6 + 17;
const long long M = (long long)2e3 + 69;
const long long inf = (long long)1e14 + 3;
const long long mod = (long long)1e9 + 7;
long long sq(long long x) { return x * x; }
long long t = 1, a[N];
void solve() {
  long long n, k, cnt = 0;
  cin >> n >> k;
  k++;
  for (long long i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (long long i = 2; i <= n; i++) {
    long long x = pow(10, a[i] - a[i - 1]) - 1;
    if (k >= x)
      k -= x, cnt += a[i] - a[i - 1];
    else
      break;
  }
  cout << k;
  while (cnt--) cout << 9;
  cout << "\n";
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
