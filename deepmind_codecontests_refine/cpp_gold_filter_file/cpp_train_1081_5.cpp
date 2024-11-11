#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC target("sse4")
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  vector<long long> a(n + 1), b(n + 1);
  deque<pair<long long, long long> > lines;
  for (int i = 1; i <= n; i++) cin >> a[i];
  for (int i = 1; i <= n; i++) cin >> b[i];
  lines.push_back({b[1], 0});
  long long ans = 0;
  for (int i = 2; i <= n; i++) {
    while (lines.size() > 1) {
      pair<long long, long long> c = lines[0], d = lines[1];
      if (a[i] >= (d.second - c.second) / (c.first - d.first))
        lines.pop_front();
      else
        break;
    }
    long long g = lines.front().first, h = lines.front().second;
    ans = a[i] * g + h;
    while (lines.size() > 1) {
      pair<long long, long long> c = lines[lines.size() - 1],
                                 d = lines[lines.size() - 2];
      long long x =
          (d.second - c.second + (c.first - d.first)) / (c.first - d.first);
      if (c.first - b[i] >= (ans - c.second + x - 1) / x)
        lines.pop_back();
      else
        break;
    }
    lines.push_back({b[i], ans});
  }
  cout << ans << endl;
  return 0;
}
