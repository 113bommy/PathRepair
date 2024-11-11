#include <bits/stdc++.h>
using namespace std;
long long ans = 0, i, j, n, m;
long long w[1100000], a[1100000];
vector<long long> v;
bool isPrime(long long x) {
  for (long long i = 2; i * i <= x; ++i)
    if (x % i == 0) return false;
  return true;
}
int main() {
  cin >> n;
  int ans = 1;
  i = 2;
  if (n % i == 0) {
    while (n % i == 0) n /= i;
    ans *= i;
  }
  i++;
  while (n > 1) {
    if (n % i == 0) {
      while (n % i == 0) n /= i;
      ans *= i;
    }
    if (i > int(sqrt(n * 1.))) {
      ans *= n;
      break;
    }
    i += 2;
  }
  cout << ans << endl;
}
