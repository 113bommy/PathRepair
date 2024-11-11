#include <bits/stdc++.h>
using namespace std;
int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  cout.setf(ios_base::fixed);
  cout.precision(28);
  int n, k;
  cin >> n >> k;
  vector<int> v(n);
  long long s = 0;
  for (auto &x : v) {
    cin >> x;
    s += x;
  }
  sort(v.begin(), v.end());
  vector<int> cv(n, int(s / n));
  for (int i = 0; i < s % n; ++i) {
    ++cv[n - i - 1];
  }
  long long sabs = 0;
  for (int i = 0; i < n; ++i) {
    sabs += abs(v[i] - cv[i]);
  }
  if (sabs <= k) {
    cout << cv.back() - cv[0];
    return 0;
  }
  int L = 0, R = 1e9 + 10, M;
  while (R - L > 1) {
    M = (L + R) / 2;
    long long sd = 0;
    for (auto x : v) {
      if (x > M) {
        sd += x - M;
      }
    }
    if (sd > k) {
      L = M;
    } else {
      R = M;
    }
  }
  int ans = R;
  L = 0;
  R = 1e9 + 10;
  while (R - L > 1) {
    M = (L + R) / 2;
    long long sd = 0;
    for (auto x : v) {
      if (x < M) {
        sd += M - x;
      }
    }
    if (sd > k) {
      R = M;
    } else {
      L = M;
    }
  }
  cout << ans - L;
  return 0;
}
