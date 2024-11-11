#include <bits/stdc++.h>
using namespace std;
int main() {
  string a;
  int n;
  cin >> n;
  for (int i = 0; i < n - 1; i++) {
    cin >> a;
    if (a.length() > 10) {
      cout << a[0] << a.length() - 2 << a[a.length() - 1] << endl;
    } else {
      cout << a << endl;
    }
  }
}
