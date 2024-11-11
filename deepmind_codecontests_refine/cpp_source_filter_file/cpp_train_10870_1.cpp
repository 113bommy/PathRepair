#include <bits/stdc++.h>
using namespace std;
vector<pair<long long, long long> > preval;
long long w, m, k;
void store() {
  long long mx = 0, pref = 9, pres = 0, i = 0;
  while (mx <= 10000000000000000l) {
    preval.push_back(make_pair(pref, pref + pres));
    mx = preval[i].second;
    pres = pref + pres;
    pref *= 10;
    i++;
  }
}
long long solve() {
  long long res = 0, cnt;
  for (long long i = 0; i < preval.size(); i++) {
    if (m <= preval[i].second) {
      cnt = preval[i].second - m + 1;
      cnt *= (k * (i + 1));
      if (w >= cnt) {
        w -= cnt;
        res += preval[i].second - m + 1;
        if (w == 0) return res;
      } else {
        res += (w / (k * (i + 1)));
        return res;
      }
      m = preval[i].second + 1;
    }
  }
  return res;
}
int main(void) {
  cout.sync_with_stdio(false);
  store();
  cin >> w >> m >> k;
  cout << solve() << "\n";
  return 0;
}
