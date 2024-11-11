#include <bits/stdc++.h>
using namespace std;
int n, x, y;
int main() {
  cin >> n >> x >> y;
  x = (n - x) + 1;
  if (y > x) {
    cout << "Black";
  } else {
    cout << "White";
  }
  return 0;
}
