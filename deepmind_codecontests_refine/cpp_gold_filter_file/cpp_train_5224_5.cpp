#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int arr[10];
  string s;
  cin >> s;
  for (int i = 0; i < 10; i++) {
    arr[i] = 0;
  }
  int count = 0;
  for (int i = 0; i < n; i++) {
    if (s[i] == 'L') {
      count = 0;
      for (int j = 0; j < 10; j++) {
        if (arr[j] == 0) {
          count++;
          arr[j] = 1;
          if (count == 1) {
            break;
          }
        }
      }
    } else if (s[i] == 'R') {
      count = 0;
      for (int j = 9; j >= 0; j--) {
        if (arr[j] == 0) {
          arr[j] = 1;
          count = 1;
          if (count == 1) {
            break;
          }
        }
      }
    } else {
      int room = int(s[i]) - 48;
      arr[room] = 0;
    }
  }
  for (int i = 0; i < 10; i++) {
    cout << arr[i];
  }
  return 0;
}
