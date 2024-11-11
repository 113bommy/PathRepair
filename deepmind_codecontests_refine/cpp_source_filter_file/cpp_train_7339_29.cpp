#include <bits/stdc++.h>
using namespace std;
const int N = 500005;
int main() {
  string arr[10];
  for (int i = 0; i < 8; i++) cin >> arr[i];
  int ans1 = INT_MAX, ans2 = INT_MAX;
  for (int j = 0; j < 8; j++) {
    for (int i = 0; i < 8; i++) {
      if (arr[i][j] == 'B') break;
      if (arr[i][j] == 'W') {
        ans1 = min(ans1, (i));
        break;
      }
    }
  }
  for (int j = 0; j < 8; j++) {
    for (int i = 7; i >= 0; i--) {
      if (arr[i][j] == 'W') break;
      if (arr[i][j] == 'B') {
        ans2 = min(ans2, 8 - i - 1);
        break;
      }
    }
  }
  if (ans1 < ans2) {
    cout << "A" << endl;
  } else {
    cout << "B" << endl;
  }
}
