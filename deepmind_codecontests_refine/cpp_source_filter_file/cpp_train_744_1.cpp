#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-8;
const double pi = acos(-1);
const long long inf = 0x3f3f3f3f3f3f3f3f;
const int INF = 0x3f3f3f3f;
const int MAX = 2e5 + 10;
const long long mod = 1e9 + 7;
long long gcd(long long a, long long b) { return b ? gcd(b, a % b) : a; }
int a[3000];
int main() {
  int q;
  cin >> q;
  while (q--) {
    int n;
    cin >> n;
    int mark = 0;
    for (int i = (0); i < (n); ++i) cin >> a[i];
    for (int i = (0); i < (n); ++i) {
      if (abs(a[i] - a[(i + 1) % n]) == 1 ||
          abs(a[i] - a[(i + 1) % n] == n - 1))
        continue;
      cout << "NO" << '\n';
      mark = 1;
      break;
    }
    if (mark == 0) cout << "YES" << '\n';
  }
}
