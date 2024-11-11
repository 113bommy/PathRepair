#include <bits/stdc++.h>
using namespace std;
void runTest() {
  long long int n;
  cin >> n;
  long long int a[n];
  for (long long int i = 0; i < n; i++) cin >> a[i];
  if (n <= 2) {
    cout << n << "\n";
    return;
  }
  long long int left[n];
  long long int right[n];
  left[0] = 1;
  right[n - 1] = 1;
  for (long long int i = 1; i < n; i++) {
    if (a[i] > a[i - 1])
      left[i] = 1 + left[i - 1];
    else
      left[i] = 1;
  }
  for (long long int i = n - 2; i >= 0; i--) {
    if (a[i] < a[i + 1])
      right[i] = 1 + right[i + 1];
    else
      right[i] = 1;
  }
  long long int ans = 0;
  for (long long int i = 0; i < n; i++) {
    if (i == 0) {
      if (i + 1 < n)
        ans = max(ans, right[i + 1] + 1);
      else
        ans = max(ans, 1LL);
      continue;
    }
    if (i == n - 1) {
      if (i - 1 >= 0)
        ans = max(ans, left[i - 1] + 1);
      else
        ans = max(ans, 1LL);
      continue;
    }
    if (a[i - 1] < a[i + 1]) ans = max(ans, left[i - 1] + right[i + 1] + 1);
    ans = max(ans, right[i + 1] + 1);
    ans = max(ans, left[i - 1] + 1);
  }
  cout << ans << "\n";
}
int main() {
  int t = 1;
  while (t--) runTest();
  return 0;
}
