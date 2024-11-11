#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, a, x, b, y, pr, ul;
  cin >> n >> a >> x >> b >> y;
  pr = a;
  ul = b;
  while (pr != x && ul != y && pr != ul) {
    pr++;
    ul--;
    if (pr == n) {
      pr = 1;
    }
    if (ul == 0) {
      ul = n;
    }
  }
  if (pr == ul) {
    cout << "YES";
  } else
    cout << "NO";
}
