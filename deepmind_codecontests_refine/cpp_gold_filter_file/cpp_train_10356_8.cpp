#include <bits/stdc++.h>
using namespace std;
const int maxn = 5000010, Inf = 1000000000;
const long double Eps = 1e-12;
int n, m;
pair<int, int> seg[maxn * 2];
int main() {
  scanf("%d%d", &n, &m);
  long long ans = 0;
  for (int b = 1; b <= n; b++) {
    long long maxs = (long long)b * b - 1;
    long long mins = max((long long)b * b - m, 0LL);
    ans += 2 * (maxs - mins + 1);
    if (mins == 0) ans--;
    int maxsq = (int)floor(sqrt((long double)maxs) + Eps);
    while ((long long)(maxsq + 1) * (maxsq + 1) <= maxs) maxsq++;
    while ((long long)maxsq * maxsq > maxs) maxsq--;
    int minsq = (int)floor(sqrt((long double)mins) - Eps) + 1;
    while (minsq != 0 && (long long)(minsq - 1) * (minsq - 1) >= mins) minsq--;
    while ((long long)minsq * minsq < mins) minsq++;
    seg[b * 2 - 1].first = -b + minsq;
    seg[b * 2 - 1].second = -b + maxsq;
    seg[b * 2].first = -b - maxsq;
    seg[b * 2].second = -b - max(1, minsq);
  }
  for (int i = 1; i <= 2 * n; i++) ans -= seg[i].second - seg[i].first + 1;
  sort(seg + 1, seg + 1 + 2 * n);
  for (int i = 1, L = seg[1].first, R = -Inf; i <= 2 * n; i++) {
    R = max(R, seg[i].second);
    if (i == 2 * n || seg[i + 1].first > R) {
      ans += R - L + 1;
      if (i != 2 * n) L = seg[i + 1].first;
    }
  }
  cout << ans << endl;
  return 0;
}
