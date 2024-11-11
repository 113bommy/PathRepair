#include <bits/stdc++.h>
using namespace std;
long long n, x, y, k, ans, a[200050], u;
pair<int, int> p[200050];
bool l[200050];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  for (int i = 0; i < n; ++i)
    cin >> a[i], p[i].first = a[i], p[i].second = i, k += a[i];
  sort(a, a + n);
  sort(p, p + n);
  for (int i = 0; i < n; ++i) {
    y = k - a[i];
    x = lower_bound(a, a + n, y / 2) - a;
    if (x == i) ++x;
    if (y % 2 == 0 && y / 2 == a[x]) l[p[i].second] = 1, ++ans;
  }
  cout << ans << endl;
  for (int i = 0; i < n; ++i)
    if (l[i]) cout << i + 1 << " ";
  return 0;
}
