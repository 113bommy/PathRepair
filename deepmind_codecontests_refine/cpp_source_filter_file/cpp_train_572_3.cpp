#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, c, i;
  cin >> a >> b >> c;
  for (i = 0; i < 10001; i++) {
    if ((c - a * i) % b == 0) {
      cout << "Yes";
      return 0;
    }
  }
  cout << "No";
  return 0;
}
