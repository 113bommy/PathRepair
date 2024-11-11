#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 100;
int L, n, p, t, lp[N], rp[N], ed[N];
long long add[N];
pair<int, int> seg[N];
long long mx[N];
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> L >> n >> p >> t;
  for (int i = 1; i <= n; i++) {
    cin >> seg[i].first >> seg[i].second;
  }
  seg[++n].first = L + t + 1;
  seg[n].second = L + t + 1;
  sort(seg + 1, seg + n + 1);
  for (int i = 1; i <= n; i++) {
    lp[i] = seg[i].first;
    rp[i] = seg[i].second;
  }
  for (int i = 1; i <= n; i++) {
    mx[i] = (rp[i] - lp[i]) / p;
    ed[i] = lp[i] + mx[i] * p;
  }
  for (int i = 1; i <= n; i++) {
    int tmp = 0, edd;
    add[i] = max(add[i], add[i - 1]);
    tmp = (rp[i] - lp[i]) / p;
    edd = lp[i] + tmp * p;
    tmp += add[i];
    if (tmp > mx[i] || (tmp == mx[i] && edd < ed[i])) {
      mx[i] = tmp;
      ed[i] = edd;
    }
    int nxt = lower_bound(rp + 1, rp + n + 1, ed[i] + t) - rp;
    if (nxt > n) continue;
    if (lp[nxt] <= ed[i] + t) {
      tmp = (rp[nxt] - (ed[i] + t)) / p;
      edd = (ed[i] + t) + tmp * p;
      tmp += mx[i];
      if (tmp > mx[nxt] || (tmp == mx[nxt] && edd < ed[nxt])) {
        mx[nxt] = tmp;
        ed[nxt] = edd;
      }
      add[nxt + 1] = max(add[nxt + 1], mx[i]);
    } else {
      add[nxt] = max(add[nxt + 1], mx[i]);
    }
  }
  cout << mx[n] << '\n';
  return 0;
}
