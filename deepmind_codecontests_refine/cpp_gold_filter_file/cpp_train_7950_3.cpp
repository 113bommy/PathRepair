#include <bits/stdc++.h>
using namespace std;
long double res;
long double ret_numer = 0, ret_denom = 1;
int x, y, n;
void update(int numer, int denom) {
  long double val = abs((long double)numer / denom - (long double)x / y);
  if (val < res) {
    ret_numer = numer, ret_denom = denom;
    res = val;
  } else if (val == res && ret_denom > denom)
    ret_numer = numer, ret_denom = denom;
  else if (val == res && ret_denom == denom && ret_numer > numer)
    ret_numer = numer;
}
int main() {
  cin >> x >> y >> n;
  res = (long double)x / y;
  for (int i = 1; i <= n; i++) {
    long double cur = (long double)x * (long double)i / y;
    int numer1 = floor(cur), numer2 = ceil(cur);
    update(numer1, i);
    update(numer2, i);
  }
  cout << ret_numer << "/" << ret_denom;
}
