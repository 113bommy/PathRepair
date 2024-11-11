#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, i, j;
  cin >> n;
  string s = "ROYGBIV";
  for (i = 0, j = 0; j < n; j++) {
    cout << s[i];
    i++;
    if (i == 7) {
      i = 3;
    }
  }
  return 0;
}
