#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:1024000000,1024000000")
using namespace std;
const int inf = 0x3f3f3f3f;
const int mod = 1e9 + 7;
int s, a, b, c;
int main() {
  while (cin >> s >> a >> b >> c) {
    double sum = a + b + c;
    double x, y, z;
    if (!a && !b && !c) {
      puts("1.0 1.0 1.0");
      continue;
    }
    x = s * a / sum;
    y = s * b / sum;
    z = s * c / sum;
    printf("%.11f %.11f %.11f\n", x, y, z);
  }
  return 0;
}
