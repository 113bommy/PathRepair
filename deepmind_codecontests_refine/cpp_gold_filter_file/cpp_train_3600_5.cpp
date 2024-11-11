#include <bits/stdc++.h>
#pragma gcc optimize("O3, unroll-loops")
using namespace std;
template <typename It>
ostream& outIt(ostream& out, It b, It e) {
  for (It i = b; i != e; i++) out << (i == b ? "" : " ") << *i;
  return out;
}
template <typename T>
ostream& operator<<(ostream& out, vector<T>& v) {
  return outIt(out << '[', (v).begin(), (v).end()) << ']';
}
template <typename T1, typename T2>
ostream& operator<<(ostream& out, pair<T1, T2> p) {
  return out << '(' << p.first << ", " << p.second << ')';
}
template <typename T1, typename T2>
istream& operator>>(istream& in, pair<T1, T2>& p) {
  return in >> p.first >> p.second;
}
vector<int64_t> ans;
int64_t fpow(int64_t a, int64_t b, int64_t mod) {
  int64_t ans = 1;
  if (b <= 0) return ans;
  do
    if (b & 1) ans = (int64_t)ans * a % mod;
  while (a = (int64_t)a * a % mod, b >>= 1);
  return ans;
}
int64_t invmod(int64_t a, int64_t b, int64_t mod, int64_t s0 = 0,
               int64_t s1 = 1) {
  return b ? invmod(b, a % b, mod,
                    (s1 - ((int64_t)a / b * s0) % mod + mod) % mod, s0)
           : s1;
}
signed main() {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  int64_t n;
  cin >> n;
  ans.resize(n + 1);
  ans[0] = LLONG_MAX;
  int64_t xax = invmod(7, n, n);
  for (int64_t i = 1; i <= n; i++) {
    int64_t x;
    cin >> x;
    if (n % 7 == 0) {
      if (i % 7 == 0)
        ans[i] = LLONG_MAX;
      else
        ans[i] = i + (int64_t)(x - 1) * n;
    } else {
      int64_t next = ((int64_t)xax * i * 7 - i) % (7 * n) + i;
      if (n > 2)
        assert(next >= i), assert(next % n == i % n), assert(next % 7 == 0);
      if ((next - i) / n >= x)
        ans[i] = i + (int64_t)(x - 1) * n;
      else
        x -= (next - i) / n + 1,
            ans[i] = (int64_t)(x / 6 * 7 + x % 6 + 1) * n + next;
    }
  }
  cout << min_element((ans).begin(), (ans).end()) - ans.begin() << endl;
}
