#include <bits/stdc++.h>
using namespace std;
int main() {
  int i, t, n, a, b, j;
  string str;
  cin >> t;
  for (i = 0; i < t; ++i) {
    a = -1;
    b = -1;
    cin >> n;
    getchar();
    cin >> str;
    for (j = 0; j < str.length() - 1; ++j) {
      if (str[j] != str[j + 1]) {
        a = j;
        b = j + 1;
        break;
      }
    }
    cout << a << " " << b << endl;
  }
  return 0;
}
