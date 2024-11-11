#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;
const long long N = 2e5 + 5;
const long double pi = 3.14159265359;
const long long INF = (1LL << 63);
long long n, a, b;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  a = n, b = 1;
  for (long long i = 1; i <= n; i++) {
    if (n % i == 0) {
      if (abs(n / i - i) < a - b) {
        a = i;
        b = n / i;
      }
    }
  }
  if (a > b) swap(a, b);
  cout << a << " " << b << "\n";
  return 0;
}
