#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;
const long long infi = INT_MAX;
const long long infll = LLONG_MAX;
const long double PI = 3.1415926535897932384626;
void solve(long long test_case) {
  long long n, a, b;
  cin >> n >> a >> b;
  if (a + b + 2 > n) {
    cout << -1 << "\n";
    return;
  }
  if (abs(a - b) > 1) {
    cout << -1 << "\n";
    return;
  }
  vector<long long> arr(n);
  for (long long i = 0; i < n; i++) arr[i] = i + 1;
  if (a > b) {
    for (long long i = n - 1; i - 1 >= 0; i -= 2) {
      swap(arr[i], arr[i - 1]);
      if (--a == 0) break;
    }
  } else if (b > a) {
    for (long long i = 0; i + 1 < n; i += 2) {
      swap(arr[i], arr[i + 1]);
      if (--b == 0) break;
    }
  } else {
    for (long long i = 1; i + 1 < n; i += 2) {
      if (a == 0) break;
      swap(arr[i], arr[i + 1]);
      a--;
    }
  }
  for (auto x : arr) cout << x << " ";
  cout << "\n";
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ios_base ::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long tc = 1;
  cin >> tc;
  while (tc--) solve(tc);
  return 0;
}
