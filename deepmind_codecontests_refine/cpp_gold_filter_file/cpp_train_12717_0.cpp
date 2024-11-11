#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n, m;
  cin >> n >> m;
  int arr[n];
  for (int i = 0; i < n; i++) cin >> arr[i];
  int start = 0, end = m;
  int ans;
  while (start <= end) {
    int mid = (start + end) / 2;
    int min;
    if (m - arr[0] <= mid)
      min = 0;
    else
      min = arr[0];
    int flag = 0;
    for (int i = 1; i < n; i++) {
      if (arr[i] < min && min - arr[i] <= mid) continue;
      if (arr[i] < min && min - arr[i] > mid) {
        flag = 1;
        break;
      }
      if (arr[i] == min) continue;
      if (arr[i] > min && min + m - arr[i] <= mid) continue;
      if (arr[i] > min) min = arr[i];
    }
    if (flag == 1) {
      start = mid + 1;
    } else {
      ans = mid;
      end = mid - 1;
    }
  }
  cout << ans;
  return 0;
}
