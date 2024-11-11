#include <bits/stdc++.h>
using namespace std;
int main() {
  cin.tie(0);
  std::ios::sync_with_stdio(false);
  long long n, x = -1, arr[6][6];
  cin >> n;
  for (int i = 0; i < 4; i++) {
    for (int k = 0; k < 4; k++) cin >> arr[i][k];
    if (arr[i][0] + arr[i][2] <= n) {
      x = i;
      arr[5][0] = arr[i][0];
      arr[5][1] = arr[i][2];
    }
    if (arr[i][0] + arr[i][3] <= n) {
      x = i;
      arr[5][0] = arr[i][0];
      arr[5][1] = arr[i][3];
    }
    if (arr[i][1] + arr[i][3] <= n) {
      x = i;
      arr[5][0] = arr[i][1];
      arr[5][1] = arr[i][3];
    }
    if (arr[i][1] + arr[i][2] <= n) {
      x = i;
      arr[5][0] = arr[i][1];
      arr[5][1] = arr[i][2];
    }
  }
  if (x != -1)
    cout << x + 1 << " " << arr[5][0] << " " << n - arr[5][0] << endl;
  else
    cout << x << endl;
  return 0;
}
