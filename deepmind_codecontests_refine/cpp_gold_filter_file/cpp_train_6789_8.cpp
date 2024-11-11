#include <bits/stdc++.h>
using namespace std;
int main() {
  int tt;
  cin >> tt;
  while (tt--) {
    long long l, r;
    cin >> l >> r;
    string str = to_string(r);
    int size1 = str.size();
    int f = 1;
    for (int i = 0; i < size1; i++) {
      if (str[i] != '9') {
        f = 0;
      }
    }
    if (f) {
      cout << l * (size1) << endl;
    } else {
      cout << l * (size1 - 1) << endl;
    }
  }
  return 0;
}
