#include <bits/stdc++.h>
using namespace std;
const long long inf = 2e9;
const int N = 2e5 + 5;
const int M = 1 << 17;
const int mod = 1e9 + 7;
int n, m, k, T, t, op, len;
long long a[N], ans;
vector<int> v;
set<long long> s;
mt19937_64 mt(chrono::steady_clock::now().time_since_epoch().count());
void getfac(long long x) {
  for (long long i = 2; i <= (long long)sqrt(x); i++) {
    if (x % i == 0) {
      s.insert(i);
      while (x % i == 0) x /= i;
    }
  }
  if (x > 1) s.insert(x);
}
long long check(long long x) {
  long long res = 0;
  for (int i = 1; i <= n; i++) {
    if (a[i] <= x)
      res += (x - a[i]);
    else
      res += min(x - a[i] % x, a[i] % x);
    if (res > ans) return res;
  }
  return res;
}
void solve() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%lld", &a[i]), v.push_back(i);
  ans = n;
  shuffle(v.begin(), v.end(), mt);
  for (int i = 0; i < 100 && i < n; i++) {
    for (int j = -1; j <= 1; j++) getfac(a[v[i]] + j);
  }
  s.insert(2);
  s.insert(3);
  for (auto e : s) {
    ans = min(ans, check(e));
  }
  printf("%lld\n", ans);
}
int main() {
  solve();
  return 0;
}
