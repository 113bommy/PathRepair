#include <bits/stdc++.h>
using namespace std;
int main() {
  string a;
  cin >> a;
  int p = -1, i;
  int pos = -1;
  int bc = -1;
  for (i = a.length() - 2; i >= 0; i--) {
    int q = a[i] - '0';
    if (q % 2 == 0 && q < a[a.length() - 1]) {
      p = q;
      pos = i;
    }
    if (q % 2 == 0 && bc != -1) {
      bc = i;
    }
  }
  if (pos != -1) {
    char ar = a[a.length() - 1];
    a[a.length() - 1] = a[pos];
    a[pos] = ar;
    cout << a << endl;
  } else if (bc != -1) {
    char ar = a[a.length() - 1];
    a[a.length() - 1] = a[bc];
    a[bc] = ar;
    cout << a << endl;
  } else
    cout << "-1\n";
  return 0;
}
