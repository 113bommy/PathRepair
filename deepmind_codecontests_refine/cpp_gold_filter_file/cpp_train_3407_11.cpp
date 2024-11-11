#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;
const double PI = 2 * acos(0.0);
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long n;
  cin >> n;
  long long arr[n];
  for (long long i = 0; i < n; i++) {
    cin >> arr[i];
  }
  sort(arr, arr + n);
  vector<long long> ans = {arr[0]};
  for (long long i = 1; i < n; i++) {
    for (long long j = 0; j <= 31; j++) {
      long long l_val = arr[i] - (1 << j);
      long long u_val = arr[i] + (1 << j);
      bool l_found = binary_search(arr, arr + i, l_val);
      bool u_found = binary_search(arr + i + 1, arr + n, u_val);
      if (l_found && u_found) {
        ans = {l_val, arr[i], u_val};
      } else if (ans.size() < 3) {
        if (l_found) {
          ans = {l_val, arr[i]};
        } else if (u_found) {
          ans = {arr[i], u_val};
        }
      }
    }
  }
  cout << ans.size() << "\n";
  for (auto val : ans) {
    cout << val << " ";
  }
  cout << "\n";
  return 0;
}
