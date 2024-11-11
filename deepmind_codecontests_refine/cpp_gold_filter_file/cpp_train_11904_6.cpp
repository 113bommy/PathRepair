#include <bits/stdc++.h>
using namespace std;
int s, a, b, c;
int main() {
  cin >> s >> a >> b >> c;
  long double p;
  if (a + b + c == 0)
    p = 0;
  else
    p = s * 1.0 / ((a + b + c) * 1.0);
  printf("%.20f %.20f %.20f", p * a, p * b, p * c);
  return 0;
}
