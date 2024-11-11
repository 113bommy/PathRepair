#include <bits/stdc++.h>
using namespace std;
struct zapr {
  long long x, y, numb;
};
long long n, x[112345], y[112345];
long long ans[112345], k, pref[112345], a[112345], b[112345];
vector<long long> v;
set<long long> st;
zapr z[112345];
long long cnt[112345];
bool cmp(zapr a, zapr b) {
  if (a.x / 500 != b.x / 500)
    return (a.x / 500) < (b.x / 500);
  else
    return a.y < b.y;
}
int main() {
  ios_base::sync_with_stdio(0);
  long long i;
  cin >> n >> k;
  for (i = 1; i <= n; i++) cin >> b[i];
  for (i = 1; i <= n; i++) {
    cin >> a[i];
    if (b[i] == 2) a[i] = -a[i];
  }
  pref[0] = 0;
  for (i = 0; i <= n; i++) {
    if (i > 0) pref[i] = pref[i - 1] + a[i];
    if (st.count(pref[i]) == 0) {
      v.push_back(pref[i]);
      st.insert(pref[i]);
    }
    if (st.count(pref[i] - k) == 0) {
      v.push_back(pref[i] - k);
      st.insert(pref[i] - k);
    }
    if (st.count(pref[i] + k) == 0) {
      v.push_back(pref[i] + k);
      st.insert(pref[i] + k);
    }
  }
  sort(v.begin(), v.end());
  for (i = 0; i <= n; i++) {
    x[i] = lower_bound(v.begin(), v.end(), pref[i] - k) - v.begin();
    y[i] = lower_bound(v.begin(), v.end(), pref[i] + k) - v.begin();
    pref[i] = lower_bound(v.begin(), v.end(), pref[i]) - v.begin();
  }
  long long m;
  cin >> m;
  for (i = 0; i < m; i++) {
    cin >> z[i].x >> z[i].y;
    z[i].numb = i;
  }
  sort(z, z + m, cmp);
  long long l = 1, r = 1;
  long long curr = 0;
  cnt[pref[0]]++;
  cnt[pref[1]]++;
  if (a[1] == k) curr++;
  for (i = 0; i < m; i++) {
    while (r < z[i].y) {
      r++;
      curr += cnt[x[r]];
      cnt[pref[r]]++;
    }
    while (l > z[i].x) {
      l--;
      curr += cnt[y[l - 1]];
      cnt[pref[l - 1]]++;
    }
    while (r > z[i].y) {
      cnt[pref[r]]--;
      curr -= cnt[x[r]];
      r--;
    }
    while (l < z[i].x) {
      cnt[pref[l - 1]]--;
      curr -= cnt[y[l - 1]];
      l++;
    }
    ans[z[i].numb] = curr;
  }
  for (i = 0; i < m; i++) cout << ans[i] << endl;
  return 0;
}
