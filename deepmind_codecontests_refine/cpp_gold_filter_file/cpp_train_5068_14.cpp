#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, b, cnt = 0, cnt1 = 0, ans = 0;
  cin >> n >> b;
  int arr[n + 2];
  for (int i = 0; i < n; i++) cin >> arr[i];
  vector<int> v;
  for (int i = 0; i < n - 1; i++) {
    if (arr[i] % 2)
      cnt++;
    else
      cnt1++;
    if (cnt == cnt1) {
      int x = abs(arr[i] - arr[i + 1]);
      v.push_back(x);
    }
  }
  sort(v.begin(), v.end());
  for (int i = 0; i < v.size(); i++) {
    if (v[i] <= b) {
      ans++;
      b -= v[i];
    }
  }
  cout << ans << endl;
  return 0;
}
