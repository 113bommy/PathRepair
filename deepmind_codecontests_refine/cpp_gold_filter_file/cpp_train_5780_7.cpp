#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  long n, m, p, q;
  cin >> n >> m;
  pair<pair<long, bool>, long> a[m];
  for (long i = 0; i < m; i++) {
    cin >> p >> q;
    a[i].first = make_pair(p, 1 - q);
    a[i].second = i;
  }
  sort(a, a + m);
  pair<long, long> ans[m];
  long t1, t2, t3;
  bool xx = true;
  t1 = 2;
  t2 = 2;
  t3 = 3;
  for (long i = 0; i < m; i++) {
    if (a[i].first.second == 0) {
      ans[a[i].second] = make_pair(1, t1++);
    } else {
      if (t3 >= t1) xx = false;
      ans[a[i].second] = make_pair(t2++, t3);
      if (t2 >= t3) {
        t3++;
        t2 = 2;
      }
    }
  }
  if (t1 != n + 1) xx = false;
  if (!xx)
    cout << "-1";
  else {
    for (long i = 0; i < m; i++)
      cout << ans[i].first << " " << ans[i].second << endl;
  }
  return 0;
}
