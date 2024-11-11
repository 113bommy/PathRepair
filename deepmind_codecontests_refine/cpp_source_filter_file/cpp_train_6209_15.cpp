#include <bits/stdc++.h>
using namespace std;
int main() {
  string a, b;
  cin >> a >> b;
  cout << a[0];
  for (int i = 1; i < a.length(); i++) {
    if (a[i] <= b[0])
      cout << a[i];
    else
      break;
  }
  cout << b[0];
  return 0;
}
