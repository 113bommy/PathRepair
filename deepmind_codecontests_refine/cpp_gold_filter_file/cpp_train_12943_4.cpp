#include <bits/stdc++.h>
using namespace std;
long long f(long long x) {
  if (x == 0) return 0;
  x--;
  if (x % 2 == 0) return 1 - ((x / 2) % 2);
  if (x % 4 == 1) return x + 2;
  return x + 1;
}
int main() {
  int n;
  cin >> n;
  long long cres = 0;
  for (int i = 0; i < n; ++i) {
    long long a, b;
    cin >> a >> b;
    cres ^= f(a - 1) ^ f(a + b - 1);
  }
  cout << ((cres != 0) ? "tolik" : "bolik");
  return 0;
}
