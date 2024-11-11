#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n;
  cin >> n;
  string s;
  cin >> s;
  long long rooms[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
  for (int i = 0; i < n; ++i) {
    if (s[i] == 'L') {
      for (int j = 0; j < 10; ++j) {
        if (rooms[j] == 0) {
          rooms[j] = 1;
          break;
        }
      }
    } else if (s[i] == 'R') {
      for (int j = 9; j >= 0; --j) {
        if (rooms[j] == 0) {
          rooms[j] = 1;
          break;
        }
      }
    } else {
      rooms[s[i] - '0'] = 0;
    }
  }
  for (int i = 0; i < 10; ++i) {
    cout << rooms[i];
  }
  cout << endl;
}
