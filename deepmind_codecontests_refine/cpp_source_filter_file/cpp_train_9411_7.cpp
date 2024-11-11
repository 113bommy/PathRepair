#include <bits/stdc++.h>
using namespace std;
int main() {
  long a, b, c;
  cin >> a >> b >> c;
  if ((b + c - a) % 2 == 0 && (c + a - b) % 2 == 0 && (b + a - c) % 2 == 0 &&
      (b + a - c) / 2 > 0 && (c + b - a) / 2 > 0 && (c + a - b) / 2 > 0)
    cout << (b + a - c) / 2 << " " << (c + b - a) / 2 << " " << (c + a - b) / 2;
  else
    cout << "Impossible";
  return 0;
}
