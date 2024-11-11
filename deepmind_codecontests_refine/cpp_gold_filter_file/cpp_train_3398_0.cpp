#include <bits/stdc++.h>
using namespace std;
using namespace std;
unsigned long long n;
unsigned long long p[20];
unsigned long long k;
vector<unsigned long long> pf[2], pn[2];
void help(unsigned long long id, unsigned long long z, unsigned long long ml,
          unsigned long long cur) {
  if (id >= pn[z].size()) {
    pf[z].push_back(cur);
    return;
  }
  while (ml > 0) {
    help(id + 1, z, ml, cur);
    cur *= pn[z][id];
    ml /= pn[z][id];
  }
}
bool ch(unsigned long long x) {
  unsigned long long cnt = 0;
  unsigned long long id = 0;
  for (auto ii : pf[0]) {
    while (id < pf[1].size() && pf[1][id] <= x / ii) id++;
    cnt += id;
  }
  if (cnt < k) return true;
  return false;
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  for (unsigned long long i = 0; i < n; i++) {
    cin >> p[i];
    pn[i % 2].push_back(p[i]);
  }
  cin >> k;
  help(0, 0, 1e18, 1);
  help(0, 1, 1e18, 1);
  sort(pf[0].rbegin(), pf[0].rend());
  sort(pf[1].begin(), pf[1].end());
  for (unsigned long long i = 0; i < 2; i++) {
    for (unsigned long long j = 0; j < pf[i].size(); j++) {
    }
  }
  unsigned long long st = 1, en = 1e18, an = 1e18 + 5;
  while (st < en) {
    unsigned long long mi = (st + en) / 2;
    if (ch(mi)) {
      an = mi;
      st = mi + 1;
    } else
      en = mi;
  }
  cout << st;
  return 0;
}
