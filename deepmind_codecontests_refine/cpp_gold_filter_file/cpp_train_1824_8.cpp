#include <bits/stdc++.h>
using namespace std;
template <typename T, typename U>
ostream& operator<<(ostream& os, const pair<T, U>& _p) {
  return os << "(" << _p.first << "," << _p.second << ")";
}
template <typename T>
ostream& operator<<(ostream& os, const vector<T>& _V) {
  bool f = true;
  os << "[";
  for (auto v : _V) {
    os << (f ? "" : ",") << v;
    f = false;
  }
  return os << "]";
}
template <typename T>
ostream& operator<<(ostream& os, const set<T>& _S) {
  bool f = true;
  os << "(";
  for (auto s : _S) {
    os << (f ? "" : ",") << s;
    f = false;
  }
  return os << ")";
}
template <typename T, typename U>
ostream& operator<<(ostream& os, const map<T, U>& _M) {
  return os << set<pair<T, U>>(_M.begin(), _M.end());
}
const signed long long INF = 1000000100;
const long double EPS = 1e-9;
signed long long mod = 1000000007;
signed long long cp(pair<signed long long, signed long long> a,
                    pair<signed long long, signed long long> b) {
  return (a.first * b.second - a.second * b.first);
}
signed long long tri_area(pair<signed long long, signed long long> a,
                          pair<signed long long, signed long long> b,
                          pair<signed long long, signed long long> c) {
  return (cp(a, b) + cp(b, c) + cp(a, c)) % mod;
}
signed long long area(vector<pair<signed long long, signed long long>>& v) {
  signed long long ret = 0;
  for (int(i) = (0); (i) <= (int(v.size()) - 2); (i)++) {
    ret = (ret + cp(v[i], v[i + 1])) % mod;
  }
  ret = (ret + cp(v.back(), v[0])) % mod;
  return ret;
}
const int MAXN = 500042;
signed long long C[MAXN], C2[MAXN];
int main() {
  ios_base::sync_with_stdio(0);
  int n;
  cin >> n;
  vector<pair<signed long long, signed long long>> v(n);
  for (int(i) = (0); (i) < (n); (i)++) cin >> v[i].first >> v[i].second;
  for (int(i) = (0); (i) < (n); (i)++) {
    C[i] = cp(v[i], v[(i + 1) % n]);
    C2[i + 1] = (C[i] + C2[i]);
  }
  signed long long S = (-C2[n]);
  signed long long ans = (n * (n - 3LL) / 2) % mod;
  ans = (ans * (S % mod)) % mod;
  signed long long temp = 0;
  int j = 0;
  signed long long cur = 0;
  signed long long sum_product = 0, sum_product2 = 0;
  signed long long sx = 0, sy = 0;
  for (int(i) = (0); (i) < (n); (i)++) {
    if (i) sx -= v[i].first;
    if (i) sy -= v[i].second;
    while (42) {
      signed long long bleh = (cur - (cp(v[(j + 1) % n], v[i])) - (C[j % n]));
      if (bleh + (j + 1 >= n) > S - bleh) break;
      cur -= C[j % n];
      sum_product -= C[j % n];
      sum_product2 -= (C[j % n] % mod) * (j + 1);
      sum_product2 %= mod;
      sum_product %= mod;
      j++;
      sx += v[j % n].first;
      sy += v[j % n].second;
    }
    temp += sum_product * (j + 1) - sum_product2 -
            (cp(make_pair(sx % mod, sy % mod), v[i]) % mod);
    temp %= mod;
    cur += C[i];
    sum_product += C[i];
    sum_product2 += (C[i] % mod) * (i + 1);
    sum_product2 %= mod;
    sum_product %= mod;
  }
  cout << ((ans - 2 * temp) % mod + mod) % mod << "\n";
  return 0;
}
