#include <bits/stdc++.h>
using namespace std;
const long long maxn = 100005;
long long n, d, b;
long long a[maxn];
bool f(long long x) {
  long long l = 1 + x;
  long long r = n - x;
  deque<pair<long long, long long>> dq;
  for (long long i = 1; i <= n; i++)
    if (a[i] != 0) dq.push_front({i, a[i]});
  long long t = 1 + x;
  while (l <= r) {
    long long left = b;
    while (left > 0) {
      if (dq.empty()) return false;
      pair<long long, long long> p = dq.back();
      dq.pop_back();
      long long amt = min(p.second, left);
      if (p.first - l > t * d) return false;
      p.second -= amt;
      left -= amt;
      if (p.second > 0) dq.push_back(p);
    }
    l++;
    if (l <= r) {
      long long right = b;
      while (right > 0) {
        if (dq.empty()) return false;
        pair<long long, long long> p = dq.front();
        dq.pop_front();
        long long amt = min(p.second, right);
        if (r - p.first > t * d) return false;
        p.second -= amt;
        right -= amt;
        if (p.second > 0) dq.push_front(p);
      }
      r--;
    }
    t++;
  }
  return true;
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> d >> b;
  for (long long i = 1; i <= n; i++) cin >> a[i];
  long long l = 0;
  long long r = n;
  while (r - l > 3) {
    long long mid = (r - l) / 2 + l;
    if (f(mid))
      r = mid;
    else
      l = mid;
  }
  for (long long i = l; i <= r; i++) {
    if (f(i)) {
      cout << i << '\n';
      break;
    }
  }
}
