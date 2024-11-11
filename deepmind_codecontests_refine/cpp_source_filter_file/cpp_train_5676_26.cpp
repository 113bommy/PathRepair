#include <bits/stdc++.h>
using namespace std;
pair<long long, long long> a[100005];
bool compare(pair<long long, long long> p1, pair<long long, long long> p2) {
  if (p1.first == p2.first) return p1.second < p2.second;
  return p1.first < p2.first;
}
long long sum[100005];
long long b[100005];
long long b2[100005];
int main() {
  long long n, A, cf, cm, m;
  long long xp, xl;
  long long ans = 0;
  cin >> n >> A >> cf >> cm >> m;
  for (int i = 1; i <= n; i++) {
    cin >> a[i].first;
    a[i].second = i;
    b2[i] = a[i].first;
  }
  sort(a + 1, a + n + 1, compare);
  for (int i = 1; i <= n; i++)
    sum[i] = sum[i - 1] + a[i].first, b[i] = a[i].first;
  for (long long p = n; p >= 0; p--) {
    long long left = A * (n - p) - (sum[n] - sum[p]);
    left = m - left;
    if (left < 0) break;
    long long l = 0;
    long long r = A;
    long long mid;
    while (l < r) {
      mid = (l + r + 1) >> 1;
      long long x = lower_bound(b + 1, b + p + 1, mid) - b - 1;
      if (mid * x - sum[x] <= left)
        l = mid;
      else
        r = mid - 1;
    }
    if (cf * (n - p) + cm * l > ans) {
      ans = cf * (n - p) + cm * l;
      xp = p;
      xl = l;
    }
  }
  cout << ans << endl;
  for (int i = 1; i <= n; i++)
    if (b2[i] < xl) b2[i] = xl;
  for (int i = n; i > xp; i--) {
    b2[a[i].second] = A;
  }
  for (int i = 1; i <= n; i++) cout << b2[i] << " ";
  cout << endl;
  return 0;
}
