#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) { return (b == 0) ? a : gcd(b, a % b); }
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int k;
    cin >> k;
    long long l = gcd(k + 1, 4 * k);
    l = (4 * k) / l;
    cout << l + 1 << endl;
  }
  return 0;
}
