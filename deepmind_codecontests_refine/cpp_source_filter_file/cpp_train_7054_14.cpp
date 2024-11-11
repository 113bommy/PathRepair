#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 5;
long long a[maxn];
int nno[maxn];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  long long k;
  cin >> n >> k;
  for (int i = 0; i < n; ++i) cin >> a[i];
  nno[n - 1] = -1;
  for (int i = n - 2; i >= 0; --i) {
    if (a[i + 1] > 1)
      nno[i] = i + 1;
    else
      nno[i] = nno[i + 1];
  }
  int ans = 0;
  long long mex = (long long)(2e13 + 5) * k;
  for (int i = 0; i < n; ++i) {
    long long p = a[i];
    long long s = a[i];
    int ne = i;
    while (1) {
      if (p == s * k) ans++;
      int ne2 = nno[ne];
      if (ne2 == -1) {
        if (p > s * k && p <= (s + n - i - 1) * k && p % k == 0) ans++;
        break;
      }
      if (p > s * k && p <= (s + ne2 - ne - 1) * k && p % k == 0) {
        ans++;
      }
      s += ne2 - ne - 1;
      ne = ne2;
      if (p >= mex / a[ne]) break;
      p *= a[ne];
      s += a[ne];
    }
  }
  cout << ans << endl;
  return 0;
}
