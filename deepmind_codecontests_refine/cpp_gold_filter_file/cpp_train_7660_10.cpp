#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int n;
  cin >> n;
  long long int arr[n];
  vector<long long int> a2;
  for (long long int i = 0; i < n; i++) {
    cin >> arr[i];
    if (arr[i] == 0) {
      a2.push_back(i);
    }
  }
  vector<long long int> ans(n, (int)1e9);
  for (long long int i = 0; i < n; i++) {
    if (arr[i] == 0) {
      ans[i] = 0;
    } else if (ans[i - 1] != (int)1e9) {
      ans[i] = 1 + ans[i - 1];
    }
  }
  for (long long int i = n - 2; i >= 0; i--) {
    ans[i] = min(ans[i + 1] + 1, ans[i]);
  }
  for (long long int i = 0; i < n; i++) {
    cout << ans[i] << " ";
  }
  return 0;
}
