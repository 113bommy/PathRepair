#include <bits/stdc++.h>
#pragma GCC optimize("-O2")
using namespace std;
void err(istream_iterator<string> it) { cerr << endl; }
template <typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
  cerr << *it << " = " << a << "\t";
  err(++it, args...);
}
template <typename T1, typename T2>
ostream& operator<<(ostream& c, pair<T1, T2>& v) {
  c << "(" << v.first << "," << v.second << ")";
  return c;
}
template <template <class...> class TT, class... T>
ostream& operator<<(ostream& out, TT<T...>& c) {
  out << "{ ";
  for (auto& x : c) out << x << " ";
  out << "}";
  return out;
}
const int LIM = 1e2 + 5, MOD = 1e9 + 7;
int t, n, m, k, x, y, w;
int f[LIM];
int mu[LIM], is_com[LIM];
vector<int> pr;
void sieve() {
  mu[1] = 1;
  for (int i = 2; i < LIM; ++i) {
    if (!is_com[i]) pr.push_back(i), mu[i] = -1;
    for (auto& it : pr) {
      if (it * i >= LIM) break;
      is_com[i * it] = 1;
      if (i % it == 0) {
        mu[i * it] = 0;
        break;
      } else {
        mu[i * it] = mu[i] * mu[it];
      }
    }
  }
}
inline long long powm(long long x, long long pw, long long Mod = MOD) {
  x %= Mod;
  long long res = 1;
  while (pw) {
    if (pw & 1LL) res = ((res * x)) % Mod;
    pw >>= 1;
    x = ((x * x)) % Mod;
  }
  return res;
}
inline long long inv(long long x, long long Mod = MOD) {
  return powm(x, Mod - 2, Mod);
}
long long fun(int x) {
  if (x == 0) return 0;
  long long ans = powm(2, x) + MOD - 1;
  ans %= MOD;
  ans = ans * (n - x) % MOD;
  return ans;
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  sieve();
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> x;
    for (int i = 1; i <= x; ++i) {
      if (i * i > x) break;
      if (x % i == 0) {
        f[i]++;
        if (x / i != i) f[x / i]++;
      }
    }
  }
  long long ans = 0;
  for (int i = 1; i < LIM; ++i) {
    ans += mu[i] * fun(f[i]);
    ans %= MOD;
    ans += MOD;
    ans %= MOD;
  }
  cout << (MOD - ans) % MOD << '\n';
  return 0;
}
