#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];
    sort(arr.begin(), arr.end());
    bool flag = true;
    for (int i = 0; i < n - 1 && flag; i++) {
      if (arr[i + 1] - arr[i] > 1) {
        cout << "NO" << endl;
        flag = false;
      }
    }
    if (flag) cout << "YES" << endl;
  }
}
