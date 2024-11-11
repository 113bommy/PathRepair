#include <bits/stdc++.h>
using namespace std;
int main(void) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  long double n, k, l, c, d, p, nl, np;
  cin >> n >> k >> l >> c >> d >> p >> nl >> np;
  cout << (long long int)(min(min(k * l / nl, c * d), p / np) / n);
  return 0;
}
