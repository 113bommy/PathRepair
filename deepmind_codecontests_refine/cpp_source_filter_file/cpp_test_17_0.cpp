#include <bits/stdc++.h>
using namespace std;
template <typename T>
inline T gcd(T a, T b) {
  return b ? gcd(b, a % b) : a;
}
template <typename T>
inline T lowbit(T x) {
  return x & -x;
}
const long long N = 2e5 + 10;
long long n;
vector<long long> vec;
long long tr[N];
long long a[N];
void modify(long long x) {
  for (long long i = x; i <= n; i += lowbit(i)) tr[i]++;
}
long long query(long long x) {
  long long res = 0;
  for (long long i = x; i >= 1; i -= lowbit(i)) res += tr[i];
  return res;
}
void init() {
  for (long long i = 1; i <= n; ++i) tr[i] = 0;
}
void solve() {
  cin >> n;
  vec.clear();
  init();
  for (long long i = 1; i <= n; ++i) {
    long long x;
    scanf("%d", &x);
    a[i] = x;
    vec.push_back(x);
  }
  sort(vec.begin(), vec.end());
  vec.erase(unique(vec.begin(), vec.end()), vec.end());
  long long res = 0;
  for (long long i = 1; i <= n; ++i) {
    long long p = lower_bound(vec.begin(), vec.end(), a[i]) - vec.begin() + 1;
    long long x = query(p - 1);
    long long y = query(n) - query(p);
    res += min(x, y);
    modify(p);
  }
  cout << res << endl;
}
signed main() {
  long long _;
  cin >> _;
  while (_--) solve();
  return 0;
}
