#include <bits/stdc++.h>
using namespace std;
int n, mnPre[(100005)], mxPre[(100005)], mnSuf[(100005)], mxSuf[(100005)];
pair<int, int> a[2][(100005)];
long long solve(int ax) {
  sort(a[ax] + 1, a[ax] + 1 + n);
  for (int i = 1; i <= n; ++i) {
    mnPre[i] = min(mnPre[i - 1], a[ax][i].second);
    mxPre[i] = max(mxPre[i - 1], a[ax][i].second);
  }
  for (int i = n; i >= 1; --i) {
    mnSuf[i] = min(mnSuf[i + 1], a[ax][i].second);
    mxSuf[i] = max(mxSuf[i + 1], a[ax][i].second);
  }
  long long r = (1LL << 60) - 1;
  long long m = 0;
  int mn, mx;
  for (int i = 59; i >= 0; --i) {
    bool allowed = 0;
    m = r - (1LL << i);
    allowed = (1LL * (a[ax][n].first - a[ax][1].first) *
               (a[ax][n].first - a[ax][1].first)) <= m;
    for (int en = 1, st = 1; en <= n && !allowed; ++en) {
      while ((1LL * (a[ax][en].first - a[ax][st].first) *
              (a[ax][en].first - a[ax][st].first)) > m)
        ++st;
      mn = min(mnPre[st - 1], mnSuf[en + 1]);
      mx = max(mxPre[st - 1], mxSuf[en + 1]);
      allowed = (1LL * (mx - mn) * (mx - mn)) <= m &&
                max((1LL * (mn) * (mn)), (1LL * (mx) * (mx))) +
                        max((1LL * (a[ax][en].first) * (a[ax][en].first)),
                            (1LL * (a[ax][st].first) * (a[ax][st].first))) <=
                    m;
    }
    if (allowed) r -= (1LL << i);
  }
  return r;
}
int main() {
  scanf("%d", &n);
  for (int i = 1, x, y; i <= n; ++i) {
    scanf("%d%d", &x, &y);
    a[0][i] = {x, y}, a[1][i] = {y, x};
  }
  printf("%I64d", min(solve(0), solve(1)));
}
