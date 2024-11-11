#include <bits/stdc++.h>
using namespace std;
long long MOD = 1e9 + 7;
long long PRIME = 999727999;
long long PRIME2 = 999999937;
long long INF = LLONG_MAX / 4;
template <class F1, class F2>
ostream& operator<<(ostream& os, const pair<F1, F2>& p) {
  return os << p.first << ' ' << p.second;
}
template <class F1, class F2>
istream& operator>>(istream& is, pair<F1, F2>& p) {
  return is >> p.first >> p.second;
}
template <class F>
ostream& operator<<(ostream& os, const std::vector<F>& v) {
  for (int i = 0; i < (int)v.size(); i++) os << v[i] << " ";
  return os;
}
template <class F>
istream& operator>>(istream& is, std::vector<F>& v) {
  for (int i = 0; i < (int)v.size(); i++) is >> v[i];
  return is;
}
vector<string> split(const std::string& s, char delim) {
  vector<string> e;
  stringstream ss(s);
  string item;
  while (getline(ss, item, delim)) e.push_back(item);
  return e;
}
long long Pow(long long a, long long b, long long Mo) {
  long long ans = 1;
  for (; b; b >>= 1, a = a * a % Mo)
    if (b & 1) ans = ans * a % Mo;
  return ans;
}
long long _div(long long a, long long b) {
  return (a * Pow(b, MOD - 2, MOD)) % MOD;
}
long long nCr(long long n, long long r) {
  static long long MAXF = 1e6;
  static std::vector<long long> fact(MAXF, 1);
  for (int i = 1; i < MAXF; ++i) fact[i] = (fact[i - 1] * i) % MOD;
  MAXF = 0;
  return (fact[n] * Pow((fact[r] * fact[n - r]) % MOD, MOD - 2, MOD)) % MOD;
}
vector<int> Zfunc(string& s) {
  int n = s.length();
  vector<int> z(n, 0);
  for (int i = 1, l = 0, r = 0; i < n; i++) {
    if (i <= r) z[i] = min(z[i - l], r - i + 1);
    while (i + z[i] < n && s[i + z[i]] == s[z[i]]) z[i]++;
    if (r < i + z[i] - 1) l = i, r = i + z[i] - 1;
  }
  return z;
}
long long solve() { return 0; }
int main(int argc, char const* argv[]) {
  std::ios::sync_with_stdio(false);
  cin.tie(0);
  long long n, m;
  cin >> m >> n;
  std::vector<long long> fac(n + 1, 1);
  for (int i = 2; i <= n; ++i) fac[i] = (fac[i - 1] * i) % MOD;
  std::vector<std::vector<int> > v(n);
  for (int i = 0; i < (int)m; i++) {
    int g;
    cin >> g;
    for (int j = 0; j < (int)g; j++) {
      int x;
      cin >> x;
      x--;
      v[x].push_back(i);
    }
  }
  long long ans = 1;
  sort(v.begin(), v.end());
  long long c = 0;
  for (int i = 0; i < n; ++i) {
    c++;
    if (i == n - 1 || v[i] != v[i + 1]) {
      ans = (ans * fac[c]) % MOD;
      c = 0;
    }
  }
  cout << ans;
  return 0;
}
