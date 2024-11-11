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
  cin >> n >> d >> k;
  if (d > 2 * k || (k == 1 && n > 2)) return cout << -1, 0;
  for (i = 1; i <= k; i++) cout << i << " " << i + 1 << "\n";
  if (k == d) {
    long long rem = n - k - 1;
    for (j = 1; j <= rem; j++) cout << "2 " << ++i << "\n";
    return 0;
  }
  if (d - k) {
    i++;
    cout << "1 " << i << "\n";
    if (d - k - 1 >= 1) {
      for (j = 1; j <= d - k - 1; j++, i++) cout << i << " " << i + 1 << "\n";
    }
  }
  long long rem = n - 1 - d;
  long long root = 1;
  for (j = 0; j < rem; j++) cout << root << " " << ++i << "\n";
  return 0;
}
