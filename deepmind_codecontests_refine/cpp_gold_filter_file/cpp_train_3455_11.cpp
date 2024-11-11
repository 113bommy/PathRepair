#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k;
  cin >> n >> k;
  string a;
  cin >> a;
  if (k == 0)
    cout << a << endl;
  else if (n == 1)
    cout << 0 << endl;
  else {
    int s = 0;
    if (a[0] != '1') {
      a[0] = '1';
      s++;
    }
    for (int i = 1; i < n; i++) {
      if (s == k)
        break;
      else if (a[i] != '0') {
        a[i] = '0';
        s++;
      }
    }
    cout << a << endl;
  }
  return 0;
}
