#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  vector<int> cur(10, 0);
  while (n--) {
    char c;
    cin >> c;
    if ('0' <= c && c <= '9') {
      cur[c - '0'] = 0;
    } else if (c == 'L') {
      for (int i = 0; i < 10; i++) {
        if (cur[i] == 0) {
          cur[i] = 1;
          break;
        }
      }
    } else {
      for (int i = 9; i >= 0; i--) {
        if (cur[i] == 0) {
          cur[i] = 1;
          break;
        }
      }
    }
  }
  for (int i : cur) {
    cout << i;
  }
  cout << '\n';
  return 0;
}
