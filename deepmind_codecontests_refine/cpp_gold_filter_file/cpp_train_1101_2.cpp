#include <bits/stdc++.h>
using namespace std;
long long pref_od[100500];
long long pref_ev[100500];
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long b1, q, l, m;
  cin >> b1 >> q >> l >> m;
  if (abs(b1) > l) {
    cout << 0;
    return 0;
  }
  vector<long long> a(m);
  bool f1 = 0, f2 = 0, f3 = 0;
  unordered_set<long long> st;
  for (long long i = 0; i < m; i++) {
    cin >> a[i];
    st.insert(a[i]);
    if (a[i] == 0) f1 = 1;
    if (a[i] == b1) f2 = 1;
    if (a[i] == -b1) f3 = 1;
  }
  if (b1 == 0) {
    if (f1) {
      cout << 0;
    } else {
      cout << "inf";
    }
    return 0;
  }
  if (q == 1) {
    if (f2)
      cout << 0;
    else
      cout << "inf";
    return 0;
  }
  if (q == -1) {
    if (f2 && f3) {
      cout << 0;
    } else if (f2 && !f3 || !f2 && f3) {
      cout << "inf";
    } else if (!f2 && !f3) {
      cout << "inf";
    }
    return 0;
  }
  if (q == 0) {
    if (f1 && f2) {
      cout << 0;
    } else if (f1 && !f2) {
      cout << 1;
    } else if (!f1 && f2 || !f1 && !f2) {
      cout << "inf";
    }
    return 0;
  }
  long long ans = 0;
  while (abs(b1) <= l) {
    if (st.find(b1) == st.end()) ans++;
    b1 *= q;
  }
  cout << ans;
  return 0;
}
