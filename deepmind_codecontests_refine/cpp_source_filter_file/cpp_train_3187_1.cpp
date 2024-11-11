#include <bits/stdc++.h>
const double Pi = acos(-1.0);
using namespace std;
long long a, b;
long long gcd(long long x, long long y) { return (y ? gcd(y, x % y) : x); }
int main(int argc, char** argv) {
  cin >> a >> b;
  long long x = a, y = b;
  vector<long long> fact;
  for (long long i = 2; i * i <= a; i++) {
    if (a % i == 0) {
      fact.push_back(i);
      while (i % a == 0) a /= i;
    }
  }
  if (a > 1) fact.push_back(a);
  long long ans = 0;
  while (y) {
    long long g = gcd(x, y);
    x /= g;
    y /= g;
    long long md = y;
    for (int i = 0; i < (int)fact.size(); i++) {
      if (x % fact[i] == 0) md = min(md, y % fact[i]);
    }
    ans += md;
    y -= md;
  }
  cout << ans << '\n';
  return 0;
}
