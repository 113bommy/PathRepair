#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100;
int arr[MAXN + 10];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n, k;
  cin >> n >> k;
  for (int i = 0; i < n; i++) cin >> arr[i];
  sort(arr, arr + n);
  if (k == 0) {
    cout << arr[n - 1] << endl;
    return 0;
  }
  int ans = 0;
  for (int i = 1; i < k; i++) {
    arr[n - i] -= arr[n - i - 1];
    ans = arr[n - i - 1];
  }
  cout << ans << endl;
}
