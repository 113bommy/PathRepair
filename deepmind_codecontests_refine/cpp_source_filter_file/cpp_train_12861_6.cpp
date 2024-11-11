#include <bits/stdc++.h>
using namespace std;
template <typename Arg1>
void __f(const char* name, Arg1&& arg1) {
  cerr << name << " : " << arg1 << std::endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
  const char* comma = strchr(names + 1, ',');
  cerr.write(names, comma - names) << " : " << arg1 << " | ";
  __f(comma + 1, args...);
}
template <class T>
ostream& operator<<(ostream& os, vector<T> V) {
  os << "[ ";
  for (auto v : V) os << v << " ";
  return os << "]";
}
template <class L, class R>
ostream& operator<<(ostream& os, pair<L, R> P) {
  return os << "(" << P.first << "," << P.second << ")";
}
const long long int mod = 998244353;
const long long int maxn = 200001;
long long int power(long long int x, long long int n) {
  long long int res = 1;
  for (; n > 0; n >>= 1) {
    if (n & 1) res = (res * x) % mod;
    x = (x * x) % mod;
  }
  return res;
}
long long int no_of_ways(long long int m, long long int x) {
  long long int ans = 0;
  for (long long int r = 2; r <= 100000; r++) {
    long long int maxi = r * r * r;
    if (maxi > x) break;
    ans += (x / maxi);
  }
  return ans;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int m;
  cin >> m;
  long long int l = 1, r = 1e9 + 5;
  long long int ans = -1;
  while (r - l > 1) {
    long long int mid = (l + r) / 2;
    if (no_of_ways(m, mid) >= m)
      r = mid;
    else if (no_of_ways(m, mid) < m)
      l = mid + 1;
  }
  if (no_of_ways(m, l) == m)
    ans = l;
  else if (no_of_ways(m, r) == m)
    ans = r;
  cout << ans << endl;
}
