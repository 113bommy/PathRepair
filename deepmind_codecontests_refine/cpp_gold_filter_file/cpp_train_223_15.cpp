#include <bits/stdc++.h>
using namespace std;
const long long MOD = (1e9) + 7;
const long double EPS = 0.0000001;
long long pows(long long a, long long b) {
  if (b == 0) return 1LL;
  long long temp = pows(a, b / 2);
  temp = (temp * temp) % MOD;
  if (b % 2) temp = (temp * a) % MOD;
  return temp;
}
int main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    long long a, b;
    cin >> a >> b;
    long long n;
    cin >> n;
    if ((n % 3) == 0) {
      cout << a << endl;
    } else if ((n % 3) == 1) {
      cout << b << endl;
    } else {
      cout << (a ^ b) << endl;
    }
  }
  return 0;
}
