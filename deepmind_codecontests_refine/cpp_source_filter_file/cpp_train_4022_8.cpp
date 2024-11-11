#include <bits/stdc++.h>
using namespace std;
long long n, a, m, d, ans = 0;
long long t[100010];
int main() {
  ios::sync_with_stdio(false);
  long long i, j;
  cin >> n >> m >> a >> d;
  for (i = 0; i < m; ++i) cin >> t[i];
  sort(t, t + m);
  char type;
  long long div = (d + a - 1) / a * a, k;
  if (a < t[0])
    type = 'a';
  else
    type = 't';
  j = a;
  i = 0;
  while (i < m) {
    if (type == 'a') {
      while (i < m && (t[i] - j) % div <= d && t[i] - (t[i] - j) % div <= n * a)
        ++i;
      if (i >= m) {
        ans += (n * a - j) / div + 1;
        break;
      }
      k = min(t[i], n * a);
      ans += (k - j) / div + 1;
      type = 't';
    }
    if (type == 't' && i < m) {
      ++ans;
      k = i;
      while (i < m && t[k] + d >= t[i]) ++i;
      j = ((t[k] + d) / a + 1) * a;
      if (i >= m) {
        if (j <= n * a) ans += (n * a - j) / div + 1;
        break;
      }
      if (j <= n * a && j < t[i])
        type = 'a';
      else
        type = 't';
    }
  }
  cout << ans << endl;
  return 0;
}
