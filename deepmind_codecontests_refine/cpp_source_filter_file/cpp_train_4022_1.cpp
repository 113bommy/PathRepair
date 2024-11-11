#include <bits/stdc++.h>
using namespace std;
const int MAX = 3e5 + 33;
const long long MOD = 1e9 + 7;
const long long INF = 1e18 + 77;
int main() {
  long long n, m, a, d;
  scanf("%lld", &n);
  scanf("%lld", &m);
  scanf("%lld", &a);
  scanf("%lld", &d);
  long long res = 0;
  long long lst = 1;
  d++;
  long long x = (d + a - 1) / a;
  for (int i = 0; i < m; ++i) {
    long long cur;
    scanf("%lld", &cur);
    if (res && abs(cur - lst) <= d) continue;
    long long st, en;
    long long lstT = lst + d;
    if (!res) lstT = 1;
    st = lstT + ((a - lstT % a) % a);
    en = cur - cur % a;
    en = min(en, n * a);
    if (en >= st && st < cur) {
      long long tmp = (en - st + a) / a;
      res += (tmp + x - 1) / x;
      lst = en - ((tmp + x - 1) % x) * a;
    }
    if (res && abs(cur - lst) <= d) continue;
    res++;
    lst = cur;
  }
  long long st, en;
  long long lstT = lst + d;
  st = lstT + ((a - lstT % a) % a);
  en = n * a;
  if (en >= st) {
    long long tmp = (en - st + a) / a;
    res += (tmp + x - 1) / x;
    lst = en - (x - tmp % x) * a;
  }
  cout << res;
  return 0;
}
