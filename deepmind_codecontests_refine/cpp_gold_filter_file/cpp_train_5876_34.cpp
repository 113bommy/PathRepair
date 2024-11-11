#include <bits/stdc++.h>
using namespace std;
int main() {
  string a, b;
  cin >> a >> b;
  int l = a.length();
  for (int i = 0; i < l; i++) {
    if (a[i] != b[l - i - 1]) {
      cout << "NO";
      return 0;
    }
  }
  cout << "YES";
  return 0;
}
