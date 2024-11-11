#include <bits/stdc++.h>
using namespace std;
int main() {
  string str[1003];
  int n, cnt = 0, Max = INT_MIN;
  cin >> n;
  if (n == 1) {
    cin >> str[0];
    for (int i = 0; i < 7; i++) {
      if (str[0][i] == '1') {
        cout << 1 << endl;
        return 0;
      }
    }
    cout << 0 << endl;
  } else {
    for (int i = 0; i < n; i++) {
      cin >> str[i];
    }
    for (int i = 0; i < 7; i++) {
      cnt = 0;
      for (int j = 0; j < n; j++) {
        if (str[j][i] == '1') cnt++;
      }
      if (cnt > Max) Max = cnt;
    }
    cout << Max << endl;
  }
  return 0;
}
