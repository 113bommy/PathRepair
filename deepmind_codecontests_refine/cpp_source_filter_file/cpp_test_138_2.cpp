#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
using ll = long long;
const int N = 200005, LG = 16;
int n, m, q, k, a[N], b[N], c[N << 1], ct[N << 1];
ll pf[N << 1], ans[N];
pair<int, int> qr[N];
set<int> cp;
inline ll sm(int i, int j) {
  return i > j ? 0 : (pf[j] - (i == 0 ? 0 : pf[i - 1]));
}
inline ll calc(int i) {
  auto it = cp.lower_bound(i);
  if (it == cp.begin()) {
    return sm(i - ct[i] + 1, i);
  } else {
    int j = *(--it);
    return sm(i - (ct[i] - ct[j]) + 1, i);
  }
}
inline void upd(ll &sm, int i) {
  auto it = cp.upper_bound(i);
  assert(it != cp.end());
  int j = *it;
  sm -= calc(j);
  sm -= calc(i);
  cp.erase(i);
  sm += calc(j);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  cin >> n >> m >> q;
  ll sm = 0;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    sm += a[i];
  }
  for (int j = 0; j < m; ++j) {
    cin >> b[j];
  }
  sort(a, a + n);
  sort(b, b + m);
  merge(a, a + n, b, b + m, c);
  for (int i = 0, j = 0; i < n; ++i) {
    while (c[j] != a[i]) {
      ++j;
    }
    ct[j] = 1;
  }
  int s = n + m;
  pf[0] = c[0];
  for (int i = 1; i < s; ++i) {
    pf[i] = pf[i - 1] + c[i];
    ct[i] += ct[i - 1];
  }
  for (int i = 0; i < s; ++i) {
    cp.insert(i);
  }
  set<pair<int, int> > st;
  for (int i = 0; i < s - 1; ++i) {
    st.insert({c[i + 1] - c[i], i});
  }
  for (int i = 0; i < q; ++i) {
    cin >> k;
    qr[i] = pair<int, int>{k, i};
  }
  sort(qr, qr + q);
  int curr = -1;
  for (int i = 0; i < q; ++i) {
    if (qr[i].first != curr) {
      curr = qr[i].first;
      while (!st.empty() && st.begin()->first <= curr) {
        upd(sm, st.begin()->second);
        st.erase(st.begin());
      }
    }
    ans[qr[i].second] = sm;
  }
  for (int i = 0; i < q; ++i) {
    cout << ans[i] << '\n';
  }
  return 0;
}
