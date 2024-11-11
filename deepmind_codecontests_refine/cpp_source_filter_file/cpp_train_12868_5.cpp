#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  int long long n;
  cin >> n;
  vector<int long long> a(n), b(n, 0), c(n, 0), d(n), e(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  int long long p = 0;
  for (int i = 0; i < n; i++) {
    if (a[i] <= p)
      b[i] = b[i - 1] + p - a[i] + 1, p++;
    else if (i == 0)
      p = a[i];
    else
      b[i] = b[i - 1], p = a[i];
    d[i] = p;
  }
  p = 0;
  reverse(a.begin(), a.end());
  for (int i = 0; i < n; i++) {
    if (a[i] <= p)
      c[i] = c[i - 1] + p - c[i] + 1, p++;
    else if (i == 0)
      p = a[i];
    else
      c[i] = c[i - 1], p = a[i];
    e[i] = p;
  }
  reverse(a.begin(), a.end());
  reverse(c.begin(), c.end());
  reverse(e.begin(), e.end());
  int long long ans = 100000000000000000ll;
  for (int i = 1; i < n - 1; i++) {
    ans = min(ans, b[i - 1] + c[i + 1] +
                       max(max(0ll, e[i + 1] - a[i] + 1), d[i - 1] - a[i] + 1));
  }
  cout << min(ans, min(c[0], b[n - 1])) << endl;
}
