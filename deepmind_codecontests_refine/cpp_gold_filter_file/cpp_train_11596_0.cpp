#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9 + 23;
const int MOD = 1e9 + 9;
const int ARRS = 1e5 + 100;
int arr[ARRS];
map<int, bool> in;
int main() {
  ios_base::sync_with_stdio(0);
  int n, k;
  cin >> n >> k;
  for (int i = 0; i < n; ++i) {
    cin >> arr[i];
  }
  sort(arr, arr + n);
  int ans = 0;
  for (int i = 0; i < n; ++i) {
    if (arr[i] % k != 0 || !in[arr[i] / k]) {
      in[arr[i]] = true;
      ++ans;
    }
  }
  cout << ans << "\n";
  return 0;
}
