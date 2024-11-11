#include <bits/stdc++.h>
using namespace std;
const int N = 500001;
char s[N], t[N];
long long len, k, ans, r;
int main() {
  scanf("%lld%lld", &len, &k);
  scanf("%s%s", s, t);
  if (s[0] < t[0])
    r = 2;
  else
    r = 1;
  if (r >= k) {
    ans += (len - 1) * k;
    printf("%lld", ans);
    return 0;
  }
  ans += r;
  for (int i = 1; i < len; i++) {
    if (s[i] == 'a') {
      if (t[i] == 'b')
        r = r * 2;
      else
        r = r * 2 - 1;
    } else {
      if (t[i] == 'b')
        r = r * 2 - 1;
      else
        r = r * 2 - 2;
    }
    if (r < k)
      ans += r;
    else {
      ans += (len - i) * k;
      printf("%lld", ans);
      return 0;
    }
  }
  printf("%lld", ans);
}
