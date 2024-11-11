#include <bits/stdc++.h>
using namespace std;
int main() {
  float d, h, v, e;
  scanf("%f%f%f%f", &d, &h, &v, &e);
  float k = 3.14159 * (d / 2) * (d / 2) * h;
  float r = v - 3.14159 * (d / 2) * (d / 2) * e;
  if (r == 0) {
    printf("NO\n");
    return 0;
  }
  float m = k / r;
  if (m < 0) {
    cout << "NO"
         << "\n";
    return 0;
  } else {
    cout << "YES"
         << "\n";
    printf("%.8f\n", m);
  }
  return 0;
}
