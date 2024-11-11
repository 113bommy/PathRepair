#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, a, x, b, y;
  bool check = false;
  cin >> n >> a >> x >> b >> y;
  while (a != x && b != y) {
    if (a != x) {
      a++;
      if (a == n + 1) a = 1;
    }
    if (b != y) {
      b--;
      if (b == 0) b = n;
    }
    if (a == b) check = true;
  }
  check ? cout << "YES" : cout << "NO";
  return 0;
}
