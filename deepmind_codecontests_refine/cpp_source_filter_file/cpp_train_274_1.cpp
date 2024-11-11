#include <bits/stdc++.h>
using namespace std;
const int DIM = 200005;
int arr[DIM], cnt[DIM];
int main(void) {
  int n, k;
  cin >> n >> k;
  for (int i = 1; i <= n; ++i) {
    cin >> arr[i];
    ++cnt[arr[i]];
  }
  sort(arr + 1, arr + n + 1);
  int ans = n;
  for (int i = 2; i <= n; ++i)
    if (arr[i] > arr[i - 1] and arr[i] <= arr[i - 1] + k)
      ans -= cnt[arr[i - 1]];
  cout << ans;
  return 0;
}
