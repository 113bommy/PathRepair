#include <bits/stdc++.h>
using namespace std;
void GO() {
  ios_base::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
}
const long long INF = 1e18;
const long long mod = (1e9) + 7;
const int maxn = (int)2001;
const long double PI = acos(-1.0);
const long double eps = 0.000000001;
mt19937 rnd(time(0));
void solve() {
  int n, m;
  cin >> n >> m;
  vector<long long> a(n);
  for (auto &i : a) cin >> i;
  vector<long long> b(m);
  for (auto &i : b) cin >> i;
  vector<long long> sort_b = b;
  sort(sort_b.begin(), sort_b.end());
  sort_b.push_back(INF);
  vector<long long> kol(n + 1);
  for (int _ = 0; _ < n + 1; ++_) {
    int l = -1, r = m;
    while (r - l > 1) {
      int mid = r + l >> 1, ost = _;
      long long sum = sort_b[mid];
      multiset<long long> st;
      bool f = 1;
      for (int i = 0; i < n; ++i) {
        st.insert(a[i]);
        sum += a[i];
        while (sum < 0 && int(st.size())) {
          sum -= *st.begin();
          ost--, st.erase(st.begin());
        }
        if (sum < 0) {
          f = 0;
          break;
        }
      }
      if (ost < 0) f = 0;
      (f ? r : l) = mid;
    }
    kol[_] = sort_b[r];
  }
  reverse(kol.begin(), kol.end());
  for (int i = 0; i < m; ++i) {
    int j = upper_bound(kol.begin(), kol.end(), b[i]) - kol.begin() - 1;
    cout << n - j << '\n';
  }
}
signed main() {
  GO();
  int Q = 1;
  while (Q--) {
    solve();
  }
}
