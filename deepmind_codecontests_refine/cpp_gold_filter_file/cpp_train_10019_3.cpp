#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int arr[n + 2];
    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      arr[x] = i + 1;
    }
    if (n == 1) {
      cout << "Yes" << endl;
    } else {
      bool chk = 0;
      for (int i = 2; i <= n; i++) {
        int d = arr[i] - arr[i - 1];
        if (d < 0) {
          continue;
        } else {
          if (d > 1) {
            chk = 1;
            break;
          }
        }
      }
      if (chk)
        cout << "No" << endl;
      else
        cout << "Yes" << endl;
    }
  }
  return 0;
}
