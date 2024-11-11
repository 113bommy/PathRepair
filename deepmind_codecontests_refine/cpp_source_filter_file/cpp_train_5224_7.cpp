#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, ans[10];
  char data[100005];
  for (int i = 0; i < 10; i++) {
    ans[i] = 0;
  }
  cin >> n >> data;
  for (int i = 0; i < n; i++) {
    if (data[i] == 'L') {
      for (int j = 0; j < 10; j++) {
        if (ans[j] == 0) {
          ans[j] = 1;
          break;
        }
      }
    } else if (data[i] == 'R') {
      for (int j = 9; j >= 0; j--) {
        if (ans[j] == 0) {
          ans[j] = 1;
          break;
        }
      }
    } else {
      ans[data[i] - '0'] = 0;
    }
  }
  for (int i = 0; i < 9; i++) {
    cout << ans[i];
  }
  return 0;
}
