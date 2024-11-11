#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  vector<long long> arr(n);
  for (int i = 0; i < n; i++) cin >> arr[i];
  for (int i = 0; i < n - 1; i++) {
    arr[i] = abs(arr[i] - arr[i + 1]);
  }
  vector<long long> a(n), b(n);
  a[0] = arr[0];
  long long ans1 = a[0], ans2 = 0;
  for (int i = 1; i < n - 1; i++) {
    if (i & 1) {
      a[i] = max(a[i - 1] + arr[i] * -1, arr[i] * -1);
    } else {
      a[i] = max(a[i - 1] + arr[i], arr[i]);
    }
    ans1 = max(ans1, a[i]);
  }
  b[0] = -1 * arr[0];
  ans2 = b[0];
  for (int i = 1; i < n - 1; i++) {
    if (i & 1) {
      a[i] = max(a[i - 1] + arr[i], arr[i]);
    } else {
      a[i] = max(a[i - 1] + arr[i] * -1, arr[i] * -1);
    }
    ans2 = max(ans2, b[i]);
  }
  cout << max(ans1, ans2);
}
