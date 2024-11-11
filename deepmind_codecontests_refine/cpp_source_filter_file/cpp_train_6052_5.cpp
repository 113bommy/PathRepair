#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  cin >> s;
  long long int n = s.size();
  long long int h = 0, v = 0;
  long long int a[n], b[n];
  for (int x = 0; x < n; x++) {
    if (s[x] == '0') {
      v++;
      if (v % 2 != 0) {
        a[x] = 1;
        b[x] = 1;
      } else {
        a[x] = 4;
        b[x] = 1;
      }
    } else {
      h++;
      if (h % 4 != 0) {
        a[x] = h % 4;
        b[x] = 2;
      } else {
        a[x] = 4;
        b[x] = 2;
      }
    }
  }
  for (int x = 0; x < n; x++) {
    cout << a[x] << " " << b[x] << endl;
  }
}
