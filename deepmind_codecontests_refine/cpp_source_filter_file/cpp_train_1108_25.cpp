#include <bits/stdc++.h>
using namespace std;
long long modexpo(long long x, long long p) {
  long long res = 1;
  x = x % 1000000007;
  while (p) {
    if (p % 2) res = res * x;
    p >>= 1;
    x = x * x % 1000000007;
    res %= 1000000007;
  }
  return res;
}
struct compare {
  bool operator()(const pair<long long, long long> a,
                  const pair<long long, long long> b) const {
    return a.first < b.first;
  }
};
const long long nax = 5e5 + 5;
long long n, r, k;
vector<long long> a(nax, 0), p(nax, 0), v(nax, 0);
bool check(long long x) {
  long long cur = 0, have = k;
  vector<long long> tot(n + 5, 0);
  for (long long i = 1; i <= n; i++) {
    cur += tot[i];
    if (v[i] + cur < x) {
      long long need = x - v[i] - cur;
      if (need > have) {
        return false;
      }
      long long temp = min(i + r, n);
      tot[temp + 1] = -need;
      cur += need;
      have -= need;
    }
  }
  return true;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> r >> k;
  for (long long i = 1; i <= n; i++) {
    cin >> a[i];
    p[i] += p[i - 1] + a[i];
  }
  for (long long i = 1; i <= n; i++) {
    long long x = p[max(0LL, i - r - 1)];
    long long y = p[min(i + r, n)];
    v[i] = y - x;
  }
  long long low = 0, high = 1e18, res = 0;
  while (low <= high) {
    long long mid = (low + high) >> 1;
    if (check(mid)) {
      low = mid + 1;
      res = max(res, mid);
    } else {
      high = mid - 1;
    }
  }
  cout << res << "\n";
}
