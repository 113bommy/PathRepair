#include <bits/stdc++.h>
using namespace std;
int main() {
  string a;
  cin >> a;
  for (int i = 0; i < int(a.size() - 2); ++i) {
    char x = a[i], y = a[i + 1], z = a[i + 2];
    if (x != '.' && y != '.' && z != '.')
      if (x != y && x != z && y != z) {
        cout << "Yes" << endl;
        return 0;
      }
  }
  cout << "No" << endl;
  return 0;
}
