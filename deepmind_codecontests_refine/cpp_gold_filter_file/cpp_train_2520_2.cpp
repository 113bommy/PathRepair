#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k, a, b, c = 0, d = 0;
  float length = 0;
  cin >> n >> k;
  cin >> c >> d;
  c *= k;
  d *= k;
  for (int i = 1; i < n; i++) {
    cin >> a >> b;
    a *= k;
    b *= k;
    length += sqrt((float)(a - c) * (a - c) + (float)(b - d) * (b - d));
    c = a;
    d = b;
  }
  length /= 50;
  printf("%0.6f", length);
}
