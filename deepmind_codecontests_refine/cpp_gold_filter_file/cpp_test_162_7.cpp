#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long int n;
  cin >> n;
  vector<long long int> vec(n);
  for (long long int i = 0; i < n; i++) {
    cin >> vec[i];
  }
  long long int left = 0, right = 1e10;
  long long int ans = 0;
  while (left <= right) {
    long long int mid = (left + right) / 2;
    bool cool = 1;
    vector<long long int> dummy = vec;
    for (long long int i = n - 1; i >= 2; i--) {
      long long int x = dummy[i];
      long long int y = dummy[i - 1];
      long long int z = dummy[i - 2];
      if (dummy[i] < mid) {
        cool = 0;
        break;
      }
      long long int extra = dummy[i] - mid;
      extra = min(extra, vec[i]);
      dummy[i] = mid;
      long long int remain = extra % 3;
      long long int v = extra / 3;
      dummy[i - 1] += v;
      dummy[i - 2] += 2 * v;
      remain = extra - 3 * v;
    }
    long long int val = *min_element(dummy.begin(), dummy.end());
    if (val < mid) {
      right = mid - 1;
    } else {
      left = mid + 1;
      ans = mid;
    }
  }
  cout << ans;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  long long int T = 1;
  cin >> T;
  for (int t = 1; t <= T; t++) {
    solve();
    cout << '\n';
  }
  return 0;
}
