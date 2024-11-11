#include <bits/stdc++.h>
using namespace std;
string n, cur = "4";
int main() {
  cin >> n;
  for (int i = 1; i <= 2000; i++) {
    if (n == cur) {
      cout << i;
      break;
    }
    int change = 1;
    for (int i = (int)cur.size() - 1; i >= 0; i--) {
      if (cur[i] == '4' && change == 1) {
        cur[i] = '7';
        change = 0;
        break;
      }
      if (cur[i] == '7') {
        change = 1;
        cur[i] = '4';
      }
    }
    if (change == 1) {
      cur = '4' + cur;
    }
  }
  return 0;
}
