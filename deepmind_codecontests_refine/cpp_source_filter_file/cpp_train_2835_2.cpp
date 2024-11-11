#include <bits/stdc++.h>
using namespace std;
int main() {
  int T;
  cin >> T;
  while (T--) {
    int n, arr[103];
    cin >> n;
    for (int i = 0; i < n; i++) {
      cin >> arr[i];
    }
    sort(arr, arr + n);
    int num = arr[0];
    if (n == 1) {
      cout << "YES\n";
    } else {
      for (int i = 1; i <= num; i++) {
        for (int j = 0; j < n; j++) {
          arr[j] -= 1;
        }
      }
      int point = 0;
      for (int j = 0; j < n; j++) {
        if (arr[j] == 0 || arr[j] == 2) {
          point++;
        }
      }
      if (point == n) {
        cout << "YES\n";
      } else {
        cout << "NO\n";
      }
    }
  }
}
