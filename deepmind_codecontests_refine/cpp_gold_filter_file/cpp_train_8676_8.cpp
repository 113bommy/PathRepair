#include <bits/stdc++.h>
using namespace std;
pair<pair<int, int>, int> a[201000];
long long n, k, c, x, y, m, ans, cnt, t, b;
int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> k >> c >> x >> y >> m;
    t = 0;
    for (int j = 0; j < k; j++) {
      if (cnt <= 200000) a[cnt++] = make_pair(make_pair(t, c), i);
      b = (c * x + y) % m;
      if (b < c && j != k - 1) t++;
      c = b;
    }
    ans = max(ans, t);
  }
  cout << ans << endl;
  if (cnt <= 200000) {
    sort(a, a + cnt);
    for (int i = 0; i < cnt; i++)
      cout << a[i].first.second << " " << a[i].second + 1 << endl;
  }
}
