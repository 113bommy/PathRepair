#include <bits/stdc++.h>
using namespace std;
int main() {
  int t, s, d;
  cin >> t;
  while (t--) {
    int count = 0;
    string a;
    cin >> a;
    s = a.size();
    d = s / 2;
    if (s % 2 == 1) {
      cout << "no1" << endl;
    } else {
      for (int i = 0; i < d; i++) {
        if (a[i] != a[i + d]) {
          count = 1;
          break;
        }
      }
      if (count == 1)
        cout << "no" << endl;
      else
        cout << "yes" << endl;
    }
  }
}
