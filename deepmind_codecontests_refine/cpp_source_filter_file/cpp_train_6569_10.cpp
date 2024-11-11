#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const long long mod = 1e9 + 7;
const int maxn = 1e6 + 5;
vector<pair<int, int> > p;
int main() {
  int n, h;
  while (~scanf("%d%d", &n, &h)) {
    int l, r;
    p.clear();
    for (int i = 0; i < n; ++i) {
      scanf("%d%d", &l, &r);
      p.push_back({l, r});
    }
    int da = 0;
    int ans = p[0].second - p[0].first;
    int pre = p[0].second;
    int hh = 0;
    int yh = h;
    for (int i = 1; i < n; ++i) {
      int res = p[i].first - pre;
      while (res >= h && hh < i) {
        ans += h;
        da = max(ans, da);
        ans -= p[hh + 1].first - p[hh].first;
        ans -= h;
        hh++;
        h += p[hh].first - p[hh - 1].second;
      }
      if (hh == i) {
        h = yh;
        ans += p[i].second - p[i].first;
        pre = p[i].second;
        continue;
      }
      ans += res;
      h -= res;
      ans += p[i].second - p[i].first;
      pre = p[i].second;
    }
    if (h) ans += h;
    da = max(ans, da);
    printf("%d\n", da);
  }
}
