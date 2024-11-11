#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int k, r, l, p, q;
  cin >> k >> r >> l;
  p = (long long int)floor((long double)l / (long double)k);
  q = (long long int)ceil((long double)r / (long double)k);
  cout << abs(p - q) + 1;
  return 0;
}
