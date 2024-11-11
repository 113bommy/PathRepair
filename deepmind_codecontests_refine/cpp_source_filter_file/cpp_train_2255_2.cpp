#include <bits/stdc++.h>
using namespace std;
long long t, d, ct, q, ans, l, m, r, n, mx, mn, i, j, k, x, y, z, s;
char ch;
string ss = "", str = "";
map<long long, long long> mp;
set<long long> st;
long long a[200003], b[200003];
int main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  s = k = d = l = mx = m = mn = r = q = i = j = z = x = y = ct = ans = 0;
  cin >> n >> q;
  cin >> a[0];
  for (i = 0; i < n - 1; i++) cin >> k, a[i] += a[i - 1] + k;
  for (i = 0; i < q; i++) cin >> b[i];
  for (i = 0; i < q; i++) {
    s += b[i];
    l = upper_bound(a, a + n, s) - a;
    if (l == n)
      cout << n << "\n", s = 0;
    else
      cout << n - l - 1 << "\n";
  }
  return 0;
}
