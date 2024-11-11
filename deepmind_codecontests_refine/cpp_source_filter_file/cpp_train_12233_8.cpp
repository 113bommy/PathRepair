#include <bits/stdc++.h>
using namespace std;
long long maxm = -1e18;
long long minm = 1e18;
long long mod = 1e9 + 7;
long long mod1 = 1e9 + 9;
const long double Pi = 3.141592653;
int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);
  long long t = 1;
  while (t--) {
    long long n;
    cin >> n;
    long long ans = 1;
    for (long long i = 2; i <= 1e6; i++) {
      if (n % (i * i) == 0) {
        n /= i;
      }
    }
    cout << n << endl;
  }
  return 0;
}
