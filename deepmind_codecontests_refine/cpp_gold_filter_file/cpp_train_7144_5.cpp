#include <bits/stdc++.h>
using namespace std;
long long dp[200000];
signed main() {
  cin.tie(0);
  cout.tie(0);
  ios_base::sync_with_stdio(false);
  long long n;
  cin >> n;
  vector<long long> bit(n + 1, 0);
  auto update = [&](long long x, long long val) {
    while (x <= n) {
      bit[x] ^= val;
      x += x & -x;
    }
  };
  auto query = [&](long long x) {
    long long ans = 0;
    while (x) {
      ans ^= bit[x];
      x -= x & -x;
    }
    return ans;
  };
  auto mex = [&](vector<long long> v) {
    sort(begin(v), end(v));
    v.erase(unique(begin(v), end(v)), v.end());
    v.push_back(1000000000000000000);
    long long i = 0;
    while (v[i] == i) i++;
    return i;
  };
  for (long long i = 3; i < n + 1; i++) {
    vector<long long> v;
    for (long long j = 2; j * (j + 1) / 2 <= i; j++) {
      if ((2 * i - j * (j + 1)) % (2 * j) != 0) continue;
      long long l = (2 * i - j * (j + 1)) / (2 * j) + 1;
      long long r = l + j - 1;
      v.push_back(query(r) ^ query(l - 1));
    }
    dp[i] = mex(v);
    update(i, dp[i]);
  }
  if (!dp[n])
    cout << "-1\n";
  else {
    for (long long j = 2; j * (j + 1) / 2 <= n; j++) {
      if ((2 * n - j * (j + 1)) % (2 * j) != 0) continue;
      long long l = (2 * n - j * (j + 1)) / (2 * j) + 1;
      long long r = l + j - 1;
      if ((query(r) ^ query(l - 1)) == 0) return cout << j << '\n', 0;
    }
  }
}
