#include <bits/stdc++.h>
using namespace std;
int m, k, n, s, req[500010], cnt[500010], a[500010];
int cmp[500010], ans[500010];
void init() {
  for (int i = 0; i < 500010; ++i) cmp[i] = -1;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> m >> k >> n >> s;
  init();
  for (int i = 0; i < m; ++i) cin >> a[i];
  for (int i = 0; i < s; ++i) {
    int x;
    cin >> x;
    req[x]++;
  }
  int tt = 0;
  for (int i = 0; i < 500010; ++i) {
    if (req[i] > 0) tt++;
  }
  int L = 0, R = 0, curr = 0;
  while (L < m) {
    if (curr == tt) cmp[R - 1] = max(cmp[R - 1], L);
    if (curr < tt && R < m) {
      cnt[a[R]]++;
      if (cnt[a[R]] == req[a[R]] && req[a[R]]) curr++;
      R++;
    } else {
      if (cnt[a[L]] == req[a[L]] && req[a[L]]) curr--;
      cnt[a[L]]--;
      L++;
    }
  }
  int pos = -1;
  for (int i = 0; i < m; ++i) {
    if (cmp[i] == -1) continue;
    int l = cmp[i];
    int t = l / k;
    int rm = l % k;
    rm += (i - l + 1);
    int u = i + max(0, k - rm);
    if (u >= m) continue;
    t++;
    t += (m - 1 - u) / k;
    if (t >= n) {
      pos = i;
      break;
    }
  }
  int p = pos;
  if (p == -1) {
    cout << -1;
    return 0;
  }
  int l = cmp[p];
  for (int i = 0; i < 500010; ++i) cnt[i] = 0;
  for (int i = l; i <= p; i++) {
    if (cnt[a[i]] < req[a[i]]) {
      ans[i] = 1;
      cnt[a[i]]++;
    }
  }
  int kk = 0;
  for (int i = l; i <= p; i++) {
    kk += ans[i];
  }
  for (int i = l; i <= p; i++) {
    if (kk == k) break;
    if (ans[i] == 0) {
      ans[i] = 1;
      kk++;
    }
  }
  int ss = (l / k) * k;
  for (int i = ss; i < l; i++) {
    if (kk == k) break;
    ans[i] = 1;
    kk++;
  }
  int r = p + 1;
  while (kk < k) {
    ans[r] = 1;
    r++;
    kk++;
  }
  int t = min(ss / k, n - 1);
  for (int i = 0; i < t * k; ++i) {
    ans[i] = 1;
  }
  int done = t + 1;
  done = n - done;
  for (int i = r; i < r + k * done; i++) {
    ans[i] = 1;
  }
  int d = 0;
  for (int i = 0; i < m; ++i) {
    if (ans[i] == 0) d++;
  }
  cout << d << endl;
  for (int i = 0; i < m; ++i) {
    if (ans[i] == 0) cout << i + 1 << " ";
  }
  return 0;
}
