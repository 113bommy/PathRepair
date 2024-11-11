#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int> > sweep;
int main() {
  int D, volum, m;
  scanf("%d %d %d", &D, &volum, &m);
  long long totalCost = 0;
  for (long long i = 1; i <= m; i++) {
    int x, p;
    scanf("%d %d", &x, &p);
    sweep.push_back(make_pair(x, p));
    sweep.push_back(make_pair(x + volum, -p));
  }
  sweep.push_back(make_pair(D, 0));
  sort(sweep.begin(), sweep.end());
  multiset<int> tap;
  int pos = 0, cur_vol = volum;
  for (__typeof(sweep).begin() it = (sweep).begin(); it != (sweep).end();
       it++) {
    int x = (*it).first;
    int cost = (*it).second;
    if (pos + cur_vol >= x) {
      cur_vol -= x - pos;
      pos = x;
    } else
      pos = pos + cur_vol;
    if (pos != x) {
      if (tap.empty()) {
        cout << -1;
        return 0;
      }
      totalCost += 1LL * (x - pos) * (*tap.begin());
      pos = x;
      cur_vol = 0;
    }
    if (cost == 0) break;
    if (cost > 0)
      tap.insert(cost);
    else
      tap.erase(tap.lower_bound(-cost));
  }
  printf("%I64d", totalCost);
}
