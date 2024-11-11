#include <bits/stdc++.h>
using namespace std;
vector<pair<int, long double> > v[100];
long double sz[100];
int num[100];
int main() {
  int n, m, w;
  cin >> n >> w >> m;
  long double now = 0, mx = (n * w * 1.0) / m;
  int st = 1;
  for (int i = 1; i <= m; ++i) sz[i] = 0;
  for (int i = 0; i <= n;) {
    if (now < 1e-11) {
      now = w;
      ++i;
      continue;
    }
    long double x = min(mx - sz[st], now);
    sz[st] += x;
    now -= x;
    v[st].push_back({i, x});
    ++num[i];
    if (num[i] > 2) {
      cout << "NO" << endl;
      return 0;
    }
    if (sz[st] > mx - 1e-11) ++st;
  }
  puts("YES");
  cout << setprecision(6) << fixed;
  for (int i = 1; i <= m; ++i) {
    for (auto x : v[i]) cout << x.first << " " << x.second << " ";
    cout << endl;
  }
}
