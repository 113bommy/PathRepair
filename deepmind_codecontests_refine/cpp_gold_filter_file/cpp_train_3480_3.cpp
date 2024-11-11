#include <bits/stdc++.h>
using namespace std;
int main() {
  int k, a, b, v;
  cin >> k >> a >> b >> v;
  int box = 0;
  int count = 0;
  do {
    if (k >= b + 1 && b != 0) {
      count = v * (b + 1);
      b = 0;
    } else if (k < b + 1 && b != 0) {
      count = v * k;
      b -= (k - 1);
    } else
      count = v;
    box++;
    a -= count;
  } while (a > 0);
  cout << box;
  return 0;
}
