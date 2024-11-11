#include <bits/stdc++.h>
using namespace std;
bool prime(long long n) {
  for (long long i = 2; i <= n / 2 + 1; i++) {
    if (n % i == 0) return false;
  }
  return true;
}
int main() {
  long long n, ans;
  cin >> n;
  if (prime(n))
    ans = 1;
  else if (n % 2 == 0)
    ans = 2;
  else if (prime(n - 2))
    ans = 2;
  else
    ans = 3;
  cout << ans << endl;
  return 0;
}
