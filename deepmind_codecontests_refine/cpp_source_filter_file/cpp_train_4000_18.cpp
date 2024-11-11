#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100010;
long long q[MAXN], w[MAXN];
long long get_min_len(long long n) {
  long long ans = (n * (n - 1LL)) << 1LL;
  if (n & 1LL) return ans;
  return ans + ((n - 2LL) << 1LL);
}
long long sum[MAXN];
int main() {
  int n, m;
  cin >> n >> m;
  for (int i = (int)0; i < (int)m; i++) cin >> q[i] >> w[i];
  long long ans = 0;
  sort(w, w + m);
  for (int i = (int)0; i < (int)m; i++) sum[i + 1] = sum[i] + w[m - 1 - i];
  for (int i = (int)1; i < (int)m + 1; i++) {
    long long min_len = get_min_len(i) + 1LL;
    if (min_len <= (long long)n) {
      ans = max(ans, sum[i]);
    }
  }
  cout << ans << endl;
  return 0;
}
