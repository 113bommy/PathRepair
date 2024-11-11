#include <bits/stdc++.h>
using namespace std;
template <typename X>
ostream& operator<<(ostream& x, const vector<X>& v) {
  for (long long i = 0; i < v.size(); ++i) x << v[i] << " ";
  return x;
}
template <typename X>
ostream& operator<<(ostream& x, const set<X>& v) {
  for (auto it : v) x << it << " ";
  return x;
}
template <typename X, typename Y>
ostream& operator<<(ostream& x, const pair<X, Y>& v) {
  x << v.ff << " " << v.ss;
  return x;
}
template <typename T, typename S>
ostream& operator<<(ostream& os, const map<T, S>& v) {
  for (auto it : v) os << it.first << "=>" << it.second << endl;
  return os;
}
struct pair_hash {
  inline std::size_t operator()(
      const std::pair<long long, long long>& v) const {
    return v.first * 31 + v.second;
  }
};
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
const int N = 100005;
;
long long fct[N];
long long inf[N];
long long power(long long a, long long b, long long m) {
  long long ans = 1;
  while (b > 0) {
    if (b % 2) {
      ans = (ans * a) % m;
    }
    a = (a * a) % m;
    b = b / 2;
  }
  return ans;
}
long long inv(long long n) { return (power(n, 1000000007 - 2, 1000000007)); }
long long C(long long n, long long r) {
  long long aa = (fct[n] * inf[n - r]) % 1000000007;
  aa *= inf[r];
  aa %= 1000000007;
  return aa;
}
int main() {
  fct[0] = 1;
  inf[0] = 1;
  for (long long i = 1; i < N; i++) {
    fct[i] = (fct[i - 1] * i) % 1000000007;
    inf[i] = inv(fct[i]);
  }
  long long n;
  cin >> n;
  long long ans = C(2 * n - 1, n);
  ans *= 2;
  ans %= 1000000007;
  ans += 1000000007;
  ans -= n;
  ans %= 1000000007;
  cout << ans << endl;
}
