#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, sum_up = 0, sum_down = 0, o_u = 0, o_d = 0;
  cin >> n;
  int arr[n][2];
  for (int i = 0; i < n; i++) {
    cin >> arr[i][0] >> arr[i][1];
    sum_up += arr[i][0];
    sum_down += arr[i][1];
    if (arr[i][0] % 2 == 1 && arr[i][1] % 2 == 0) o_u++;
    if (arr[i][0] % 2 == 0 && arr[i][1] % 2 == 1) o_d++;
  }
  if (sum_up % 2 == 0 && sum_down % 2 == 0) {
    cout << 0;
  } else if (sum_up % 2 == 1 && sum_down % 2 == 0 ||
             sum_up % 2 == 0 && sum_down % 2 == 1)
    cout << -1;
  else if (sum_up % 2 == 1 && sum_down % 2 == 1) {
    if (o_u || o_d)
      cout << 1;
    else
      cout << -1;
  } else
    cout << -1;
  return 0;
}
