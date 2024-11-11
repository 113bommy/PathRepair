#include <bits/stdc++.h>
using namespace std;
int main() {
  long long x;
  scanf("%lld", &x);
  vector<pair<long long, long long> > vt;
  long long now = 1, pos = 1;
  for (long long i = 1; i <= x; i += pos * pos) {
    if (x == i) {
      vt.push_back({i, i});
    } else if ((x - i) % now == 0) {
      vt.push_back({pos, pos + (x - i) / now});
      vt.push_back({pos + (x - i) / now, pos});
    }
    now += ++pos;
  }
  sort(vt.begin(), vt.end());
  printf("%d\n", (int)vt.size());
  for (int i = 0; i < vt.size(); i++) {
    printf("%lld %lld\n", vt[i].first, vt[i].second);
  }
  return 0;
}
