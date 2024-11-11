#include <bits/stdc++.h>
using namespace std;
long long n, cnt, a[500005], b[500005], base[65];
bool insert(long long c) {
  for (int i = 63; i >= 0; --i)
    if (c & (1 << i)) {
      if (!base[i]) {
        base[i] = c;
        return true;
      }
      c ^= base[i];
    }
  return false;
}
int main() {
  ios::sync_with_stdio(false);
  cin >> n;
  for (int i = 1; i <= n; ++i) cin >> a[i] >> b[i];
  for (int i = 1; i <= n; ++i) a[n + 1] ^= a[i], a[i] ^= b[i];
  for (int i = 1; i <= n; ++i)
    if (insert(a[i])) ++cnt;
  if (insert(a[n + 1]))
    cout << "1/1" << endl;
  else
    cout << (1ll << cnt) - 1 << '/' << (1ll << cnt) << endl;
  return 0;
}
