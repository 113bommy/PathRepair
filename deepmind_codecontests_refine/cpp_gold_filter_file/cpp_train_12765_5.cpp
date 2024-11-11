#include <bits/stdc++.h>
using namespace std;
vector<pair<long long, long long>> vt;
vector<pair<long long, long long>> vt1;
int main() {
  long long n, m;
  long long sum = 0;
  long long ch = 0, ch1 = 0;
  long long xx = 0;
  scanf("%lld %lld", &n, &m);
  for (int i = 0; i < n; i++) {
    long long q, w, e;
    scanf("%lld %lld %lld", &q, &w, &e);
    if (w > e) {
      ch += q;
      vt.push_back({w - e, q});
    } else if (w < e) {
      ch1 += q;
      vt1.push_back({e - w, q});
    }
    if (w == e) {
      xx += q;
    }
    sum += (max(w, e) * q);
  }
  ch %= m;
  ch1 %= m;
  if (ch + ch1 > m) {
    printf("%lld\n", sum);
    return 0;
  }
  if (ch == 0 || ch1 == 0) {
    printf("%lld\n", sum);
    return 0;
  }
  if (min(m - ch, m - ch1) <= xx) {
    printf("%lld\n", sum);
    return 0;
  }
  long long oo = min(ch, m - ch1 - xx);
  long long oo1 = min(ch1, m - ch - xx);
  sort(vt.begin(), vt.end());
  sort(vt1.begin(), vt1.end());
  long long sum1 = 0, sum2 = 0, gap1 = 0, gap2 = 0;
  for (int i = 0; i < vt.size(); i++) {
    if (gap1 + vt[i].second >= ch) {
      sum1 += (vt[i].first * (ch - gap1));
      break;
    }
    gap1 += vt[i].second;
    sum1 += (vt[i].first * vt[i].second);
  }
  for (int i = 0; i < vt1.size(); i++) {
    if (gap2 + vt1[i].second >= ch1) {
      sum2 += (vt1[i].first * (ch1 - gap2));
      break;
    }
    gap2 += vt1[i].second;
    sum2 += (vt1[i].first * vt1[i].second);
  }
  printf("%lld\n", sum - min(sum1, sum2));
}
