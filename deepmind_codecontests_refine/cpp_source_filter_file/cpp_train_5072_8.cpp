#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k;
  cin >> n >> k;
  int arr[n];
  for (int i = 0; i < n; i++) cin >> arr[i];
  int arr2[n];
  if (arr[0] % 2 == 1)
    arr2[0] = -1;
  else
    arr2[0] = 1;
  for (int i = 1; i < n; i++) {
    if (arr[i] % 2 == 0)
      arr2[i] = arr2[i - 1] + 1;
    else
      arr2[i] = arr2[i - 1] - 1;
  }
  vector<int> v;
  for (int i = 0; i < n; i++) {
    if (arr2[i] == 0 && i != n - 1) {
      v.push_back(abs(arr[i] - arr[i + 1]));
    }
  }
  if (v.size() == 0) {
    cout << 0 << endl;
    return 0;
  }
  sort(v.begin(), v.end());
  int i = 0;
  int ans = 0;
  while (k > 0 && i < v.size()) {
    if (k > v[i]) {
      k -= v[i];
      ans++;
      i++;
    } else
      break;
  }
  cout << ans << endl;
  return 0;
}
