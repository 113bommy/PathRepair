#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) { return (a == 0) ? b : gcd(b % a, a); }
map<int, int> loops;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long k;
  cin >> k;
  long long x = k / 2, y = k % 2;
  if (x > 18) {
    cout << -1;
    return 0;
  } else {
    if (y) cout << 4;
    for (long long i = 0; i < x; ++i) cout << 8;
  }
  return 0;
}
