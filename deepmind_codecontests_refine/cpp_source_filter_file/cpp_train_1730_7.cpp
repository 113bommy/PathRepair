#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-9;
const int INF = (int)1e9 + 7;
const long long linf = (long long)1e16 + 7;
const int MAXN = (int)1e6;
int main() {
  vector<int> bad(MAXN + 1);
  vector<int> prime;
  for (int i = 2; i < MAXN + 1; ++i) {
    if (!bad[i]) {
      prime.push_back(i);
      for (int j = i; j < MAXN + 1; j += i) bad[j] = 1;
    }
  }
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);
  int n, x, y;
  cin >> n >> x >> y;
  vector<int> a(n + 1);
  vector<int> cnt(MAXN + 1);
  vector<long long> sum(MAXN + 1);
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    cnt[a[i]]++;
    sum[a[i]] += a[i];
  }
  for (int i = 1; i <= MAXN; ++i) {
    cnt[i] += cnt[i - 1];
    sum[i] += sum[i - 1];
  }
  long long ans = linf;
  for (const auto &g : prime) {
    long long cur = 0;
    int f = g - min(g, (x + y - 1) / y);
    for (int i = g; i <= MAXN; i += g) {
      cur += (cnt[i - g + f] - cnt[i - g]) * 1ll * x;
      cur += ((cnt[i] - cnt[i - g + f]) * 1ll * i - (sum[i] - sum[i - g + f])) *
             1ll * y;
    }
    ans = min(ans, cur);
  }
  cout << ans;
  return 0;
}
