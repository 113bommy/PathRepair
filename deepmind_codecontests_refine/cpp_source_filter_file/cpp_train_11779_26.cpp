#include <bits/stdc++.h>
using namespace std;
int x, y, z, a, b, c;
int main() {
  cin >> x >> y >> z >> a >> b >> c;
  if (a < x) {
    puts("NO");
    return 0;
  }
  x -= a;
  if (a + b < y || a + b + c < y + z) {
    puts("NO");
    return 0;
  }
  puts("YES");
}
