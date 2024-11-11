#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
long long n;
long long spr(long long a) {
  cout << "? " << a << endl;
  long long ans1;
  cin >> ans1;
  long long b = (a + n / 2) % n;
  if (b == 0) b = n;
  cout << "? " << b << endl;
  long long ans2;
  cin >> ans2;
  return ans2 - ans1;
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  if (n % 4 != 0) {
    cout << "! -1" << endl;
    return 0;
  }
  long long l = 1, r = n / 2 + 1;
  long long ans = spr(1);
  bool fl = true;
  if (ans == 0) {
    cout << "! 1" << endl;
    return 0;
  }
  if (ans > 0) {
    fl = false;
  }
  while (r - l > 1) {
    long long m = (l + r) / 2;
    long long que = spr(m);
    if (fl) {
      if (que == 0) {
        cout << "! " << m << endl;
        return 0;
      } else if (que > 0) {
        r = m;
      } else
        l = m;
    } else {
      if (que == 0) {
        cout << "! " << m << endl;
        return 0;
      } else if (que > 0) {
        l = m;
      } else
        r = m;
    }
  }
  cout << "! " << l << endl;
  return 0;
}
