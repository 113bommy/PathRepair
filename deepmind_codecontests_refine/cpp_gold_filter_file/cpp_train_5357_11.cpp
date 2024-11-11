#include <bits/stdc++.h>
using namespace std;
bool h[1001];
int main() {
  int p, q, l, r, t = 0;
  cin >> p >> q >> l >> r;
  pair<int, int> x[p], y[q];
  for (int i = 0; i < p; i++) {
    cin >> x[i].first >> x[i].second;
  }
  for (int i = 0; i < q; i++) {
    cin >> y[i].first >> y[i].second;
  }
  for (int i = 0; i < q; i++) {
    for (int j = 0; j < p; j++) {
      for (int o = max(l, x[j].first - y[i].second);
           o <= min(r, x[j].second - y[i].first); o++)
        h[o] = true;
    }
  }
  for (int i = l; i <= r; i++)
    if (h[i]) t++;
  cout << t << endl;
  return 0;
}
