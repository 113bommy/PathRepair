#include <bits/stdc++.h>
using namespace std;
int main(void) {
  long long t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    string a, b, c;
    cin >> a >> b >> c;
    int n = a.length();
    bool pos = true;
    for (int j = 0; j < n; j++) {
      if (a[j] != c[j] && b[j] != c[j]) {
        pos = false;
      }
    }
    if (pos) {
      cout << "YES";
    } else {
      cout << "NO";
    }
  }
  return 0;
}
