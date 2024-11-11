#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n;
  cin >> n;
  long long ans = 0;
  for (long long i = 2; i <= n; i++) {
    for (long long j = 2 * i; j <= n; j += i) {
      if (j % i == 0 and j / i > 1) ans += (j / i) * 4;
    }
  }
  cout << ans << endl;
}
