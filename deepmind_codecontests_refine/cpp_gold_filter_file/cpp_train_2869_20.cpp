#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    string a;
    cin >> a;
    if ((a.size()) > 10) {
      cout << a[0] << (a.size() - 2) << a[a.size() - 1] << endl;
    } else {
      cout << a << endl;
    }
  }
  return 0;
}
