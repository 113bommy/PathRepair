#include <bits/stdc++.h>
using namespace std;
long long a[10010];
int main() {
  long long n, m, k;
  cin >> n >> m >> k;
  if ((n % 2 == 0) || (m <= n / 2)) {
    cout << "0\n";
    return 0;
  }
  for (int i = 0; i < (n); ++i) {
    cin >> a[i];
  }
  long long mi = a[0];
  int i = 2;
  while (i < n) {
    mi = min(mi, a[i]);
    i += 2;
  }
  long long ans = min(mi, (m / (n / 2 + 1)) * k);
  cout << ans << '\n';
  return 0;
}
