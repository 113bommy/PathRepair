#include <bits/stdc++.h>
using namespace std;
long long b[200005], a[200005];
string s, p;
int main() {
  ios_base::sync_with_stdio(false);
  long long i, j, k, l, m, x, y, r, n, t;
  cin >> n >> k;
  for (i = 0; i <= n; i++) {
    cin >> a[i];
  }
  b[n] = a[n];
  for (i = 0; i < n; i++) {
    long long temp = (a[i] + b[i]);
    b[i + 1] += (temp / 2ll);
    b[i] = temp % 2ll;
  }
  long long flag = 0;
  for (i = 0; i <= n; i++) {
    if (b[i]) {
      flag = i;
      break;
    }
  }
  long long res = 0;
  long long cnt = 0;
  for (i = n; i >= 0; i--) {
    res = res * 2ll + b[i];
    if (res > 1000000002000000000ll && res < -1000000002000000000ll) break;
    if (i <= flag) {
      long long ans = a[i] - res;
      if (ans >= -k && ans <= k) {
        if (ans != 0 || i != n) cnt++;
      }
    }
  }
  cout << cnt << endl;
  return 0;
}
