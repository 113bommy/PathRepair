#include <bits/stdc++.h>
using namespace std;
int n, x, y, p;
int main() {
  cin >> n >> x >> y;
  p = (n * y + 99) / 100;
  if (p <= x) {
    cout << 0;
  } else {
    cout << p - x;
  }
}
