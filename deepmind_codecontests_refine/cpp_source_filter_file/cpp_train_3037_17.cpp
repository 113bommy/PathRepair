#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  long long arr[n];
  cin >> arr[0];
  for (int i = 1; i < n; i++) {
    cin >> arr[i];
    arr[i] += arr[i - 1];
  }
  int q;
  cin >> q;
  while (q) {
    q--;
    int l, r;
    int ans;
    cin >> l >> r;
    if (l == 1) {
      ans = (int)((arr[r - 1]) / 10);
    } else {
      ans = (int)((arr[r - 1] - arr[l - 1]) / 10);
    }
    cout << ans << endl;
  }
  return 0;
}
