#include <bits/stdc++.h>
using namespace std;
int main() {
  long long a, b, c;
  long long x, y, z;
  while (cin >> a >> b >> c) {
    cin >> x >> y >> z;
    long long more = 0, need = 0;
    if (a > x)
      more += (a - x) / 2;
    else
      need += x - a;
    if (b > y)
      more += (b - y) / 2;
    else
      need += y - b;
    if (c > z)
      more += (z - c) / 2;
    else
      need += (z - c);
    cout << (more >= need ? "Yes" : "No") << endl;
  }
  return 0;
}
