#include <bits/stdc++.h>
using namespace std;
int main() {
  int x;
  cin >> x;
  int n = 0;
  int t = 0;
  if (x == 1) {
    cout << "1" << endl;
    return 0;
  }
  if (x == 3) {
    cout << "5" << endl;
    return 0;
  }
  for (int i = 3;; i += 2) {
    t = i * i / 2 + 1;
    if (x <= t) {
      n = i;
      break;
    }
  }
  cout << n << endl;
  return 0;
}
