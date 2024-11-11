#include <bits/stdc++.h>
using namespace std;
int gcd(int a, int b) {
  if (a == 0 || b == 0) return max(a, b);
  if (a > b) return gcd(a - b, b);
  return gcd(b, b - a);
}
int main() {
  int n, ma, mb;
  cin >> n;
  for (int i = 1; i <= n / 2; ++i) {
    int a = i;
    int b = n - i;
    if (gcd(a, b) == 1) {
      ma = a;
      mb = b;
    }
  }
  cout << ma << " " << mb;
  return 0;
}
