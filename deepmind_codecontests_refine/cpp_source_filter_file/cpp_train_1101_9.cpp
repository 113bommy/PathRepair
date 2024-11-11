#include <bits/stdc++.h>
using namespace std;
int a[100005];
map<long long, int> ma;
int main() {
  int b1, q, m, l;
  cin >> b1 >> q >> l >> m;
  while (m--) {
    long long x;
    cin >> x;
    ma[x] = 1;
  }
  int ans = 0, i;
  for (i = 1; i < 100; i++) {
    if (abs(b1) > l) break;
    if (!ma[b1]) ans++;
    b1 *= q;
  }
  if (ans < 49)
    cout << ans << endl;
  else
    cout << "inf" << endl;
  return 0;
}
