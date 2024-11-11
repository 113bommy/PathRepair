#include <bits/stdc++.h>
using namespace std;
long long h[100005], a[100005];
long long n, days, k, p;
long long cnt[5005];
bool check(long long x) {
  memset(cnt, 0, sizeof(cnt));
  long long total = 0;
  for (int i = 0; i < n; ++i) {
    long long day = 0;
    long long curh = x;
    while (true) {
      if (curh >= a[i] * days) break;
      long long nextday = curh / a[i] - 1;
      cnt[nextday]++;
      total++;
      if (total > days * k) return false;
      curh += p;
    }
    curh = curh - days * a[i];
    if (curh < h[i]) {
      long long dif = h[i] - curh;
      cnt[n - 1] += (dif + p - 1) / p;
      total += (dif + p - 1) / p;
    }
    if (total > days * k) return false;
  }
  long long sum = 0;
  for (int i = 0; i < days; ++i) {
    sum += cnt[i];
    if (sum > (i + 1) * k) return false;
  }
  return true;
}
int main() {
  cin >> n >> days >> k >> p;
  long long l = 1, r = 1LL << 55;
  for (int i = 0; i < n; ++i) {
    cin >> h[i] >> a[i];
    l = max(l, a[i]);
  }
  long long ans;
  while (l < r) {
    long long mid = (l + r) / 2;
    if (check(mid)) {
      ans = mid;
      r = mid;
    } else {
      l = mid + 1;
    }
  }
  cout << ans << endl;
  return 0;
}
