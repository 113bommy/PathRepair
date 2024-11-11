#include <bits/stdc++.h>
using namespace std;
int ans = 0;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  if (n == 1) {
    cout << 1;
    return 0;
  }
  int sum = 0, sum2 = 0;
  int x[n];
  for (int i = 0; i < n; ++i) {
    cin >> x[i];
    sum += x[i];
  }
  for (int i = 0; i < n; ++i) {
    if (sum2 >= sum / 2) {
      ans = i;
      break;
    } else {
      sum2 += x[i];
    }
  }
  if (ans == 0) {
    cout << n;
    return 0;
  }
  cout << ans;
  return 0;
}
