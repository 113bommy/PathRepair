#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k, l, c, d, p, nl, np;
  cin >> n >> k >> l >> c >> d >> p >> nl >> np;
  if (k * l / (nl * n) < c * d / (n) && k * l / (nl * n) < p / (np * n))
    cout << k * l / (nl * n);
  if (k * l / (nl * n) > c * d / (n) && c * d / n < p / (np * n))
    cout << c * d / n;
  if (k * l / (nl * n) > p / (np * n) && c * d / n > p / (np * n))
    cout << p / (np * n);
  return 0;
}
