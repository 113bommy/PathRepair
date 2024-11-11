#include <bits/stdc++.h>
using namespace std;
int main() {
  int test;
  cin >> test;
  while (test--) {
    long long int n, x;
    cin >> n >> x;
    long long int arr[n];
    int i;
    for (i = 0; i < n; i++) cin >> arr[i];
    for (i = 0; i < n; i++) arr[i] = arr[i] % x;
    long long sumi = 0;
    for (i = 0; i < n; i++) sumi += arr[i];
    if (sumi % x) {
      cout << n << "\n";
      continue;
    }
    int f = n, l = -1;
    for (i = 0; i < n; i++) {
      if (arr[i] != 0) {
        f = i;
        break;
      }
    }
    for (i = n - 1; i >= 0; i--) {
      if (arr[i] != 0) {
        l = i;
        break;
      }
    }
    int a1 = n - f - 1;
    int a2 = l;
    int ans = max(a1, a2);
    cout << ans << "\n";
  }
}
