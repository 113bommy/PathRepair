#include <bits/stdc++.h>
using namespace std;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
long long getrand(long long l, long long r) {
  return uniform_int_distribution<long long>(l, r)(rng);
}
int main() {
  long long n, k;
  cin >> n >> k;
  long long l = 1, r = n;
  string ans;
  int asks = 0;
  while (true) {
    if (r - l + 1 <= 50) {
      long long x = getrand(l, r);
      cout << x << " " << x << endl;
      cin >> ans;
      if (ans == "Yes") {
        return 0;
      }
      l = max(l - k, 1LL);
      r = min(r + k, n);
      asks++;
    } else {
      long long m = (l + r) / 2;
      cout << l << " " << m << endl;
      cin >> ans;
      if (ans == "Yes") {
        l = max(l - k, 1LL);
        r = min(m + k, n);
      } else {
        l = max(m - k, 1LL);
        r = min(r + k, n);
      }
      asks++;
    }
    if (asks >= 4500) {
      return 0;
    }
  }
  return 0;
}
