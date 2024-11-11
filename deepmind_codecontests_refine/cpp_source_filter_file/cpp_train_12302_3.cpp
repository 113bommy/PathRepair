#include <bits/stdc++.h>
using namespace std;
template <typename A, typename B>
ostream& operator<<(ostream& o, pair<A, B> a) {
  return o << a.first << ' ' << a.second;
}
template <typename A, typename B>
istream& operator>>(istream& o, pair<A, B>& a) {
  return o >> a.first >> a.second;
}
const int mod = 1e9 + 7, abc = 864197532, N = 300087, K = 111;
long long int modpow(long long int a, int b) {
  long long int ans = 1;
  for (; b; b >>= 1, a = a * a % mod) {
    if (b & 1) ans = ans * a % mod;
  }
  return ans;
}
int inter(vector<int> l, vector<int> r) {
  int ll = *max_element(l.begin(), l.end()),
      rr = *min_element(r.begin(), r.end());
  if (ll <= rr) return rr - ll + 1;
  return 0;
}
void add(long long int& a, long long int b) {
  a += b;
  if (a >= mod) a -= mod;
}
void del(long long int& a, long long int b) {
  a -= b;
  if (a < 0) a += mod;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> l(n), r(n), sz(n), inv(n);
  for (int i = 0; i < n; ++i) cin >> l[i];
  long long int al = 1;
  for (int i = 0; i < n; ++i) {
    cin >> r[i];
    sz[i] = r[i] - l[i] + 1;
    al = al * sz[i] % mod;
    inv[i] = modpow(sz[i], mod - 2);
  }
  long long int square = 0, sum = 0;
  for (int i = 0; i + 1 < n; ++i) {
    add(sum, inter({l[i], l[i + 1]}, {r[i], r[i + 1]}) * al % mod * inv[i] %
                 mod * inv[i + 1] % mod);
  }
  square = sum;
  for (int i = 0; i + 2 < n; ++i) {
    add(square, inter({l[i], l[i + 1], l[i + 2]}, {r[i], r[i + 1], r[i + 2]}) *
                    al % mod * inv[i] % mod * inv[i + 1] % mod * inv[i + 2] %
                    mod * 2 % mod);
  }
  long long int now = 0;
  for (int i = 0; i + 1 < n; ++i)
    add(now, inter({l[i], l[i + 1]}, {r[i], r[i + 1]}) * inv[i] % mod *
                 inv[i + 1] % mod);
  for (int i = 0; i + 1 < n; ++i) {
    if (i - 1 >= 0)
      del(now, 1ll * inter({l[i - 1], l[i]}, {r[i - 1], r[i]}) * inv[i - 1] %
                   mod * inv[i] % mod);
    del(now, 1ll * inter({l[i], l[i + 1]}, {r[i], r[i + 1]}) * inv[i] % mod *
                 inv[i + 1] % mod);
    if (i + 2 < n)
      del(now, 1ll * inter({l[i + 1], l[i + 2]}, {r[i + 1], r[i + 2]}) *
                   inv[i + 1] % mod * inv[i + 2] % mod);
    add(square, now * inter({l[i], l[i + 1]}, {r[i], r[i + 1]}) % mod * inv[i] %
                    mod * inv[i + 1] % mod * al % mod);
    if (i - 1 >= 0)
      add(now, 1ll * inter({l[i - 1], l[i]}, {r[i - 1], r[i]}) * inv[i - 1] %
                   mod * inv[i] % mod);
    add(now, 1ll * inter({l[i], l[i + 1]}, {r[i], r[i + 1]}) * inv[i] % mod *
                 inv[i + 1] % mod);
    if (i + 2 < n)
      add(now, 1ll * inter({l[i + 1], l[i + 2]}, {r[i + 1], r[i + 2]}) *
                   inv[i + 1] % mod * inv[i + 2] % mod);
  }
  cout << ((square + mod - sum * n * 2 % mod) * modpow(al, mod - 2) +
           1ll * n * n) %
              mod;
}
