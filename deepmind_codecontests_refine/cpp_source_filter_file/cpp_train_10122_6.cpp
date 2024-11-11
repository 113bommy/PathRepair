#include <bits/stdc++.h>
using namespace std;
long long max(long long a, long long b) { return a > b ? a : b; }
long long min(long long a, long long b) { return a < b ? a : b; }
long long gcd(long long a, long long b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
long long lcm(long long a, long long b) { return (a * b) / gcd(a, b); }
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    int a, b;
    cin >> a >> b;
    if (a == b)
      cout << 0 << endl;
    else {
      if (a > b) {
        if (!((a - b) & 1)) {
          cout << 1 << endl;
        } else
          cout << 0 << endl;
      } else {
        if (((b - a) & 1)) {
          cout << 1 << endl;
        } else
          cout << 0 << endl;
      }
    }
  }
  return 0;
}
