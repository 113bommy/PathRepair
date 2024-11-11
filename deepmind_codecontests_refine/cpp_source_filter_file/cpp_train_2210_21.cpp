#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) { return b == 0 ? a : gcd(b, a % b); }
long long lcm(long long a, long long b) { return a * b / gcd(a, b); }
int main() {
  long long res = 0;
  int n;
  cin >> n;
  map<int, int> a;
  for (int i = 1; i <= n; ++i) {
    int x;
    cin >> x;
    a[x]++;
  }
  if (a[0] > 1) {
    int ax = a[0];
    for (int i = 0; i < ax; ++i) {
      res = res + (ax - i - 1);
    }
  }
  for (int i = -10; i < 0; i++) {
    res += a[i] * a[-i];
  }
  cout << res << endl;
}
