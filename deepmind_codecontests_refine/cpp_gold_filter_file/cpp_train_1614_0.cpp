#include <bits/stdc++.h>
using namespace std;
int main() {
  long long a, b, c, l;
  cin >> a >> b >> c >> l;
  long long ways = (l + 1) * (l + 2) * (l + 3);
  ways /= 6;
  for (int i = 0; i <= l; i++) {
    long long x = min(a - b - c + i, l - i);
    if (x < 0) continue;
    ways -= ((x + 1) * (x + 2)) / 2;
  }
  for (int i = 0; i <= l; i++) {
    long long x = min(b - a - c + i, l - i);
    if (x < 0) continue;
    ways -= ((x + 1) * (x + 2)) / 2;
  }
  for (int i = 0; i <= l; i++) {
    long long x = min(c - b - a + i, l - i);
    if (x < 0) continue;
    ways -= ((x + 1) * (x + 2)) / 2;
  }
  cout << ways << endl;
  return 0;
}
