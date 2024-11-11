#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353;
int add(int a, int b) { return a + b - mod * (a + b >= mod); }
int mul(int a, int b) { return int(1ll * a * b % mod); }
int power(int a, int x) {
  if (x == 0) {
    return 1;
  }
  return mul(power(mul(a, a), x >> 1), (x & 1 ? a : 1));
}
int divide(int a, int b) { return mul(a, power(b, mod - 2)); }
int sub(int a, int b) { return a - b + mod * (a < b); }
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  int n, q;
  cin >> n >> q;
  vector<int> p(n), pr(n + 1), invpr(n + 1), sum(n + 1);
  pr[n] = invpr[n] = 1;
  for (int i = 0; i < n; ++i) {
    cin >> p[i];
    p[i] = divide(100, p[i]);
  }
  for (int i = n - 1; i >= 0; --i) {
    pr[i] = mul(pr[i + 1], p[i]);
    invpr[i] = divide(1, pr[i]);
    sum[i] = add(sum[i + 1], pr[i]);
  }
  auto get_ans = [&](int l, int r) {
    return mul(sub(sum[l], sum[r + 1]), invpr[r + 1]);
  };
  int ans = get_ans(0, n - 1);
  set<int> s = {0, n};
  while (q--) {
    int x;
    cin >> x;
    --x;
    if (s.count(x)) {
      int l = *(--s.lower_bound(x)), r = *s.upper_bound(x);
      ans = sub(ans, get_ans(l, x - 1));
      ans = sub(ans, get_ans(x, r - 1));
      ans = add(ans, get_ans(l, r - 1));
      s.erase(x);
    } else {
      int l = *(--s.lower_bound(x)), r = *s.upper_bound(x);
      ans = sub(ans, get_ans(l, r - 1));
      ans = add(ans, get_ans(l, x - 1));
      ans = add(ans, get_ans(x, r - 1));
      s.insert(x);
    }
    cout << ans << '\n';
  }
  return 0;
}
