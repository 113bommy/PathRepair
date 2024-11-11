#include <bits/stdc++.h>
using namespace std;
void err(istream_iterator<string> it) { cerr << endl; }
template <typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
  cerr << *it << " = " << a << " ";
  err(++it, args...);
}
long long mod(long long x, long long m = 1000000007) { return x % m; }
long long power(long long x, long long y, long long p = 1000000007) {
  x %= p;
  long long val = 1;
  while (y) {
    if (y & 1LL) val = (val * x) % p;
    y >>= 1LL;
    x = (x * x) % p;
  }
  return val;
}
long long a[400005];
vector<long long> ed[20];
long long cnt[20][20];
long long dp[(1LL << 20)];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long n;
  cin >> n;
  for (long long i = 1; i <= n; i++) {
    cin >> a[i];
    a[i]--;
    ed[a[i]].push_back(i);
  }
  for (int i = 0; i < 20; i++) {
    for (int j = 0; j < 20; j++) {
      if (i == j) continue;
      int x = 0, y = 0;
      while (x < ed[i].size() && y < ed[j].size()) {
        if (ed[i][x] < ed[j][y])
          cnt[i][j] += y, x++;
        else
          y++;
      }
      while (x < ed[i].size()) cnt[i][j] += y, x++;
    }
  }
  for (int i = 1; i < (1LL << 20); i++) {
    dp[i] = 1e17;
    for (int j = 0; j < 20; j++) {
      if (i & (1LL << j)) {
        int sum = 0;
        for (int k = 0; k < 20; k++) {
          if (i & (1LL << k)) sum += cnt[j][k];
        }
        dp[i] = min(dp[i], sum + dp[i ^ (1LL << j)]);
      }
    }
  }
  cout << dp[(1 << 20) - 1] << '\n';
}
