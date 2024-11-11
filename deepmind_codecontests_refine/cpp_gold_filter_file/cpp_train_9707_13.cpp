#include <bits/stdc++.h>
using namespace std;
long long a[100005], b[100005], n;
long long power(long long a, long long b, long long m = 1000000007) {
  if (b == 0) return 1;
  if (b == 1) return a;
  long long res = power(a, b / 2, m);
  res = (res * res) % m;
  if (b & 1) res = (res * a) % m;
  return res;
}
long long modinv(long long a, long long m = 1000000007) {
  return power(a, m - 2, m);
}
long long add(long long a, long long b, long long m = 1000000007) {
  return (a + b) % m;
}
long long sub(long long a, long long b, long long m = 1000000007) {
  return (a - b + m) % m;
}
long long mul(long long a, long long b, long long m = 1000000007) {
  return (a * b) % m;
}
long long delta(long long i, long long x) {
  long long val = a[i] - 3 * x * x + 3 * x - 1;
  return val;
}
long long fun(long long x) {
  long long sum = 0;
  for (long long i = 0; i < n; i++) {
    long long low = 0, high = a[i], mid, val = 0;
    while (low <= high) {
      mid = (low + high) / 2;
      if (delta(i, mid) >= x)
        val = mid, low = mid + 1;
      else
        high = mid - 1;
    }
    sum += b[i] = val;
  }
  return sum;
}
bool comp(pair<long long, long long> a, pair<long long, long long> b) {
  return a.first > b.first;
}
void solve() {
  long long k, i;
  cin >> n >> k;
  for (i = 0; i < n; i++) cin >> a[i];
  long long low = -4e18, high = 4e18, mid, val, total;
  while (low <= high) {
    mid = (low + high) / 2;
    if (fun(mid) <= k)
      high = mid - 1, val = mid;
    else
      low = mid + 1;
  }
  total = fun(val);
  vector<pair<long long, long long> > v;
  for (i = 0; i < n; i++) v.push_back({delta(i, b[i] + 1), i});
  sort(v.begin(), v.end(), comp);
  for (i = 0; i < n; i++) {
    long long idx = v[i].second;
    if (total == k || a[idx] == b[idx]) continue;
    b[idx]++;
    total++;
  }
  for (i = 0; i < n; i++) cout << b[i] << " ";
  cout << "\n";
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t = 1;
  while (t--) solve();
  return 0;
}
