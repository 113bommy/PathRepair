#include <bits/stdc++.h>
using namespace std;
long long ps[1000000];
long long sums[1000000];
long long get_sum(long long l, long long r) { return ps[r] - ps[l - 1]; }
long long ans = 0;
int main() {
  long long a;
  cin >> a;
  string s;
  cin >> s;
  s = 'a' + s;
  long long n = s.size() - 1;
  for (long long i = 1; i <= n; ++i) {
    ps[i] = ps[i - 1] + (s[i] - '0');
  }
  for (long long i = 1; i <= n; ++i) {
    for (long long j = i; j <= n; ++j) {
      long long cur_sum = get_sum(i, j);
      sums[cur_sum]++;
    }
  }
  for (long long i = 1; i <= n; ++i) {
    for (long long j = i; j <= n; ++j) {
      long long cur_sum = get_sum(i, j);
      if (!cur_sum) {
        if (!a) ans += 1LL * (n - 1) * n / 2;
        continue;
      }
      long long ss = a / cur_sum;
      if (ss * cur_sum == a) {
        if (ss >= 4000 * 9) {
          continue;
        }
        ans += sums[ss];
      }
    }
  }
  cout << ans << endl;
}
