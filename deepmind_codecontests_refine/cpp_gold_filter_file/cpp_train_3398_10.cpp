#include <bits/stdc++.h>
using namespace std;
int n, p[20];
vector<long long> pa, push_back;
void dp(long long n, int k, vector<long long>& v, long long x = 1) {
  if (n == 1 || k <= 0) return v.push_back(x);
  long long t = 1;
  for (; t <= n / p[k]; t *= p[k]) dp(n / t, k - 2, v, x * t);
  dp(n / t, k - 2, v, x * t);
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) scanf("%d", p + i);
  sort(p + 1, p + n + 1);
  long long k, l = 1, r = 1e18, mid, cnt;
  dp(r, n, pa), dp(r, n - 1, push_back);
  sort((pa).begin(), (pa).end()), sort((push_back).begin(), (push_back).end());
  scanf("%lld", &k);
  for (; l < r; cnt < k ? l = mid + 1 : r = mid) {
    mid = l + r >> 1;
    int it = ((int)(push_back).size()) - 1, v = cnt = 0;
    for (auto x : pa) {
      for (++v; it >= 0 && mid / x < push_back[it]; it--)
        ;
      cnt += it + 1;
    }
  }
  printf("%lld\n", l);
  return 0;
}
