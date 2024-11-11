#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  long long t;
  cin >> t;
  while (t--) {
    long long n, t, a, b;
    cin >> n >> t >> a >> b;
    pair<long long, long long> p[n + 1];
    long long todo_simple = 0, todo_hard = 0;
    for (long long i = 0; i < n; i++) {
      cin >> p[i].second;
      if (p[i].second == 0)
        todo_simple++;
      else {
        todo_hard++;
      }
    }
    for (long long i = 0; i < n; i++) cin >> p[i].first;
    sort(p, p + n);
    long long ans = 0;
    long long dones = 0, doneh = 0;
    for (long long i = 0; i < n; i++) {
      long long req = dones * a + doneh * b;
      long long has = p[i].first - req - 1;
      if (has >= 0) {
        long long cana = min(todo_simple - dones, has / a);
        has -= max(0ll, cana * a);
        long long canb = min(todo_hard - doneh, has / b);
        has -= max(0ll, canb * b);
        ans = max(ans, cana + canb + dones + doneh);
      }
      long long l = i;
      while (i < n && p[i].first == p[l].first) {
        if (p[l].second)
          doneh++;
        else
          dones++;
        l++;
      }
      i = l - 1;
    }
    if (dones * a + doneh * b <= t)
      cout << dones + doneh << "\n";
    else
      cout << ans << "\n";
  }
  return 0;
}
