#include <bits/stdc++.h>
using namespace std;
const long long modd = 1e9 + 7;
long long poww(long long a, long long b) {
  long long ans = 1;
  while (b > 0) {
    if (b % 2 == 1) ans = (ans * a) % modd;
    b = b / 2;
    a = (a * a) % modd;
  }
  return ans;
}
int main() {
  long long x, k;
  cin >> x >> k;
  if (x == 0) {
    cout << 0 << '\n';
    return 0;
  }
  long long ans = (poww(2, k + 1) * (x % modd)) % modd;
  ans = (ans - poww(2, k) + 1 + modd) % modd;
  cout << ans;
  return 0;
}
