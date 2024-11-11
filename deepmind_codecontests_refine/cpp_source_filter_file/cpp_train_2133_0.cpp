#include <bits/stdc++.h>
using namespace std;
long long mid, r, a, b, tmp, m, t, l, ll;
int n;
int main() {
  ios::sync_with_stdio(false);
  cin >> a >> b >> n;
  while (n--) {
    cin >> ll >> t >> m;
    tmp = 1ll * (l - 1) * b + a;
    if (tmp > t) {
      cout << "-1\n";
      continue;
    }
    r = (t - a) / b + 1;
    l = ll;
    while (r > l) {
      mid = (l + r + 1) / 2;
      tmp = (mid - ll + 1) * a + (mid + ll - 2) * (mid - ll + 1) / 2 * b;
      if (tmp > m * t)
        r = mid - 1;
      else
        l = mid;
    }
    cout << r << '\n';
  }
}
