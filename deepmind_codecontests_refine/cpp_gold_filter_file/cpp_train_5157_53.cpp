#include <bits/stdc++.h>
using namespace std;
int n, a, b;
vector<pair<int, int> > tab;
int x[4] = {0, 1, 0, -1};
int y[4] = {1, 0, -1, 0};
vector<int> tb;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for (int i = 0; i <= n; ++i) {
    cin >> a >> b;
    tab.push_back(pair<int, int>(a, b));
  }
  for (int i = 0; i < n; ++i) {
    int p1 = 0;
    for (int j = 0; j < 4; ++j) {
      if (x[j] && ((tab[i + 1].first - tab[i].first) / x[j]) > 0) p1 = j;
      if (y[j] && ((tab[i + 1].second - tab[i].second) / y[j]) > 0) p1 = j;
    }
    tb.push_back(p1);
  }
  int ans = 0;
  for (int i = 0; i < n - 1; ++i) {
    if (((tb[i] - tb[i + 1]) % 4 + 4) % 4 == 1) ans++;
  }
  cout << ans << endl;
  return 0;
}
