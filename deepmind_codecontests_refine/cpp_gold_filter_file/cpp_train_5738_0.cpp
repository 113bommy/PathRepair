#include <bits/stdc++.h>
using namespace std;
int main() {
  long long i, j;
  long long n, a[128];
  long long f[128];
  long long ans = 0;
  cin >> n;
  for (i = 1; i <= n; i++) {
    cin >> a[i];
  }
  f[1] = a[1];
  for (i = 2; i <= n; i++) {
    if (a[i] == 1) {
      f[i] = 1;
      continue;
    }
    f[i] = a[i];
    f[i] += (f[i] - 1) * (i - 1);
  }
  for (i = 1; i <= n; i++) {
    ans += f[i];
  }
  cout << ans << endl;
}
