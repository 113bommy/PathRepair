#include <bits/stdc++.h>
using namespace std;
long long t, d, ct, q, ans, l, m, r, n, mx, mn, i, j, k, x, y, z, s;
char ch;
string ss = "", str = "";
long long a[200005], b[200005];
int main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr);
  s = k = d = l = mx = m = mn = r = q = i = j = z = x = y = ct = ans = 0;
  cin >> ss >> str;
  n = ss.length();
  m = str.length();
  vector<long long> v;
  for (i = 1; i < n; i++)
    if (ss[i] != ss[i - 1]) v.push_back(i);
  for (i = 0; i < m; i++)
    if (ss[i] != str[i]) ct++;
  ct %= 2;
  if (!ct) ans++;
  for (; i < n; i++) {
    l = lower_bound(v.begin(), v.end(), i - m + 1) - v.begin();
    long long u = upper_bound(v.begin(), v.end(), i) - v.begin();
    long long remainssame = 0, changes = 0;
    if (l < u) remainssame = u - l;
    changes = m - remainssame;
    if (changes % 2) ct = 1 - ct;
    if (!ct) ans++;
  }
  cout << ans;
  return 0;
}
