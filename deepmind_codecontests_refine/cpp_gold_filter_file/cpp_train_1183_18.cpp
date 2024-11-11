#include <bits/stdc++.h>
using namespace std;
const long long infll = powl(2, 62) - 1;
const long double pi = 4.0 * atanl(1.0);
const long long mod = powl(10, 9) + 7;
int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cout << setprecision(10) << fixed;
  long long n, k;
  cin >> n >> k;
  vector<long long> arr(n);
  for (long long i = 0; i < (long long)(n); ++i) cin >> arr[i];
  sort((arr).rbegin(), (arr).rend());
  if (k > n) {
    cout << "-1\n";
    return 0;
  }
  --k;
  if (k + 1 < arr.size() && arr[k] == arr[k + 1]) {
    cout << "-1\n";
    return 0;
  }
  cout << arr[k] << ' ' << arr[k] << '\n';
  return 0;
}
