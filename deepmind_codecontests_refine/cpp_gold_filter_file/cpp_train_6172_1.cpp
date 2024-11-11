#include <bits/stdc++.h>
using namespace std;
const int maxn = 600005;
int a[6], ctr[maxn];
pair<int, int> b[maxn];
int main() {
  int n, m, x, cnt = 0;
  for (int i = 0; i < 6; i++) cin >> a[i];
  cin >> n;
  m = 6 * n;
  for (int i = 0; i < n; i++) {
    cin >> x;
    for (int j = 0; j < 6; j++) b[i * 6 + j] = make_pair(x - a[j], i);
  }
  sort(b, b + m);
  int ans = b[m - 1].first;
  for (int i = 0, j = 0; j < m; j++) {
    if (!(ctr[b[j].second]++)) cnt++;
    if (cnt == n) {
      while (--ctr[b[i++].second])
        ;
      cnt--;
      ans = min(ans, b[j].first - b[i - 1].first);
    }
  }
  cout << ans << endl;
  return 0;
}
