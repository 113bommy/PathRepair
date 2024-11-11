#include <bits/stdc++.h>
using namespace std;
int main() {
  int c = 0, x;
  string a, b, d;
  cin >> a;
  cin >> b;
  x = b.size();
  for (int i = 0; i < a.size(); i++) {
    d = a.substr(i, x);
    if (d == b) {
      a[i + x - 1] = '#';
      c++;
    }
  }
  printf("%d", c);
  return 0;
}
