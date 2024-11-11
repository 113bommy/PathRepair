#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int t;
  cin >> t;
  while (t--) {
    bool flag = false;
    int count = 0;
    long long int n;
    cin >> n;
    long long int a[n];
    for (long long int i = 0; i < n; i++) {
      cin >> a[i];
    }
    int mx = *max_element(a, a + n);
    long long int idx = 0;
    long long int lst_idx = 0;
    for (int i = 0; i < n; i++) {
      if (a[i] == mx) {
        if (i == 0) {
          if (a[i] < a[i + 1]) {
            cout << i + 1 << endl;
            flag = true;
            break;
          }
        } else if (i == n - 1) {
          if (a[i - 1] < a[i]) {
            cout << i + 1 << endl;
            flag = true;
            break;
          }
        } else if (a[i + 1] < a[i] or a[i - 1] < a[i]) {
          cout << i + 1 << endl;
          flag = true;
          break;
        }
      }
    }
    if (flag == false) {
      cout << -1 << endl;
    }
  }
}
