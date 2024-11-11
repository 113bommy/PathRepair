#include <bits/stdc++.h>
using namespace std;
stack<long long int> st;
long long int binarySearch(long long int l, long long int r, long long int a[],
                           long long int k) {
  if (l <= r) {
    long long int mid = l + (r - l) / 2;
    if (a[mid] == k)
      return mid;
    else if (a[mid] > k)
      return binarySearch(l, mid - 1, a, k);
    else
      return binarySearch(mid + 1, r, a, k);
  } else
    return -1;
}
void solve() {
  long long int n, s;
  cin >> n >> s;
  long long int a[n];
  long long int sum = 0;
  for (long long int i = 0; i < n; i++) {
    cin >> a[i];
    sum += a[i];
  }
  long long int v = *min_element(a, a + n);
  if (sum <= s)
    cout << "-1";
  else {
    for (long long int i = 0; i < n; i++) {
      s -= a[i] - v;
    }
    if (s <= 0)
      cout << v;
    else
      cout << v - (s + n - 1) / n;
  }
  return;
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int t = 1;
  while (t--) {
    solve();
  }
  return 0;
}
