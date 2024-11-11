#include <bits/stdc++.h>
using namespace std;
int main() {
  long t;
  cin >> t;
  while (t--) {
    long n;
    cin >> n;
    int arr[n][n];
    for (int row = 0; row < n; row++) {
      for (int col = 0; col < n; col++) {
        char c;
        cin >> c;
        arr[row][col] = c - '0';
      }
    }
    int flag(0);
    for (int row = 0; row < n - 1; row++) {
      for (int col = 0; col < n - 1; col++) {
        if (arr[row][col] && (!arr[row + 1][col] || !arr[row][col + 1])) {
          flag = 1;
          break;
        }
      }
    }
    if (flag) {
      cout << "NO" << '\n';
    } else {
      cout << "YES" << '\n';
    }
  }
  return 0;
}
