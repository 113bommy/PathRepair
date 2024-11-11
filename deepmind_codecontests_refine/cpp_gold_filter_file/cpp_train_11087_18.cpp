#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long int n, arr[100005] = {}, ans[100005] = {};
  cin >> n;
  long long int mx = -1e9;
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  for (int i = n - 1; i >= 0; i--) {
    if (i == n - 1) {
      ans[i] = 0;
    } else {
      ans[i] = max(0LL, (mx + 1 - arr[i]));
    }
    mx = max(mx, arr[i]);
  }
  for (int i = 0; i < n; i++) {
    if (i != 0) cout << " ";
    cout << ans[i];
  }
  cout << endl;
  return 0;
}
