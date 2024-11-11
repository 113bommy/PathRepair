#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
const long long inf = 2e18 + 3;
long long n, k;
vector<long long> a;
long long expo_pow(long long x, long long y) {
  if (y == 0) return 1;
  y = y % (mod - 1);
  x %= mod;
  if (y == 0) y = mod - 1;
  long long res = 1;
  while (y) {
    if (y & 1) res = (res * x) % mod;
    x = (x * x) % mod;
    y >>= 1;
  }
  return res;
}
bool check2(long long a, long long val, long long x) {
  long long tmp = a - 3 * x * x + 3 * x - 1;
  return tmp >= val;
}
long long get(long long a, long long val) {
  long long st = 0;
  long long end = a;
  long long ans = 0;
  while (end >= st) {
    long long mid = (st + end) / 2;
    if (check2(a, val, mid)) {
      ans = mid;
      st = mid + 1;
    } else
      end = mid - 1;
  }
  return ans;
}
bool check(long long val) {
  long long cnt = 0;
  for (long long i = 0; i < n; i++) {
    cnt += get(a[i], val);
  }
  return cnt >= k;
}
void solve() {
  cin >> n >> k;
  a.resize(n);
  for (long long i = 0; i < n; i++) {
    cin >> a[i];
  }
  long long st = -inf;
  long long end = inf;
  long long ans = -1;
  while (end >= st) {
    long long mid = (st + end) / 2;
    if (check(mid)) {
      ans = mid;
      st = mid + 1;
    } else {
      end = mid - 1;
    }
  }
  vector<long long> moves(n);
  long long sum = 0;
  for (long long i = 0; i < n; i++) {
    moves[i] = get(a[i], ans);
    sum += moves[i];
  }
  vector<pair<long long, long long> > tmp;
  for (long long i = 0; i < n; i++) {
    long long val = a[i] - 3 * moves[i] * moves[i] + 3 * moves[i] - 1;
    tmp.push_back({val, i});
  }
  sort(tmp.begin(), tmp.end());
  for (long long i = 0; i < n and sum > k; i++) {
    moves[tmp[i].second]--;
    sum--;
  }
  for (long long i = 0; i < n; i++) {
    cout << moves[i] << " ";
  }
  cout << "\n";
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long test = 1;
  long long i = 1;
  while (test--) {
    solve();
  }
}
