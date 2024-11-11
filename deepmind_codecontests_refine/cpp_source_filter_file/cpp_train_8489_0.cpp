#include <bits/stdc++.h>
using namespace std;
const double pi = acos(-1.0);
int a[200];
int n, k, t;
bool isGood() {
  long long k1, k2, k3;
  k1 = k2 = k3 = 0;
  for (long long i = 1; i <= n; i++) k1 += a[i];
  k3 = k1 + 1;
  k1 = k1 * 100 * n * k;
  k3 = k3 * 100 * n * k;
  k2 = t * n * n * k * k;
  if (k1 <= k2 && k2 < k3) {
    return true;
  }
  return false;
}
int main() {
  cin >> n >> k >> t;
  for (long long index = 1; index <= n; index++)
    for (long long intensive = 0; intensive <= k; intensive++) {
      for (long long i = 1; i <= index - 1; i++) a[i] = k;
      a[index] = intensive;
      for (long long i = index + 1; i <= n; i++) a[i] = 0;
      if (isGood()) {
        for (long long i = 1; i <= n; i++) cout << a[i] << " ";
        cout << endl;
        goto loop1;
      }
    }
loop1:;
}
