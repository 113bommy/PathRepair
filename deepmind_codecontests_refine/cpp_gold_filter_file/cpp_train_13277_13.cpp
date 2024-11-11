#include <bits/stdc++.h>
using namespace std;
const long long inf = 1e18 + 1;
const int N = 1000002;
long long gcd(long long x, long long y) {
  if (y == 0) return x;
  return gcd(y, x % y);
}
long long power(long long A, long long B, long long mod = 1000000007) {
  long long r = 1;
  while (B > 0) {
    if (B & 1LL) r = (r * A) % mod;
    A = (A * A) % mod;
    B >>= 1;
  }
  return r;
}
struct set_comp {
  bool operator()(const int& lhs, const int& rhs) { return lhs < rhs; }
};
int a[100002];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(NULL), cout.tie(NULL);
  int n, i;
  cin >> n;
  int c = 0;
  for (i = 1; i <= n; i++) {
    cin >> a[i];
  }
  sort(a + 1, a + 1 + n);
  for (i = 1; i <= n; i++) {
    if (c == a[i]) {
    } else if (c < a[i]) {
      c++;
    }
  }
  cout << c + 1 << endl;
  return 0;
}
