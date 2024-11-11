#include <bits/stdc++.h>
using namespace std;
int arr[1000006], n, r[1000006], c[1000006], l[1000005];
int main() {
  cin >> n;
  for (int i = 0; i < n; i++) cin >> arr[i];
  rotate(arr, max_element(arr, arr + n), arr + n);
  arr[n] = arr[0];
  for (int i = n - 1; i >= 0; i--) {
    r[i] = i + 1;
    while (r[i] < n && arr[r[i]] < arr[i]) r[i] = r[r[i]];
    if (arr[r[i]] == arr[i] && r[i] < n) {
      c[i] = c[r[i]] + 1;
      r[i] = r[r[i]];
    }
  }
  long long ans = 0;
  for (int i = 1; i < n; i++) {
    l[i] = i - 1;
    while (l[i] > 0 && arr[l[i]] < arr[i]) l[i] = l[l[i]];
    ans += c[i];
    if (arr[i] != arr[0]) {
      ans += 2;
      if (r[i] == n && l[i] == 0) ans--;
    }
  }
  ans += c[0];
  cout << ans << endl;
  return 0;
}
