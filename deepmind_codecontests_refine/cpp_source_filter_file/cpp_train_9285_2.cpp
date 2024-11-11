#include <bits/stdc++.h>
using namespace std;
long long power(long long a, long long b) {
  if (a == 0) return 0;
  if (b == 0) return 1;
  if (b % 2 == 0) {
    long long smallans = power(a, (b / 2));
    long long ans =
        ((smallans % 100000000000000000) * (smallans % 100000000000000000)) %
        100000000000000000;
    return ans;
  } else {
    long long smallans = power(a, b - 1);
    long long ans =
        ((smallans % 100000000000000000) * (a % 100000000000000000)) %
        100000000000000000;
    return ans;
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long n, x = 0, y = 0;
  int i;
  cin >> n;
  vector<long long> a(n);
  for (i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(a.begin(), a.end());
  int fin = a.size();
  for (i = 0; i < (n / 2); i++) {
    y += a[i];
    x += a[fin - 1 - i];
  }
  if (n % 2 != 0) x += a[fin - 1 - i];
  long long res =
      power(x, 2) % 100000000000000000 + power(y, 2) % 100000000000000000;
  cout << res;
  return 0;
}
