#include <bits/stdc++.h>
using namespace std;
long long time_estim(const vector<long long> &x, long long t, long long s,
                     long long cand) {
  long long ans = 0;
  long long cur = 0;
  long long k = x.size();
  for (long long i = 0; i <= k && x[i] <= s; i++) {
    long long next;
    if (i == k || x[i] >= s) {
      next = s;
    } else {
      next = x[i];
    }
    long long diff = next - cur;
    if (cand < diff) return -1;
    long long fast = min(cand - diff, diff);
    long long slow = diff - fast;
    long long total_time = fast + slow * 2;
    ans += total_time;
    cur = next;
  }
  if (cur != s) {
    long long diff = s - cur;
    if (cand < diff) return -1;
    long long fast = min(cand - diff, diff);
    long long slow = diff - fast;
    long long total_time = fast + slow * 2;
    ans += total_time;
  }
  if (ans > t) {
    return -1;
  }
  return ans;
}
int main() {
  ios::sync_with_stdio(false);
  long long n, k, s, t;
  cin >> n >> k >> s >> t;
  vector<pair<long long, long long> > c(n);
  vector<long long> x(k);
  long long min_c = 1e9 + 1;
  long long max_c = -1;
  for (long long i = 0; i < n; i++) {
    cin >> c[i].first >> c[i].second;
    if (c[i].second > max_c) max_c = c[i].second;
    if (c[i].second < min_c) min_c = c[i].second;
  }
  for (long long i = 0; i < k; i++) {
    cin >> x[i];
  }
  sort(x.begin(), x.end());
  long long l = min_c;
  long long r = max_c;
  long long mid;
  while (l < r) {
    mid = (l + r) / 2;
    if (time_estim(x, t, s, mid) == -1) {
      l = mid + 1;
    } else {
      r = mid;
    }
  }
  if (time_estim(x, t, s, l) == -1) {
    cout << -1 << endl;
    return 0;
  }
  long long min_p = 1e9;
  for (long long i = 0; i < n; i++) {
    if (c[i].second >= l && c[i].first < min_p) {
      min_p = c[i].first;
    }
  }
  if (min_p == 1e9)
    cout << -1 << endl;
  else
    cout << min_p << endl;
  return 0;
}
