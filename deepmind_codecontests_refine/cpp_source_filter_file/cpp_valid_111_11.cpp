#include <bits/stdc++.h>
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize 03
using namespace std;
int n1, m1, q, r;
int ans = 0;
int gcd(int a, int b) {
  if (a > b) swap(a, b);
  return (a == 0) ? b : gcd(b % a, a);
}
int lcm(int a, int b) { return (a * b) / gcd(a, b); }
signed main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> a(2 * n);
    for (int i = 0; i < 2 * n; ++i) {
      if (i < n)
        a[i] = 1;
      else
        a[i] = 0;
    }
    vector<int> b = a;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < 2 * n; ++j) {
        if (b[j] == 1)
          cout << "(";
        else
          cout << ")";
      }
      cout << "\n";
      b = a;
      swap(a[i + 1], a[2 * n - i - 2]);
    }
  }
}
