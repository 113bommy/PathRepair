#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, first, curr, prev, x, y, min = 10000;
  cin >> n;
  cin >> prev;
  first = prev;
  for (int i = 1; i < n; ++i) {
    cin >> curr;
    if (abs(curr - prev) < min) {
      min = abs(curr - prev);
      x = i - 1 + 1;
      y = i + 1;
    }
    prev = curr;
  }
  if (prev - first < min) {
    x = n;
    y = 1;
  }
  cout << x << " " << y;
}
