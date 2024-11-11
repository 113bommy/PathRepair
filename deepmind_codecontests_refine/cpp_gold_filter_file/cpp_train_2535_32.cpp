#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long n;
  cin >> n;
  if (n == 1)
    cout << 1;
  else {
    long long arr[n];
    for (long long i = 1; i <= n; ++i) arr[i] = i;
    for (long long i = 1; i <= n; ++i) swap(arr[i], arr[n]);
    for (long long i = 1; i <= n; ++i) cout << arr[i] << " ";
  }
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solve();
  return 0;
}
