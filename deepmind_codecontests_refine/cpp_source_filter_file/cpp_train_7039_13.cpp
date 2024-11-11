#include <bits/stdc++.h>
using namespace std;
vector<int> a;
long long maxi = 0, t, e, lef, rig, mid1, mid2;
long long w(int x) {
  a.clear();
  while (x) {
    a.push_back(x % 10);
    x /= 10;
  }
  long long ans = 0;
  for (int i = a.size() - 1; i >= 0; i--) ans = ans * 10 + (9 - a[i]);
  return ans;
}
int main() {
  int l, r;
  cin >> l >> r;
  long long st = pow(10.0, (int)log10(l * 1.0)),
            end = pow(10.0, ceil(log10(l * 1.0)));
  if (st == end) end *= 10;
  maxi = 0;
  while (st <= r) {
    lef = max(l * 1ll, st), rig = min(r * 1ll, end - 1);
    while (lef < rig - 2) {
      mid1 = (2 * lef + rig) / 3;
      mid2 = (2 * rig + lef) / 3;
      if (mid1 * w(mid1) > mid2 * w(mid2))
        rig = mid2;
      else
        lef = mid1;
    }
    t = lef * w(lef);
    if (t > maxi) maxi = t;
    for (int i = max((long long)l, lef - 3); i <= min((long long)r, lef + 3);
         i++) {
      t = i * w(i);
      if (t > maxi) maxi = t;
    }
    st *= 10;
    end *= 10;
  }
  cout << maxi;
  return 0;
}
