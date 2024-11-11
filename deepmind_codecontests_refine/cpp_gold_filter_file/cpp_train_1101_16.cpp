#include <bits/stdc++.h>
using namespace std;
map<long long, int> a;
int main() {
  long long b, q, l, m, ans = 0, x;
  cin >> b >> q >> l >> m;
  while (m--) {
    cin >> x;
    a[x] = 1;
  }
  for (int i = 0; i < 100; i++) {
    if (abs(b) > l) break;
    if (!a[b]) ans++;
    b *= q;
  }
  if (ans < 50)
    cout << ans;
  else
    cout << "inf";
}
