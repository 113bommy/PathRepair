#include <bits/stdc++.h>
using namespace std;
int BinSearch(vector<int> &arr, int val, int n) {
  int lo = 0;
  int hi = n - 1;
  int ans = -1;
  while (lo <= hi) {
    int mid = (lo + hi) / 2;
    if (arr[mid] <= val) {
      ans = mid;
      lo = mid + 1;
    } else {
      hi = mid - 1;
    }
  }
  return ans;
}
int main() {
  int n, d;
  cin >> n >> d;
  vector<int> arr(n);
  for (int i = 0; i < n; i++) cin >> arr[i];
  long long ans = 0;
  for (int i = 0; i < n; i++) {
    int val = arr[i] + d;
    int idx = BinSearch(arr, val, n);
    if (idx == -1) continue;
    int num = idx - i - 1;
    if (num > 0) {
      ans += (num + 1) * num / 2;
    }
  }
  cout << ans << endl;
}
