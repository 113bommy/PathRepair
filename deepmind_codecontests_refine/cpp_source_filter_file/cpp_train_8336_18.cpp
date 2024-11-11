#include <bits/stdc++.h>
using namespace std;
long long a[120005];
long long n, p[123];
map<int, int> m;
int main() {
  for (long long i = 1; i <= 30; i++) {
    p[i] = 1 << i;
  }
  cin >> n;
  for (long long i = 0; i < n; i++) {
    cin >> a[i];
    m[a[i]]++;
  }
  long long ans = n;
  if (n == 1 && a[0] == 0) {
    puts("0");
    return 0;
  }
  int t = 0;
  for (long long i = 0; i < n; i++) {
    bool ok = 0;
    for (long long k = 1; k <= 30; k++) {
      if (p[k] == 2 * a[i]) {
        if (m[a[i]] > 1) {
          ok = 1;
          break;
        } else
          continue;
      }
      long long t = p[k] - a[i];
      if (m[p[k] - a[i]]) {
        ok = 1;
        break;
      }
    }
    if (!ok) ans--;
  }
  cout << ans;
  return 0;
}
