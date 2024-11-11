#include <bits/stdc++.h>
using namespace std;
int main() {
  int x, y, z;
  bool f = 0;
  vector<int> a, b;
  cin >> x >> y;
  for (int i = 0; i < x; i++) {
    cin >> z;
    a.push_back(z);
  }
  for (int i = 0; i < x; i++) {
    cin >> z;
    b.push_back(z);
  }
  if (a[0] == 0) {
    cout << "NO" << endl;
    return 0;
  }
  if (a[y - 1] == 0 && b[y - 1] == 0) {
    f = 1;
    cout << "NO" << endl;
  } else if (a[y - 1] == 1) {
    f = 1;
    cout << "YES" << endl;
  } else if (a[y - 1] == 0 && b[y - 1] == 1) {
    for (int i = y; i < x; i++) {
      if (a[i] == 1 && b[i] == 1) {
        cout << "YES" << endl;
        f = 1;
        break;
      }
    }
  }
  if (f == 0) {
    cout << "NO" << endl;
  }
  return 0;
}
