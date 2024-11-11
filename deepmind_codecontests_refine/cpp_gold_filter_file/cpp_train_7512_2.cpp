#include <bits/stdc++.h>
using namespace std;
int main() {
  long long ans = 0;
  int n, k, x, m, i;
  cin >> n >> k;
  long long arr[n], a[n];
  cin >> a[0];
  for (i = 1; i < n; i++) {
    cin >> a[i];
    arr[i - 1] = a[i] - a[i - 1];
  }
  sort(arr, arr + n - 1);
  if (k == n) return puts("0"), 0;
  if (k == 1) return cout << (a[n - 1] - a[0]) << endl, 0;
  for (i = 0; i < n - k; i++) {
    ans += arr[i];
  }
  cout << ans << endl;
}
