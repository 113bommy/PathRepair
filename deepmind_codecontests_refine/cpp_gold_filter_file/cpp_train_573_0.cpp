#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, c, i;
  cin >> a >> b >> c;
  for (i = 0; i <= c / a; i++) {
    if ((c - a * i) % b == 0) {
      cout << "Yes";
      return 0;
    }
  }
  cout << "No";
  return 0;
}
