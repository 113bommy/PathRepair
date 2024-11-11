#include <bits/stdc++.h>
using namespace std;
long long n;
int main() {
  cin >> n;
  long long ans = 1, x = n;
  for (long long i = 2; i * i <= x; i++)
    if (n % i == 0) {
      ans *= (long long)i;
      while (n % i == 0) n /= i;
    }
  if (n > 1) ans *= n;
  cout << ans;
}
