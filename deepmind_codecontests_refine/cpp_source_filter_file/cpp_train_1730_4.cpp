#include <bits/stdc++.h>
using namespace std;
const int INF = 2e9;
const long long BIG_INF = 1e18;
const long long MOD = 1e9 + 7;
const int maxn = 5e5 + 5, maxa = 1e6 + 5;
int n, x, y, a[maxn], cnt[maxa];
bool prime[maxa];
long long sum[maxa];
long long get_cnt(int l, int r) {
  if (l > r) return 0;
  return (long long)(cnt[r] - cnt[l - 1]);
}
long long get_sum(int l, int r) {
  if (l > r) return 0LL;
  return sum[r] - sum[l - 1];
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> x >> y;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    cnt[a[i]]++;
    sum[a[i]] += (long long)a[i];
  }
  for (int i = 1; i < maxa; i++) {
    cnt[i] += cnt[i - 1];
    sum[i] += sum[i - 1];
  }
  for (int i = 1; i < maxa; i++) prime[i] = true;
  long long ans = BIG_INF;
  for (int i = 2; i < maxa; i++) {
    if (!prime[i]) continue;
    long long res = 0;
    int f = min(i, x / y);
    for (int j = i; j < maxa; j += i) {
      res += get_cnt(j - i + 1, j - f - 1) * (long long)x;
      res += (get_cnt(j - f + 1, j) * (long long)j - get_sum(j - f + 1, j)) *
             (long long)y;
      if (f < i)
        res += min(get_cnt(j - f, j - f) * (long long)x,
                   get_cnt(j - f, j - f) * (long long)f * (long long)y);
      prime[j] = false;
    }
    ans = min(ans, res);
  }
  cout << ans << "\n";
  return 0;
}
