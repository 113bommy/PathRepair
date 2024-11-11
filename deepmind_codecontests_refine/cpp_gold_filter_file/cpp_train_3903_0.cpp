#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, d, c = 1, count = 0, r;
  cin >> n;
  if (n == 4) {
    cout << 1;
    return 0;
  }
  if (n == 7) {
    cout << 2;
    return 0;
  }
  int y = n;
  while (y > 0) {
    y = y / 10;
    d++;
  }
  int pos = 0;
  for (int i = 1; i < d; i++) {
    pos = pos + pow(2, i);
  }
  while (n > 0) {
    r = n % 10;
    n = n / 10;
    count++;
    if (r == 7) {
      c = c + pow(2, count - 1);
    }
  }
  cout << pos + c;
  return 0;
}
