#include <bits/stdc++.h>
using namespace std;
int x, y, z, a, b, c;
int main() {
  cin >> x >> y >> z >> a >> b >> c;
  if (x > a)
    puts("NO");
  else {
    a -= x;
    if (y > a + b)
      puts("NO");
    else {
      c = c + a + b - y;
      puts(c >= z ? "YES" : "NO");
    }
  }
  return 0;
}
