#include <bits/stdc++.h>
using namespace std;
int n, m, k, arr[101];
int main() {
  int best1, best2;
  cin >> n >> m >> k;
  for (int i = 1; i <= n; i++) cin >> arr[i];
  for (int i = m - 1; i >= 1; i--) {
    if (arr[i] <= k && arr[i]) {
      best1 = abs((i - m)) * 10;
      break;
    }
  }
  for (int i = m + 1; i <= n; i++) {
    if (arr[i] <= k && arr[i]) {
      best2 = abs((i - m)) * 10;
      break;
    }
  }
  if (!best1)
    cout << best2 << endl;
  else if (!best2)
    cout << best1 << endl;
  else
    cout << min(best1, best2) << endl;
  return 0;
}
