#include <bits/stdc++.h>
using namespace std;
vector<pair<long long, long long> > ans;
int main() {
  long long x, m, n, y;
  cin >> x;
  ans.clear();
  ans.push_back(make_pair((long long)1, x));
  long long b = 1, e = 1500000, md;
  while (b <= e) {
    md = (b + e) >> 1;
    if (((md + 2) * (md + 1) * (2 * md + 3)) / 6 > x &&
        (md * (md + 1) * (2 * md + 1)) / 6 <= x)
      break;
    else if ((md * (md + 1) * (2 * md + 1)) / 6 <= x)
      b = md + 1;
    else
      e = md - 1;
  }
  for (long long i = 2; i < md + 1; i++) {
    y = x + (i * i * (i - 1)) / 2 - (i * (i - 1) * (2 * i - 1)) / 6;
    n = i * i - (i * (i - 1)) / 2;
    if (y % n == 0) ans.push_back(make_pair(i, y / n));
  }
  n = ans.size();
  if (ans[n - 1].first != ans[n - 1].second) {
    m = 1;
    cout << 2 * ans.size() << endl;
  } else {
    m = 2;
    cout << 2 * n - 1 << endl;
  }
  for (typeof(ans.begin()) it = ans.begin(); it != ans.end(); it++)
    cout << (*it).first << " " << (*it).second << endl;
  for (long long i = m; i < ans.size() + 1; i++)
    cout << ans[n - i].second << " " << ans[n - i].first << endl;
}
