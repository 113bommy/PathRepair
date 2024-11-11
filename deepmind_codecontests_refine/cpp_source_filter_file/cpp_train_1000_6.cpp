#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 7;
long long top, n, m, num, l, r, rec, rec2, ans, k;
long long a[maxn];
pair<int, int> ps[maxn];
int main() {
  cin >> n >> m >> k;
  for (long long i = 1; i <= n; ++i) scanf("%lld", &a[i]);
  for (long long i = 1; i <= n; ++i) {
    if (!top || ps[top].first != a[i])
      ps[++top] = make_pair(a[i], 1);
    else
      ps[top].second = (ps[top].second + 1) % k;
    if (ps[top].second == 0) --top;
  }
  for (long long i = 1; i <= top; ++i) rec += ps[i].second;
  l = 1, r = top;
  while (l < r && ps[l].first == ps[r].first &&
         (ps[l].second + ps[r].second) % k == 0) {
    rec2 += ps[l].second + ps[r].second;
    l++;
    r--;
  }
  if (l == r) {
    if (ps[l].second * m % k == 0) ans -= rec2;
    ans += m * rec - rec2 * (m - 1) - (ps[l].second * m / k * k);
  } else {
    if (ps[l].first == ps[r].first)
      rec2 += (ps[l].second + ps[r].second) / k * k;
    ans = m * rec - rec2 * (m - 1);
  }
  cout << ans << endl;
  return 0;
}
