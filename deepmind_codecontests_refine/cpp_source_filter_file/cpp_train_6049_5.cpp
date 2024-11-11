#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, a, b;
  cin >> n >> a >> b;
  int val[2] = {a, b};
  int arr[n];
  for (int i = 0; i < n; ++i) {
    cin >> arr[i];
  }
  int ans = 0;
  int buy = min(a, b);
  for (int i = 0; i < n / 2; ++i) {
    if (arr[i] == arr[n - i - 1] && arr[i] != 2) {
      continue;
    }
    if (arr[i] = !arr[n - i - 1] && arr[i] != 2 && arr[n - i - 1] != 2) {
      ans = -123534543;
    }
    if (arr[i] == 2) {
      if (arr[n - i - 1] == 2) {
        ans += 2 * buy;
        continue;
      } else {
        ans += val[arr[n - i - 1]];
      }
    } else if (arr[n - i - 1] == 2) {
      if (arr[i] == 2) {
        ans += 2 * buy;
      } else {
        ans += val[arr[i]];
      }
    }
  }
  if (n % 2 == 1) {
    if (arr[n / 2] == 2) {
      ans += buy;
    }
  }
  if (ans < 0) {
    ans = -1;
  }
  cout << ans << endl;
  return 0;
}
