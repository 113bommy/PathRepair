#include <bits/stdc++.h>
using namespace std;
long long int n, m, k, l, f, s, t, ans;
vector<int> a[10000];
int main() {
  cin >> n >> m >> k;
  for (int i = 0; i < n; i++) {
    cin >> l;
    a[l - 1].push_back(i);
  }
  for (int i = 0; i < m; i++) {
    s = 0;
    t = 0;
    f = 1;
    for (int j = 0; j < int(a[i].size()) - 1; j++) {
      t += a[i][j + 1] - a[i][j] - 1;
      f++;
      while (t > k) {
        f--;
        t -= a[i][s + 1] - a[i][s] - 1;
        s++;
      }
      if (f > ans) ans = f;
    }
  }
  cout << ans;
  return 0;
}
