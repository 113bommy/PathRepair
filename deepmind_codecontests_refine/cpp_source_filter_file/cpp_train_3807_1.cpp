#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
long long n;
bool isprime(long long nn) {
  int k = sqrt(nn + 0.5);
  for (int i = 2; i <= k; ++i) {
    if (nn % k == 0) return 0;
  }
  return 1;
}
int main() {
  cin >> n;
  if (isprime(n))
    puts("1");
  else {
    if (n % 2 == 0 || isprime(n - 2))
      puts("2");
    else
      puts("3");
  }
  return 0;
}
