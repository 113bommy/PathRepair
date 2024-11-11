#include <bits/stdc++.h>
using namespace std;
long long min(long long a, long long b) { return a > b ? b : a; }
int main() {
  long long n, m, a, b, c;
  while (~scanf("%lld%lld", &n, &m)) {
    long long ans = 0, cnt1 = 0, cnt2 = 0;
    vector<pair<long long, long long> > vec1, vec2;
    for (int i = 0; i < n; i++) {
      scanf("%lld%lld%lld", &a, &b, &c);
      if (b > c) {
        ans += a * b;
        cnt1 += a;
        vec1.push_back(make_pair(b - c, a));
      } else {
        ans += a * c;
        cnt2 += a;
        vec2.push_back(make_pair(c - b, a));
      }
    }
    if ((cnt1 % m + cnt2 % m) > m) {
      cout << ans << endl;
      continue;
    } else {
      sort(vec1.begin(), vec1.end());
      sort(vec2.begin(), vec2.end());
      long long tmp1 = cnt1 % m, tmp2 = cnt2 % m, p1 = 0, p2 = 0;
      for (int i = 0; tmp1; i++) {
        p1 += min(tmp1, vec1[i].second) * vec1[i].first;
        tmp1 -= min(tmp1, vec1[i].second);
      }
      for (int i = 0; tmp2; i++) {
        p2 += min(tmp2, vec2[i].second) * vec2[i].first;
        tmp2 -= min(tmp2, vec2[i].second);
      }
      cout << ans - min(p1, p2) << endl;
    }
  }
  return 0;
}
