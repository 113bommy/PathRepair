#include <bits/stdc++.h>
using namespace std;
int gcd(int x, int y) { return y ? gcd(y, x % y) : x; }
mt19937 rnd(23352);
const int MAXN = 1e5 + 7;
int ans[MAXN];
pair<int, int> a[MAXN];
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n, g, past, v, i;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> a[i].first;
    a[i].second = i;
  }
  while (clock() < 50) {
    fill(&ans[0], &ans[0] + n, 2);
    g = 0;
    for (i = 0; i < n; ++i) {
      past = g;
      g = gcd(g, a[i].first);
      if (g != past) ans[a[i].second] = 1;
    }
    if (g == 1) {
      v = 0;
      for (i = 0; i < n; ++i) {
        if (ans[a[i].second] == 2) v = gcd(v, a[i].first);
      }
      if (v == 1) {
        cout << "YES\n";
        for (i = 0; i < n; ++i) cout << ans[i] << ' ';
        return 0;
      }
    }
    shuffle(a, a + n, rnd);
  }
  cout << "NO";
  return 0;
}
