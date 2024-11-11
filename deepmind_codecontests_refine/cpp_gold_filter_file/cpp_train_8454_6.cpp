#include <bits/stdc++.h>
using namespace std;
long long int gcd(long long int a, long long int b) {
  if (a == 0) return b;
  return gcd(b % a, a);
}
long long int lcm(long long int a, long long int b) {
  return (a * b) / gcd(a, b);
}
void solve() {
  long long int i, j, n, x, c = 0, sum = 0, mul = 1;
  cin >> n;
  map<long long int, long long int> m;
  for (i = 0; i < n; i++) {
    cin >> x;
    sum += x;
    mul = mul * x;
    m[x]++;
  }
  if (sum != 0 && mul != 0)
    cout << 0;
  else if (sum == 0 && mul != 0) {
    cout << 1;
  } else {
    c = m[0];
    if (c + sum == 0)
      cout << c + 1;
    else
      cout << c;
  }
}
int main() {
  long long int t;
  cin >> t;
  while (t--) {
    solve();
    cout << "\n";
  }
}
