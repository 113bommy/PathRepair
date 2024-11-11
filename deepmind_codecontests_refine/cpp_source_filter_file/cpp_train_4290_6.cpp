#include <bits/stdc++.h>
using namespace std;
const long long MAXN = 2e5 + 5;
pair<long long, long long> a[MAXN];
long long s;
long long n;
bool check(long long x) {
  long long sum = 0, cnt = 0;
  vector<long long> nums;
  for (long long i = 0; i < n; i++) {
    if (a[i].first >= x) {
      sum += a[i].first;
      cnt++;
    } else {
      if (a[i].second < x) {
        sum += a[i].second;
      } else {
        nums.push_back(a[i].first);
      }
    }
  }
  long long left = max((long long)0, (n + 1) / 2 - cnt);
  if (left > nums.size()) return 0;
  for (long long i = 0; i < nums.size() - left; i++) {
    sum += nums[i];
  }
  for (long long i = nums.size() - left; i < nums.size(); i++) {
    sum += x;
  }
  return (sum <= s);
}
int main() {
  long long q;
  cin >> q;
  while (q--) {
    cin >> n >> s;
    for (long long i = 0; i < n; i++) {
      cin >> a[i].first >> a[i].second;
    }
    sort(a, a + n);
    long long l = 1, r = 1e9 + 100;
    while (l + 1 < r) {
      long long m = (l + r) >> 1;
      if (check(m)) {
        l = m;
      } else {
        r = m;
      }
    }
    cout << l << "\n";
  }
  return 0;
}
