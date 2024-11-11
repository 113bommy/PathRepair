#include <bits/stdc++.h>
using namespace std;
int f(int n, int m) {
  if (n % 2 == 0 || m % 2 == 0) return n * m / 2;
  return m * (n - 1) / 2 + m / 2;
}
int main() {
  int n, m;
  cin >> n >> m;
  cout << max(f(n, m), f(m, n));
  return 0;
}
