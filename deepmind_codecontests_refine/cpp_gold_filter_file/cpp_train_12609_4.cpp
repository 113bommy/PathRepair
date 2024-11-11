#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, k;
  char s[500005], t[500005];
  scanf("%lli%lli%s%s", &n, &k, &s, &t);
  long long ans = n, xs = 0, xt = 0;
  bool f = false;
  k--;
  for (int i = 0; i < n; i++) {
    if (k <= 0) break;
    if (!f) {
      if (s[i] != t[i]) {
        ans += n - i;
        f = true;
        k--;
        xs = 1;
        xt = 1;
      }
    } else {
      long long is, it;
      if (s[i] == 'a')
        is = xs;
      else
        is = xs - 1;
      if (t[i] == 'b')
        it = xt;
      else
        it = xt - 1;
      long long tem = min(k, is + it);
      ans += tem * (long long)(n - i);
      k -= tem;
      xs += is;
      xt += it;
    }
  }
  printf("%lli\n", ans);
  return 0;
}
