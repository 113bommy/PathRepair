#include <bits/stdc++.h>
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
int dxx[8] = {0, 0, 1, -1, -1, -1, 1, 1};
int dyy[8] = {1, -1, 0, 0, -1, 1, 1, -1};
using namespace std;
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n;
  int arr[n];
  for (long long int i = 0; i < n; i++) cin >> arr[i];
  for (long long int i = 0; i < n - 1; i++) {
    if ((arr[i] == 2 && arr[i + 1] == 3) || (arr[i] == 3 && arr[i + 1] == 2)) {
      cout << "Infinite";
      return 0;
    }
  }
  long long int ans = 0;
  int prev = arr[0];
  for (long long int i = 1; i < n; i++) {
    if (arr[i] == 1) {
      if (prev == 2)
        ans += 3;
      else if (prev == 3)
        ans += 4;
    } else if (arr[i] == 2) {
      if (i - 2 >= 0) {
        if (arr[i - 2] == 3)
          ans += 0;
        else
          ans += 3;
      } else {
        if (prev == 1) ans += 3;
      }
    } else if (arr[i] == 3) {
      if (prev == 1) ans += 4;
    }
    prev = arr[i];
  }
  cout << "Finite" << endl << ans;
  return 0;
}
