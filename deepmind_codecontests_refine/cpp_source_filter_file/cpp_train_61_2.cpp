#include <bits/stdc++.h>
using namespace std;
int main() {
  string a;
  cin >> a;
  int n, c, d;
  cin >> n;
  string b;
  while (n--) {
    cin >> b;
    if (b == a) {
      c = 1;
      d = 1;
    }
    if (b[1] == a[0]) {
      d = 1;
    }
    if (b[0] == a[1]) {
      c = 1;
    }
  }
  if (c == 1 && d == 1) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
}
