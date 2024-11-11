#include <bits/stdc++.h>
using namespace std;
template <typename T>
void chmax(T& a, T b) {
  a = max(a, b);
}
template <typename T>
void chmin(T& a, T b) {
  a = min(a, b);
}
long long a[3], p[3], cnt[3], r;
string str;
int good(long long x) {
  long long req = 0;
  for (int i = 0; i < 3; ++i) {
    if (!cnt[i]) continue;
    req += max(cnt[i] * x - a[i], 0ll) * p[i];
  }
  return (req <= r);
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> str;
  for (int i = 0; i < 3; ++i) cin >> a[i];
  for (int i = 0; i < 3; ++i) cin >> p[i];
  cin >> r;
  for (int i = 0; i < (int)str.size(); ++i) {
    if (str[i] == 'B')
      ++cnt[0];
    else if (str[i] == 'S')
      ++cnt[1];
    else
      ++cnt[2];
  }
  long long lo = 0, hi = 1e14;
  while (lo + 1 < hi) {
    long long mid = (lo + hi) >> 1;
    if (good(mid))
      lo = mid;
    else
      hi = mid;
  }
  cout << lo;
  return 0;
}
