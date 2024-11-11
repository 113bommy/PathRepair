#include <bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int N = 2e5 + 5;
LL fac[20];
LL dat[N];
vector<int> get_permutation(int n, LL k) {
  vector<int> p(n);
  vector<int> res;
  iota(begin(p), end(p), 0);
  set<int> st(begin(p), end(p));
  for (int i = n - 1; i >= 0; i--) {
    int j = k / fac[i];
    k = k % fac[i];
    auto it = st.begin();
    advance(it, j);
    res.push_back(*it);
    st.erase(it);
  }
  return res;
}
LL f(LL l, LL r) {
  LL rv = r * (r + 1) / 2;
  rv -= l * (l - 1) / 2;
  return rv;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  fac[0] = 1;
  for (int i = 1; i <= 15; i++) fac[i] = fac[i - 1] * i;
  int n, q;
  cin >> n >> q;
  iota(dat + 1, dat + 1 + n, 1);
  int m = min(n, 15);
  LL k = 0;
  while (q--) {
    int t;
    cin >> t;
    if (t == 1) {
      int l, r;
      cin >> l >> r;
      LL res = 0;
      if (l <= n - m) {
        res += f(l, min(r, n - m));
      }
      if (r > n - m) {
        res += accumulate(dat + max(l, n - m + 1), dat + 1 + r, 0LL);
      }
      cout << res << "\n";
    } else {
      int x;
      cin >> x;
      k += x;
      auto v = get_permutation(m, k - 1);
      for (int i = 0; i < m; i++) dat[n - m + 1 + i] = v[i] + n - m + 1;
    }
  }
}
