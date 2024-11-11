#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 10;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int n, k, l, m, a[MAXN];
  long long sum = 0;
  cin >> n >> k >> l;
  m = n * k;
  for (int i = 0; i < m; i++) cin >> a[i];
  sort(a, a + m);
  int *p = upper_bound(a, a + m, a[0] + l);
  if (p - a < n)
    cout.put('0');
  else {
    for (int i = 0, j = 1; i < p - a, j <= n; j++) {
      sum += a[i];
      if (i + n - j >= p - a)
        i++;
      else
        i = min((int)(p - (n - j) - a), i + k);
    }
    cout << sum;
  }
  return 0;
}
