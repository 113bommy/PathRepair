#include <bits/stdc++.h>
using namespace std;
int dx[] = {0, 0, 1, -1, -1, -1, 1, 1};
int dy[] = {1, -1, 0, 0, 1, -1, 1, -1};
const double EPS = 1e-8;
const double PI = acos(-1.0);
long long gcd(long long a, long long b) { return !b ? a : gcd(b, a % b); }
long long lcm(long long a, long long b) { return (a / gcd(a, b)) * b; }
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    n /= 2;
    if (n & 1) {
      cout << "NO" << endl;
      continue;
    }
    cout << "YES" << endl;
    int s = 2;
    int e = (int)1e9 - 2;
    for (int i = 0; i < n; i++) {
      cout << s << " " << e << " ";
      s += 2;
      e -= 2;
    }
    s = 1;
    e = (int)1e9 - 1;
    for (int i = 0; i < n; i++) {
      cout << s << " " << e << " ";
      s += 2;
      e -= 2;
    }
    cout << endl;
  }
  return 0;
}
