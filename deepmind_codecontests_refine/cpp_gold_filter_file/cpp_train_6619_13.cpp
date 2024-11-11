#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) {
  if (a == 0) return b;
  return gcd(b % a, a);
}
long long lcm(long long a, long long b) { return (a * b) / gcd(a, b); }
long long power(long long x, long long y) {
  long long res = 1;
  while (y > 0) {
    if (y & 1) res = res * x;
    y = y >> 1;
    x = x * x;
  }
  return res;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n;
  int ans = 0;
  set<int> s;
  for (long long i = 0; i < 2 * n; i++) {
    int x;
    cin >> x;
    if (s.find(x) == s.end())
      s.insert(x);
    else
      s.erase(x);
    ans = max(ans, (int)s.size());
  }
  cout << ans << endl;
}
