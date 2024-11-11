#include <bits/stdc++.h>
using namespace std;
enum { MAXN = 100050 };
long long k, n[3], t[3];
set<pair<long long, long long> > m[3];
int main() {
  cin >> k >> n[0] >> n[1] >> n[2] >> t[0] >> t[1] >> t[2];
  long long time, nk = k;
  for (time = 0; time <= k * (t[0] + t[1] + t[2]); time++) {
    while (m[2].size() > 0 && m[2].begin()->first <= time)
      m[2].erase(*m[2].begin());
    while (m[2].size() < n[2] && m[1].size() > 0 &&
           m[1].begin()->first <= time) {
      m[2].insert(make_pair(time + t[2], m[1].begin()->second));
      m[1].erase(*m[1].begin());
    }
    while (m[1].size() < n[1] && m[0].size() > 0 &&
           m[0].begin()->first <= time) {
      m[1].insert(make_pair(time + t[1], m[0].begin()->second));
      m[0].erase(*m[0].begin());
    }
    while (nk > 0 && m[0].size() < n[0]) {
      m[0].insert(make_pair(time + t[0], nk));
      nk--;
    }
    if (nk == 0 && m[0].size() == 0 && m[1].size() == 0 && m[2].size() == 0)
      break;
  }
  cout << time;
  return 0;
}
