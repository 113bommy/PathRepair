#include <bits/stdc++.h>
using namespace std;
int main() {
  int w, h;
  cin >> w >> h;
  int a = 2;
  int b = 2;
  long long c = 0;
  long long d = 0;
  while (w - a + 1 > 0) {
    c += w - a + 1;
    a += 2;
  }
  while (w - b + 1 > 0) {
    d += w - b + 1;
    b += 2;
  }
  long long r = c * d;
  cout << r << endl;
  return 0;
}
