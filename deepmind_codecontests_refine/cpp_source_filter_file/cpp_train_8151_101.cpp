#include <bits/stdc++.h>
using namespace std;
int min(int x, int y, int z) {
  if (x <= y && x <= z) return x;
  if (y <= x && y <= z) return y;
  return z;
}
int main() {
  int n, k, l, c, d, p, nl, np, sum = 0, sum1 = 0, sum2 = 0;
  cin >> n >> k >> l >> c >> d >> p >> nl >> np;
  sum += (k * l);
  sum /= n;
  sum1 += (c * d);
  sum2 += (p / np);
  cout << (min(sum, sum1, sum2)) / n << endl;
}
