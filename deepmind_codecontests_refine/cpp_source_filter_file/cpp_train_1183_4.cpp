#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k, x = 0, y = 0;
  cin >> n >> k;
  vector<int> arr(n);
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  sort(arr.begin(), arr.end());
  if (n > k) {
    y = x = arr[n - k];
    cout << x << " " << y;
  } else {
    cout << "-1";
  }
  return 0;
}
