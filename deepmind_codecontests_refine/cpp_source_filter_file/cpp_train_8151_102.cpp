#include <bits/stdc++.h>
using namespace std;
int min(int a, int b, int c) {
  if (a <= b && a <= c)
    return a;
  else if (b <= a && b <= c)
    return b;
  else
    return c;
}
int main() {
  long int n, k, l, c, d, p, nl, np;
  cin >> n >> k >> l >> c >> d >> p >> nl >> np;
  int ltr = k * l;
  int sli = c * d;
  int x = min(ltr / nl, sli, p / np);
  cout << x / 3;
  return 0;
}
