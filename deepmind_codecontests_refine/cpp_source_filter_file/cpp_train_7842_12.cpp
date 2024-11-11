#include <bits/stdc++.h>
using namespace std;
long long k, b, n, t, x;
bool check() {
  long long x = 1;
  for (int i = 0; i < n; i++) {
    x = k * x + b;
    if (x > t) return false;
  }
  return true;
}
int main() {
  cin >> k >> b >> n >> t;
  if (check()) {
    cout << 0 << endl;
    return 0;
  }
  long long x = 1;
  while (x < t) {
    x = k * x + b;
    if (x < t) n--;
  }
  cout << n << endl;
}
