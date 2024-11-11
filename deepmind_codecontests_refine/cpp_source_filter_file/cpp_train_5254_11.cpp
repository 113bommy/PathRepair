#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 10;
const int mod1 = 1e16;
const int N = 2005;
const int maxn = 1e6 + 55;
double pie = 3.1415926535;
vector<int> a;
int main() {
  ios_base::sync_with_stdio(false);
  int n, i, mx, x, y, z, k, ans;
  cin >> n;
  for (i = 0; i < n; i++) cin >> x, a.push_back(x);
  sort(a.begin(), a.end());
  a.erase(unique(a.begin(), a.end()), a.end());
  int l = int(a.size());
  mx = a[l - 1];
  ans = 0;
  for (i = 0; i < l; i++) {
    x = a[i];
    k = 2;
    bool flag = true;
    while (flag == true) {
      y = x * k;
      k++;
      auto it = upper_bound(a.begin(), a.end(), y);
      if (it >= a.begin()) {
        it--;
        z = (*it) % x;
        ans = max(ans, z);
      }
      if (y >= mx) flag = false;
    }
  }
  cout << ans << endl;
}
