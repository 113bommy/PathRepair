#include <bits/stdc++.h>
using namespace std;
int a, b, c, d, s1, s2;
int main() {
  cin >> a >> b >> c >> d;
  s1 = abs(a - c);
  s2 = abs(b - d);
  if (s1 == 0)
    s1 = 2;
  else
    s1++;
  if (s2 == 0)
    s2 = 2;
  else
    s2++;
  printf("%d\n", 2 * (s1 + s2));
}
