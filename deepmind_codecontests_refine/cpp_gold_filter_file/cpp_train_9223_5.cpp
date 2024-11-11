#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) { return b == 0 ? a : gcd(b, a % b); }
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n;
  while (n--) {
    long long a, b;
    cin >> a >> b;
    long long k = (0.6 + cbrt(a * b));
    if (a * b == k * k * k) {
      if (gcd(a, b) % k == 0) {
        cout << "Yes\n";
      } else
        cout << "No\n";
    } else
      cout << "No\n";
  }
}
