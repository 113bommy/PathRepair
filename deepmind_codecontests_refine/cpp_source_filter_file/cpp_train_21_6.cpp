#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long n, l, r;
  cin >> n >> l >> r;
  if (n == 2) {
    for (long long i = l - 1; i < r; i++) {
      if (i & 1)
        cout << 2 << " ";
      else
        cout << 1 << " ";
    }
    return;
  }
  if ((r - 1) / 2 + 1 < n) {
    vector<long long> ans;
    long long vl = l - 1;
    vl /= 2;
    l -= vl * 2;
    r -= vl * 2;
    vl += 2;
    while (ans.size() < r - l + 1) {
      ans.push_back(1);
      ans.push_back(vl);
      vl++;
    }
    for (long long i = l - 1; i < r; i++) {
      cout << ans[i] << " ";
    }
    return;
  }
  long long lb = -1, rb = n - 1;
  while (rb - lb != 1) {
    long long mid = lb + rb >> 1;
    if ((n - 1) * 2 + (n - 2) * (n - 1) - (n - 1 - mid) * (n - 2 - mid) >= l)
      rb = mid;
    else
      lb = mid;
  }
  long long from = rb;
  lb = -1, rb = n - 1;
  while (rb - lb != 1) {
    long long mid = rb + lb >> 1;
    if ((n - 1) * 2 + (n - 2) * (n - 1) - (n - 1 - mid) * (n - 2 - mid) >= r)
      rb = mid;
    else
      lb = mid;
  }
  vector<long long> ans;
  long long to = rb;
  long long rto = from;
  if (from ^ 1) {
    for (long long i = 2; i <= n; i++) {
      ans.push_back(1);
      ans.push_back(i);
    }
    from++;
  }
  while (from <= min(to, n - 2)) {
    ans.push_back(from + 1);
    for (long long i = from + 2; i < n; i++) {
      ans.push_back(i);
      ans.push_back(from + 1);
    }
    ans.push_back(n);
    from++;
  }
  ans.push_back(1);
  rto--;
  long long val = 0;
  if (rto != -1)
    val = (n - 1) * 2 + (n - 2) * (n - 1) - (n - 1 - rto) * (n - 2 - rto);
  r -= val;
  l -= val;
  for (long long i = l - 1; i < r; i++) cout << ans[i] << " ";
}
signed main() {
  long long t;
  cin >> t;
  while (t--) {
    solve();
    cout << endl;
  }
  return 0;
}
