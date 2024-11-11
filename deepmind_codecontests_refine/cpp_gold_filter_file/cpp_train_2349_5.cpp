#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b;
  cin >> a >> b;
  vector<int> v;
  int d = b;
  int f = 0;
  while (d > 0) {
    int c = d % 10;
    v.push_back(d);
    if (c == 3 || c == 5 || c == 7 || c == 9) {
      if (d == a) {
        cout << "YES"
             << "\n";
        cout << v.size() << "\n";
        for (int i = v.size() - 1; i >= 0; i--) cout << v[i] << " ";
        f = 1;
        break;
      } else
        break;
    } else if (c == 1) {
      if (d == a) {
        cout << "YES"
             << "\n";
        cout << v.size() << "\n";
        for (int i = v.size() - 1; i >= 0; i--) cout << v[i] << " ";
        f = 1;
        break;
      } else
        d = d / 10;
    } else {
      if (d == a) {
        cout << "YES"
             << "\n";
        cout << v.size() << "\n";
        for (int i = v.size() - 1; i >= 0; i--) cout << v[i] << " ";
        f = 1;
        break;
      } else
        d = d / 2;
    }
  }
  if (f == 0) cout << "NO";
  return 0;
}
