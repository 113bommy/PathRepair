#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long n, p, k;
  cin >> n >> p >> k;
  vector<long long> arr;
  long long a;
  for (long long i = 0; i < n; i++) {
    cin >> a;
    arr.push_back(a);
  }
  sort(arr.begin(), arr.end());
  long long arr2[n];
  arr2[0] = arr[0];
  for (long long i = 1; i < k - 1; i++) {
    arr2[i] = arr[i] + arr[i - 1];
  }
  arr2[k - 1] = arr[k - 1];
  for (long long i = k; i < n; i++) {
    arr2[i] = arr[i] + arr2[i - k];
  }
  for (long long i = 0; i < n; i++) {
  }
  for (long long i = n - 1; i >= 0; i--) {
    if (p >= arr2[i]) {
      cout << i + 1;
      return;
    }
  }
  cout << 0;
}
const long long mod = 1e9 + 7;
int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  cin.exceptions(cin.failbit);
  long long t = 1;
  cin >> t;
  while (t--) {
    solve();
    cout << endl;
  }
  return 0;
}
