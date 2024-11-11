#include <bits/stdc++.h>
using namespace std;
int main() {
  std::ios::sync_with_stdio(false);
  cin.tie(0);
  int m, n, ans = 0;
  cin >> m;
  vector<int> q(m);
  for (auto &i : q) cin >> i;
  cin >> n;
  vector<int> a(n);
  for (auto &i : a) cin >> i;
  sort(q.begin(), q.end());
  sort(a.rbegin(), a.rend());
  for (int i = 0, ctr = q[0]; i < n;) {
    if (ctr) {
      ans += a[i];
      ctr--;
      i++;
    } else {
      if (i + 2 < n)
        i += 2;
      else
        break;
      ctr = q[0];
    }
  }
  cout << ans << "\n";
  return 0;
}
