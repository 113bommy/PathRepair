#include <bits/stdc++.h>
using namespace std;
int n, m, w[502], ms[1002], last[502];
long long res;
inline long long getsum(int beg, int end) {
  set<int> seen;
  for (int i = beg + 1; i < end; ++i) seen.insert(ms[i]);
  long long acc = 0;
  for (set<int>::iterator it = seen.begin(); it != seen.end(); ++it) acc += *it;
  return acc;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  while (cin >> n >> m) {
    res = 0;
    memset(last, 0, sizeof last);
    for (int i = 0; i < n; ++i) cin >> w[i];
    ms[0] = 0;
    for (int i = 1; i <= m; ++i) {
      cin >> ms[i];
      res += getsum(last[ms[i]], i);
      last[ms[i]] = i;
    }
    cout << res << '\n';
  }
  return 0;
}
