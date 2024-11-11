#include <bits/stdc++.h>
using namespace std;
int gcd(int a, int b) { return a ? gcd(b % a, a) : b; }
int main() {
  long long n, m, k;
  cin >> n >> m >> k;
  if (n & 1) {
    long long m = 1e13;
    for (int i = 0; i < n; i++) {
      int a;
      cin >> a;
      if (!(i & 1) && m > a) {
        m = a;
      }
    }
    cout << min(m, k * m / (n + 1) * 2);
  } else
    cout << 0;
}
