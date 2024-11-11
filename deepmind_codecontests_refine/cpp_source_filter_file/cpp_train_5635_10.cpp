#include <bits/stdc++.h>
using namespace std;
const long long llINF = 9223372036854775807;
const int INF = 2147483647;
const int maxn = 500 + 7;
const int maxm = 1e5 + 7;
const int mod = 1e9 + 7;
const double eps = 1e-8;
int t;
long long n, k;
long long num[57];
void init() {
  for (int i = 1; i <= 32; i++) num[i] = num[i - 1] * 4 + 1;
}
int main(int argc, char const *argv[]) {
  init();
  scanf("%d", &t);
  while (t--) {
    scanf("%lld%lld", &n, &k);
    if (n >= 32) {
      printf("YES %lld\n", n - 1);
      return 0;
    }
    long long out = 0, in = 0;
    long long ans = n;
    long long tmp_out = 1;
    while (true) {
      if (out + in >= k && ans >= 0 && out <= k) {
        printf("YES %lld\n", ans);
        break;
      }
      out += tmp_out;
      ans--;
      if (ans < 0 || out > k) {
        printf("NO\n");
        break;
      }
      tmp_out = tmp_out * 2 + 1;
      in += (tmp_out - 2) * num[ans];
    }
  }
  return 0;
}
