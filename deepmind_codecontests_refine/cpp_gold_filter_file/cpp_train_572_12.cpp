#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, c;
  cin >> a >> b >> c;
  if (a > b) swap(a, b);
  bool chk = false;
  for (int i = 0;; i++) {
    if (a * i <= c) {
      int temp = c - (a * i);
      if (temp % b == 0) {
        chk = true;
        break;
      }
    } else
      break;
  }
  if (chk == true)
    cout << "YES";
  else
    cout << "NO";
  return 0;
}
