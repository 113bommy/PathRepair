#include <bits/stdc++.h>
using namespace std;
long long int pow(int exp) {
  if (exp == 0) return 1;
  if (exp == 1) return 2;
  long long int ans = pow(exp / 2);
  ans *= ans;
  ans %= 1000000006;
  if (ans % 2 == 1) ans *= 2;
  ans %= 1000000006;
  return ans;
}
int main() {
  long long int n, m, k;
  cin >> n >> m >> k;
  if (k == -1 && (n % 2) != (m % 2)) {
    cout << 0;
    return 0;
  }
  long long int p = (n - 1) % 1000000006;
  p *= (m - 1) % 1000000006;
  p %= 1000000006;
  cout << pow(p);
}
