#include <bits/stdc++.h>
using namespace std;
int arr[200000] = {0};
int ans[200000] = {0};
int main() {
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) cin >> arr[i];
  sort(arr, arr + n + 1);
  int j = 0, i = 1;
  bool fl = true;
  while (m > 0 && fl) {
    for (int l = arr[i - 1] + 1; l < (arr[i] == 0 ? INT_MAX : arr[i]); ++l) {
      if (l > m) {
        fl = false;
        break;
      }
      ans[j++] = l;
      m -= l;
    }
    ++i;
  }
  cout << j << endl;
  for (int i = 0; i < j; ++i) cout << ans[i] << ' ';
  return 0;
}
