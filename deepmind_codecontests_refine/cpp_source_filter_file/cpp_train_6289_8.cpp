#include <bits/stdc++.h>
using namespace std;
long long n, m, k;
long long b[100005];
long long p[100005];
pair<long long, long long> isOk(int t, long long kk) {
  int st = (int)m - t;
  long long tot = 0;
  for (int i = st; i < m; ++i) {
    if (b[i - st] >= p[i]) {
      tot += p[i];
    } else if (b[i - st] + kk >= p[i]) {
      tot += b[i - st];
      kk -= (p[i] - b[i - st]);
    } else {
      return {0, 0};
    }
  }
  return {t, max(0LL, tot - kk)};
}
int main() {
  cin >> n >> m >> k;
  for (int i = 0; i < n; ++i) {
    cin >> b[i];
  }
  for (int i = 0; i < m; ++i) {
    cin >> p[i];
  }
  sort(b, b + n, greater<long long>());
  sort(p, p + m, greater<long long>());
  int r = 0, s = 0, l = 0, h = n, mid;
  while (l <= h) {
    mid = (l + h + 1) / 2;
    auto res = isOk(mid, k);
    if (res.first > r) {
      r = res.first;
      s = res.second;
      l = mid + 1;
    } else {
      h = mid - 1;
    }
  }
  cout << r << " " << s << endl;
  return 0;
}
