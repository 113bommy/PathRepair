#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int arr[n];
    int i = 0;
    for (i = 0; i < n; i++) {
      cin >> arr[i];
    }
    i = 1;
    bool flag = true;
    for (i = 1; i < n; i++) {
      if (arr[i] != arr[i - 1]) {
        cout << 1 << endl;
        flag = false;
        break;
      }
    }
    if (flag) cout << n << endl;
  }
}
