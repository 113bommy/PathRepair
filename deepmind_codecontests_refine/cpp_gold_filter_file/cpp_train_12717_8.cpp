#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
const long long int INF = 1e12;
const int N = 1e5 + 1;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n, m;
  cin >> n >> m;
  int arr[n];
  for (int i = 0; i < n; i++) cin >> arr[i];
  long long int low = 0, high = 1LL * n * m, ans = 0;
  while (low <= high) {
    long long int mid = (low + high) / 2;
    bool valid = 1;
    int prev = 0;
    for (int i = 0; i < n; i++) {
      if (arr[i] == prev) continue;
      if (arr[i] < prev) {
        if (prev - arr[i] > mid) {
          valid = 0;
          break;
        }
      } else if (prev + m - arr[i] > mid)
        prev = arr[i];
    }
    if (valid)
      ans = mid, high = mid - 1;
    else
      low = mid + 1;
  }
  cout << ans;
  return 0;
}
