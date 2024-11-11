#include <bits/stdc++.h>
using namespace std;
int r, h, c;
int main() {
  cin >> r >> h;
  c += 2 * (h / r);
  h %= r;
  double h2, r2;
  h2 = h;
  r2 = r;
  if (h2 >= r2 / 2) {
    c += 2;
    if (2 * h2 * h2 >= r2 * r2) c++;
  } else {
    c += 1;
  }
  cout << c << '\n';
  return 0;
}
