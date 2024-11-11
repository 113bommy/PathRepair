#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) cin >> arr[i];
    int temp = arr[0];
    for (int i = 0; i < n; i++) {
      if (temp != arr[i]) {
        temp = -1;
        break;
      }
    }
    if (temp != -1) {
      cout << 1 << endl;
      for (int i = 0; i < n; i++) cout << 1 << " ";
      cout << endl;
    }
    if (temp == -1) {
      if (n % 2 == 0) {
        cout << 2 << endl;
        for (int i = 0; i < n / 2; i++) cout << 1 << " " << 2 << " ";
        cout << endl;
      }
      if (n % 2 == 1) {
        int conf = 0;
        int ans[n];
        int res = 2;
        int cond = 1;
        ans[0] = 1;
        for (int i = 1; i < n; i++) {
          if (arr[i] == arr[i - 1]) {
            ans[i] = cond;
            conf = 1;
          }
          if (arr[i] != arr[i - 1]) {
            if (cond == 1)
              cond = 0;
            else
              cond = 1;
            ans[i] = cond;
          }
        }
        if (arr[n - 1] != arr[0])
          if (ans[0] == ans[n - 1]) {
            if (conf == 0) {
              res = 3;
              ans[n - 1] = 2;
            }
            if (conf == 1) {
              int index = n - 1;
              while (arr[index] != arr[index - 1]) index--;
              for (int j = index; j < n; j++) {
                if (ans[j] == 1)
                  ans[j] = 2;
                else
                  ans[j] = 1;
              }
            }
          }
        cout << res << endl;
        for (int i = 0; i < n; i++) cout << ans[i] + 1 << " ";
        cout << endl;
      }
    }
  }
}
