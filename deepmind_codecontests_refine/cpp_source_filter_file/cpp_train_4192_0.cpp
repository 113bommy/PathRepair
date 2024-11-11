#include <bits/stdc++.h>
using namespace std;
const double pi = 2.0 * acos(0.0);
char small[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i',
                  'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r',
                  's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
long long int big_mod(long long int BASE, long long int POWER,
                      long long int MOD) {
  if (POWER == 0)
    return 1;
  else if (POWER % 2 == 0) {
    long long int RESULT = big_mod(BASE, POWER / 2, MOD);
    return ((RESULT % MOD) * (RESULT % MOD)) % MOD;
  } else
    return ((BASE % MOD) * (big_mod(BASE, POWER - 1, MOD) % MOD)) % MOD;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long int n, k;
    cin >> n >> k;
    long long int a[n], w[k];
    for (long long int i = 0; i < n; i++) cin >> a[i];
    for (long long int i = 0; i < k; i++) cin >> w[i];
    sort(a, a + n);
    sort(w, w + k);
    reverse(w, w + k);
    long long int sum = 0;
    long long int h = k, j = 0, p = n - 1, q = 0;
    while (h--) {
      if (w[j] == 1) {
        long long int dd = a[p] + a[p];
        sum += dd;
        p--;
      } else {
        long long int dd = a[p] + a[q];
        sum += dd;
        p--;
        q += w[j] - 1;
      }
      j++;
    }
    cout << sum << endl;
  }
}
