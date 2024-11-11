#include <bits/stdc++.h>
using namespace std;
const int MOD = 1000003;
long long int pow_mod(long long int a, long long int b, long long int m) {
  if (b == 0) return 1;
  long long int temp = pow_mod(a, b / 2, m);
  temp = (temp * temp) % m;
  if (b & 1) temp = (temp * a) % m;
  return temp;
}
long long int get_twos(long long int num) {
  long long int start = 2, ans = 0;
  while (start <= num) {
    ans += num / start;
    start *= 2;
  }
  return ans;
}
int main() {
  long long int n, k;
  cin >> n >> k;
  if (n <= 61 && k > (1LL << n)) {
    cout << "1"
         << " "
         << "1" << endl;
    return 0;
  }
  long long int numtwo = get_twos(k - 1);
  long long int k1 = n % (MOD - 1), k2 = k % (MOD - 1);
  long long int temp = (k1 * k2 - k1) % (MOD - 1);
  temp -= ((numtwo) % (MOD - 1));
  while (temp < 0) temp += (MOD - 1);
  long long int denom = pow_mod(2, temp, MOD);
  long long int numer = pow_mod(pow_mod(2, numtwo, MOD), MOD - 2, MOD);
  if (k >= MOD + 1) {
    numer = 0;
  } else {
    long long int k3 = pow_mod(2, k1, MOD);
    for (long long int i = 1; i <= k - 1; i++) {
      long long int a = (k3 - i) % MOD;
      if (a < 0) a += MOD;
      numer = numer * a;
      if (numer >= MOD) numer %= MOD;
    }
  }
  numer = denom - numer;
  if (numer < 0) numer += MOD;
  cout << numer << " " << denom << endl;
  return 0;
}
