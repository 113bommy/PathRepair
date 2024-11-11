#include <bits/stdc++.h>
using namespace std;
struct __timestamper {};
int main(void) {
  int n, f = 1;
  cin >> n;
  string st;
  cin >> st;
  for (int i = 0; i < n; i++) {
    for (int j = 1; j <= 99; j++) {
      f = 1;
      for (int k = 0; k <= 4; k++) {
        f &= (i + k * j < n && st[i + k * j] == '*');
      }
      if (f) {
        cout << "yes" << endl;
        return 0;
      }
    }
  }
  cout << "no" << endl;
  return 0;
}
