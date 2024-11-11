#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int arr[n];
  for (int i = 0; i < n; ++i) cin >> arr[i];
  ;
  int ans = 9999999;
  for (int i = 0; i < n; i++) {
    int tmp = arr[i];
    for (int j = i + 1; j != i; j = (j + 1) % n) {
      ans = min(ans, abs(tmp - (360 - tmp)));
      tmp += arr[j];
    }
    ans = min(ans, abs(tmp - (360 - tmp)));
  }
  cout << ans;
  return 0;
}
