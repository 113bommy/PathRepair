#include <bits/stdc++.h>
using namespace std;
void setup() {}
const long long N = 2e5 + 5;
long long n, h[N], w[N], r[N], l[N];
string s;
signed main() {
  setup();
  cin >> n;
  long long wid = 0, hi = 0;
  for (long long i = 0; i < n; wid += w[i], hi += h[i], i++) {
    cin >> w[i] >> h[i];
  }
  l[0] = h[0];
  r[n - 1] = h[n - 1];
  for (long long i = 1; i < n; i++) {
    l[i] = max(l[i - 1], h[i]);
    r[n - 1 - i] = max(r[n - i], h[n - i - 1]);
  }
  cout << r[1] * (wid - w[0]) << ' ';
  for (long long i = 1; i + 1 < n; i++) {
    long long area = wid - w[i];
    area *= max(l[i - 1], r[i + 1]);
    cout << area << ' ';
  }
  cout << l[n - 1] * (wid - w[n - 1]) << " ";
}
