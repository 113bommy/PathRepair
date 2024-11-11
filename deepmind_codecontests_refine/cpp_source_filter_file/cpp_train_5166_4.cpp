#include <bits/stdc++.h>
using namespace std;
int n, m, q, i;
long long a[100011], b[100011], sums[100011];
long long def, l, r, c;
vector<long long> ord;
long long abss(long long x) {
  if (x < 0) return -x;
  return x;
}
long long ask() {
  long long ans = 1LL << 60;
  auto it = lower_bound(ord.begin(), ord.end(), def);
  if (it != ord.end()) {
    ans = abss(def - *it);
  }
  if (it != ord.begin()) {
    it--;
    ans = min(ans, abss(def - *it));
  }
  return ans;
}
int main() {
  cin >> n >> m >> q;
  for (i = 1; i <= n; i++) {
    cin >> a[i];
    if (i & 1)
      def += a[i];
    else
      def -= a[i];
  }
  for (i = 1; i <= m; i++) {
    cin >> b[i];
    if (i % 2 == 0) b[i] *= -1;
    sums[i] = b[i] + sums[i - 1];
  }
  for (i = 1; i + n - 1 <= m; i++)
    ord.push_back((sums[i + n - 1] - sums[i - 1]) * (i % 2 == 1 ? 1 : -1));
  sort(ord.begin(), ord.end());
  printf("%lld\n", ask());
  for (i = 1; i <= q; i++) {
    scanf("%lld%lld%lld", &l, &r, &c);
    if (r - l + 1 % 2 == 1) {
      if (l % 2 == 1)
        def += c;
      else
        def -= c;
    }
    printf("%lld\n", ask());
  }
  return 0;
}
