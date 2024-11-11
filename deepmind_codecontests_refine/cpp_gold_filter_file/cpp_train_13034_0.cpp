#include <bits/stdc++.h>
using namespace std;
long long ti, n, a[200009];
long long binpow(int a, int n) {
  if (n == 0) return 1ll;
  if (n % 2 == 1)
    return 1ll * binpow(a, n - 1) * a;
  else {
    long long b = binpow(a, n / 2);
    return 1ll * b * b;
  }
}
int main() {
  cin >> ti;
  while (ti--) {
    cin >> n;
    long long sum = 0, xr = 0;
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
      sum += a[i];
      xr ^= a[i];
    }
    int k = 1;
    while (binpow(2, k) <= sum) k++;
    long long s1 = binpow(2, k);
    if (sum % 2) s1++;
    sum += s1;
    xr ^= s1;
    xr *= 2;
    long long dif = xr - sum;
    long long s2 = dif / 2ll, s3 = s2;
    sum += s2;
    sum += s2;
    cout << 3 << endl << s1 << " " << s2 << " " << s3 << endl;
  }
}
