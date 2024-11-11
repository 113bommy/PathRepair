#include <bits/stdc++.h>
using namespace std;
int n, m, x, y;
int a[100100], b[100100];
vector<pair<int, int> > res;
int main() {
  ios ::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> m >> x >> y;
  for (int i = 1; i <= n; i++) cin >> a[i];
  for (int i = 1; i <= m; i++) cin >> b[i];
  int p, q;
  p = q = 1;
  while (p <= n && q <= m) {
    if (a[p] - x <= b[q] && a[p] + y >= b[q]) {
      res.push_back(make_pair(p, q));
      p++;
      q++;
    } else if (a[p] - x > b[q])
      q++;
    else if (a[p] + y < b[q])
      p++;
  }
  cout << res.size() << endl;
  for (int i = 0; i < res.size(); i++)
    cout << res[i].first << ' ' << res[i].second << endl;
  return 0;
}
