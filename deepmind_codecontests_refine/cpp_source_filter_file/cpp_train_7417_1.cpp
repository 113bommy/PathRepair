#include <bits/stdc++.h>
using namespace std;
int main() {
  int t, i;
  std::cin;
  cin >> t;
  while (t--) {
    string a;
    cin >> a;
    if (a.length() == 2) {
      cout << a << endl;
      continue;
    }
    string b = "";
    b += a[0];
    b += a[1];
    for (i = 3; i < a.size(); i += 2) {
      b = b + a[i];
    }
    cout << b;
  }
  return 0;
}
