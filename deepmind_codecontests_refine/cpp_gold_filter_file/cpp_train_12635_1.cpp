#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, k;
  cin >> n >> k;
  int arr[n];
  for (int i = 0; i < n; i++) cin >> arr[i];
  int i = 0;
  while (k) {
    if (arr[i] < 0)
      arr[i] = -arr[i];
    else
      break;
    i++;
    k--;
  }
  sort(arr, arr + n);
  if (k > 0 && k % 2 == 1) arr[0] -= 2 * arr[0];
  int ans = 0;
  for (i = 0; i < n; i++) ans += arr[i];
  cout << ans << endl;
}
