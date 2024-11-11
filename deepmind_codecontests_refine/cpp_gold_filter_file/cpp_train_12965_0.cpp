#include <bits/stdc++.h>
using namespace std;
int main() {
  long long l = 2, r = 100, a[101] = {0}, f = 0, cnt = 0;
  for (int i = 1; i <= 20; i++) {
    cout << l << "\n";
    a[l] = 1;
    string s;
    cin >> s;
    if (s == "yes") {
      cnt++;
      if (cnt == 2) {
        f = 1;
        cout << "composite" << endl;
        break;
      }
      while (a[l] != 0 && l <= 100) {
        l++;
      }
    } else {
      for (int j = 2; j <= 100; j++) {
        if (j % l == 0 && a[j] == 0) {
          a[j] = 1;
        }
      }
      while (a[l] != 0 && l <= 100) {
        l++;
      }
    }
    if (l >= 101) {
      break;
    }
  }
  if (f == 0) {
    cout << "prime" << endl;
  }
}
