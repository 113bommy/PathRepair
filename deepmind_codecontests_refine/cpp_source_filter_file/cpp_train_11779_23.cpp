#include <bits/stdc++.h>
using namespace std;
int x, y, z, a, b, c;
int main() {
  ios::sync_with_stdio(false);
  cin >> x >> y >> z;
  cin >> a >> b >> c;
  if (a < x) {
    puts("NO");
    return 0;
  }
  a -= x;
  if (b + c < y) {
    puts("NO");
    return 0;
  }
  if (y > b) {
    y -= b;
    c -= y;
    b = 0;
  } else {
    b -= y;
  }
  if (a + b + c < z) {
    puts("NO");
    return 0;
  }
  puts("YES");
}
