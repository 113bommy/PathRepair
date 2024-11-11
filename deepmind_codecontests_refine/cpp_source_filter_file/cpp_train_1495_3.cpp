#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
using lli = long long int;
using vi = vector<int>;
using vll = vector<long long int>;
lli calc(long long a) {
  if (a < 10) return a;
  lli r = a / 10 - 1;
  r += 9;
  long long f = a;
  while (f >= 10) f /= 10;
  if (f <= a % 10) r++;
  return r;
}
int main() {
  int L, R;
  cin >> L >> R;
  cout << calc(R) - calc(L - 1) << "\n";
  return 0;
}
