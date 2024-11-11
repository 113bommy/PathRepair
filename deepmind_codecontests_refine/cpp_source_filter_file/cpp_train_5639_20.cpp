#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, c, s, n;
  cin >> n;
  while (cin >> a >> b) {
    c += b - a;
    if (c > s) s = c;
  }
  cout << s;
}
