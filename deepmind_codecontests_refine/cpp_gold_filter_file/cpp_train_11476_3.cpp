#include <bits/stdc++.h>
using namespace std;
long long a[10000];
int main() {
  long long n, m, j;
  cin >> n >> m;
  long long i;
  long long x, ans = 1;
  vector<long long> v(n);
  for (i = 0; i < n; i++) {
    cin >> x;
    v[i] = x;
    a[x % m]++;
    if (a[x % m] > 1) ans = 0;
  }
  if (ans == 0 or n > m) {
    cout << 0 << endl;
    return 0;
  }
  for (i = 0; i < n; i++) {
    for (j = i + 1; j < n; j++) {
      ans = (ans * abs(v[j] - v[i]) % m);
      ans %= m;
    }
  }
  cout << ans << endl;
  return 0;
}
