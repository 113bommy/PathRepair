#include <bits/stdc++.h>
using namespace std;
long long pwr(long long base, long long p, long long mod = 1000000000) {
  long long ans = 1;
  while (p) {
    if (p % 2 == 1) ans = (ans * base) % 1000000000;
    base = (base * base) % 1000000000;
    p /= 2;
  }
  return ans;
}
long long gcd(long long a, long long b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
long long lcm(long long a, long long b) { return (a * b) / gcd(a, b); }
bool cmp(const pair<int, int> &a, const pair<int, int> &b) {
  return (a.first > b.first);
}
const long long N = 5e5 + 5;
int main() {
  int p, m, s, ma;
  cin >> p >> m >> s >> ma;
  if (max(s, ma) > 2 * ma || 2 * s < ma || m <= ma) {
    cout << -1 << endl;
  } else {
    cout << 2 * p << endl << 2 * m << endl << max(s, ma) << endl;
  }
  return 0;
}
