#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:5000000000")
const long long mod = 1000000007;
long long Inf = (long long)2e9;
long long LINF = (long long)1e18 + 1e17;
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long n;
  cin >> n;
  for (long long a = 2; a * a < n; a++) {
    if (n % a != 0) continue;
    long long b = n / a;
    for (long long x = 1; x * b < n - 1; x++) {
      long long d = n - 1 - x * b;
      if (d > 0 && d % a == 0 && x < a && d / a < b) {
        if (a > b)
          cout << "YES\n" << d / a << " " << b << endl << x << " " << a;
        else
          cout << "YES\n2\n" << x << " " << a << endl << d / a << " " << b;
        return 0;
      }
    }
  }
  cout << "NO";
  return 0;
}
