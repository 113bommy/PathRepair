#include <bits/stdc++.h>
using namespace std;
const int maxi = 1e6 + 10;
long long a[maxi];
int n, q;
string s;
vector<int> v[maxi];
long long sum[maxi];
map<long long, long long> mp;
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) scanf("%lld", &a[i]);
  sort(a + 1, a + n + 1);
  for (int i = 1; i <= n; i++) sum[i] = sum[i - 1] + a[i];
  cin >> q;
  while (q--) {
    long long k;
    scanf("%lld", &k);
    long long ans = 0;
    long long cur = n - 1;
    long long step = k;
    long long cnt = 1;
    if (mp[k]) {
      printf("%I64d ", mp[k]);
      continue;
    }
    while (cur > 0) {
      ans += cnt * (sum[cur] - sum[max(0ll, cur - step)]);
      cnt++;
      cur -= step;
      step *= k;
    }
    mp[k] = ans;
    printf("%I64d ", ans);
  }
  printf("\n");
  return 0;
}
