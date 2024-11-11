#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, i, r, av, ans = 0, req = 0, al;
  cin >> n >> r >> av;
  pair<long long, long long> p[n];
  for (i = 0; i < n; i++) {
    cin >> p[i].second >> p[i].first;
    req += p[i].first;
  }
  sort(p, p + n);
  req = n * av - req;
  if (req <= 0) {
    cout << "0";
    return 0;
  }
  for (i = 0; i < n; i++) {
    al = r - p[i].second;
    ans += p[i].first * (min(req, al));
    req -= min(al, req);
    if (req == 0) break;
  }
  cout << ans;
}
