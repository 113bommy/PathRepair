#include <bits/stdc++.h>
using namespace std;
int gcd(int a, int b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
int main() {
  long long n;
  cin >> n;
  set<long long> f;
  for (long long i = 1; i * i <= n; i++) {
    if (n % i != 0) continue;
    f.insert(i * (n / i) * (n / i - 1) / 2 + n / i);
    f.insert((n / i) * i * (i - 1) / 2 + i);
  }
  for (auto gg : f) cout << gg << ' ';
  return 0;
}
