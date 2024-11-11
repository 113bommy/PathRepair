#include <bits/stdc++.h>
using namespace std;
long long n;
long long ydtzAKIOI(long long n) {
  long long ans = 0;
  while (n > 0) {
    ans += n % 10;
    n /= 10;
  }
  return ans;
}
int main(void) {
  int t;
  scanf("%d", &t);
  while (t--) {
    long long n, s;
    scanf("%lld%lld", &n, &s);
    if (ydtzAKIOI(n) < s) {
      puts("0");
      continue;
    }
    long long tmp = 1, ans = 0;
    for (int i = 0; i < 18; i++) {
      long long d = (n / tmp) % 10;
      long long dd = tmp * ((10 - d) % 10);
      n += dd;
      ans += dd;
      if (ydtzAKIOI(n) < s) break;
      tmp *= 10;
    }
    printf("%lld\n", ans);
  }
  return 0;
}
