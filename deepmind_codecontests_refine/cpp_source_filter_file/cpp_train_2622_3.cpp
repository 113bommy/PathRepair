#include <bits/stdc++.h>
using namespace std;
const double pi = 2 * acos(0.0);
const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, -1, 0, 1};
const int dx8[] = {-1, 0, 1, 0, 1, 1, -1, -1};
const int dy8[] = {0, -1, 0, 1, 1, -1, 1, -1};
long long min(long long a, long long b) {
  if (a < b) return a;
  return b;
}
long long max(long long a, long long b) {
  if (a > b) return a;
  return b;
}
long long ceil1(long long a, long long b) { return (a + b - 1) / b; }
long long calc(vector<long long> &arr, long long x) {
  if (x < 0 or x >= int(arr.size())) return 0;
  return arr[x];
}
void solve() {
  string x;
  cin >> x;
  long long ans = 0;
  vector<long long> cnt(int(x.size())), pw(18, 1);
  for (long long i = 1; i <= 17; i++) {
    pw[i] = pw[i - 1] * 2;
  }
  cnt[0] = 1 - x[0] + '0';
  for (long long i = 1; i < int(x.size()); i++) {
    if (x[i] == '1')
      cnt[i] = 0;
    else {
      cnt[i] = cnt[i - 1] + 1;
    }
  }
  for (long long i = 1; i <= 16; i++) {
    long long l = 0;
    long long num = 0;
    long long p = pw[i - 1], p2 = p;
    for (long long j = 0; j < x.size(); j++) {
      long long n = x[j] - '0';
      num += p2 * n;
      p2 /= 2;
      if (j - l + 1 == i) {
        if (x[l] == '1') {
          long long zero = calc(cnt, l - 1);
          long long left = j - l + 1;
          long long right = left + zero;
          if (num >= left and num <= right) ans++;
        }
        num -= (x[l] - '0') * p;
        l++;
        num *= 2;
        p2 = 1;
      }
    }
  }
  cout << ans << '\n';
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) solve();
}
