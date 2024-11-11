#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, i, p, x, ans;
  string str;
  cin >> str;
  cin >> m;
  n = str.size();
  vector<int> v(2 * n);
  for (i = 0; i < n; i++) v[i] = str[i] - '0', v[i + n] = v[i];
  vector<int> po(n);
  po[0] = 1;
  for (i = 1; i < n; i++) po[i] = (po[i - 1] * 10) % m;
  p = 0;
  for (i = 0; i < n; i++) p *= 10, p += v[i], p %= m;
  ans = p;
  for (i = 0; i < n; i++) {
    x = (v[i] * po[n - 1]) % m;
    p = (p - x + m) % m;
    p *= 10, p += v[i + n], p %= m;
    if (v[i + 1] > 0) ans = min(ans, p);
  }
  cout << ans << endl;
}
