#include <bits/stdc++.h>
using namespace std;
long long solve(long long n) {
  long long c = 0;
  long long a = n;
  while (a != 0) {
    if (a % 2 == 0) {
      c++;
      break;
    }
    a = a / 2;
  }
  if (c == 0) {
    long long ans = 1;
    for (long long i = 2; i <= sqrt(n); i++) {
      if (n % i == 0) {
        ans = max(ans, i);
        ans = max(ans, (n / i));
      }
    }
    return ans;
  }
  long long pw = ceil(log(n + 1) / log(2));
  long long res = 1;
  for (long long i = 0; i < pw; i++) {
    res *= 2;
  }
  return res - 1;
}
int main() {
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    cout << solve(n) << endl;
  }
}
