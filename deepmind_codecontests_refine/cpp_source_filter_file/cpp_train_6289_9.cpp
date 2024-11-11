#include <bits/stdc++.h>
using namespace std;
long long n, m, a, sum;
long long have[1000000 + 9], cost[1000000 + 9];
long long check(long long x) {
  bool ok = 1;
  if (x > n || x > m) {
    return 0;
  }
  vector<int> v1, v2;
  for (int i = 0; i < x; i++) {
    v1.push_back(have[i]);
  }
  for (int i = 0; i < x; i++) {
    v2.push_back(cost[i]);
  }
  reverse(v2.begin(), v2.end());
  long long pay = 0;
  for (int i = 0; i < x; i++) {
    if (v1[i] < v2[i]) {
      pay += (v2[i] - v1[i]);
    }
  }
  if (pay > a) {
    ok = 0;
  }
  return ok;
}
long long go(long long x) {
  if (x > n || x > m) {
    return 0;
  }
  long long total_have = 0;
  vector<int> v1, v2;
  for (int i = 0; i < x; i++) {
    v1.push_back(have[i]);
    total_have += have[i];
  }
  for (int i = 0; i < x; i++) {
    v2.push_back(cost[i]);
  }
  reverse(v2.begin(), v2.end());
  long long pay = 0, over = 0;
  for (int i = 0; i < x; i++) {
    if (v1[i] < v2[i]) {
      pay += (v2[i] - v1[i]);
      a -= (v2[i] - v1[i]);
    } else if (v1[i] > v2[i]) {
      over += (v1[i] - v2[i]);
    }
  }
  if (over <= total_have) {
    total_have -= over;
  } else {
    total_have = 0;
  }
  if (a <= total_have) {
    total_have -= a;
  } else {
    total_have = 0;
  }
  return total_have;
}
long long bs_max(long long start, long long end) {
  while (start < end) {
    long long mid = start + (end - start + 1) / 2;
    if (check(mid) == 0) {
      end = mid - 1;
    } else {
      start = mid;
    }
  }
  return end;
}
int main() {
  cin >> n >> m >> a;
  for (int i = 0; i < n; i++) {
    cin >> have[i];
  }
  for (int i = 0; i < m; i++) {
    cin >> cost[i];
  }
  sort(have, have + n);
  reverse(have, have + n);
  sort(cost, cost + m);
  int ans = bs_max(1, n);
  cout << ans << " " << go(ans);
  return 0;
}
