#include <bits/stdc++.h>
using namespace std;
long long mas_s[500010];
long long mas_t[500010];
int32_t main() {
  ios_base::sync_with_stdio(false);
  int n;
  long long k;
  cin >> n >> k;
  string s, t;
  cin >> s >> t;
  const long long inf = 1e18;
  if (k == 1 || s == t) {
    cout << n;
    return 0;
  }
  long long an = 0;
  bool ok = false;
  for (int i = 0; i < n; i++) {
    if (s[i] < t[i] && !ok) {
      ok = true;
      an = i + 2 * (n - i);
      k -= 2;
      continue;
    }
    if (ok) {
      if (s[i] == 'a') {
        for (int j = i; j < n && j < i + 50; j++) {
          mas_s[j] = min(inf, mas_s[j] + (1ll << (j - i)));
        }
      }
      if (t[i] == 'b') {
        for (int j = i; j < n && j < i + 50; j++) {
          mas_t[j] = min(inf, mas_t[j] + (1ll << (j - i)));
        }
      }
      int can_s = min(mas_s[i], k);
      an += 1ll * can_s * (n - i);
      k -= can_s;
      for (int j = i + 1; j < n && j < i + 50; j++) {
        mas_s[j] = max(0ll, mas_s[j] - can_s);
      }
      int can_t = min(mas_t[i], k);
      an += 1ll * can_t * (n - i);
      k -= can_t;
      for (int j = i + 1; j < n && j < i + 50; j++) {
        mas_t[j] = max(0ll, mas_t[j] - can_t);
      }
    }
  }
  cout << an;
  return 0;
}
