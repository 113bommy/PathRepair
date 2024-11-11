#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int arr[n], mx = -1, sum = 0, sum1 = 0;
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
    mx = max(mx, arr[i]);
    sum += arr[i];
  }
  for (int i = 0; i < n; i++) {
    arr[i] = mx - arr[i];
    sum1 += arr[i];
  }
  int ans = mx;
  while (sum1 > sum) {
    ans++;
    sum1 += n;
  }
  cout << ans << endl;
  return 0;
}
