#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  int arr[10] = {0};
  for (int i = 0; i < n; i++) {
    if (s[i] == 'L') {
      for (int j = 0; j < 10; j++) {
        if (arr[j] == 0) {
          arr[j] = 1;
          break;
        }
      }
    } else if (s[i] == 'R') {
      for (int j = 9; j >= 0; j--) {
        if (arr[j] == 0) {
          arr[j] = 1;
          break;
        }
      }
    } else {
      arr[s[i] - 48] = 0;
    }
  }
  for (int j = 0; j < 10; j++) {
    cout << arr[j] << endl;
  }
  return 0;
}
