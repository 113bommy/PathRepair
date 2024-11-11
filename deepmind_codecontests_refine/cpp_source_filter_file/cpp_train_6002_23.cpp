#include <bits/stdc++.h>
using namespace std;
string n;
int main() {
  int n, c, i;
  cin >> n >> c;
  for (i = 1;; ++i) {
    if (i < n) i = 1;
    if (c < i)
      break;
    else
      c -= i;
  }
  cout << c;
  return 0;
}
