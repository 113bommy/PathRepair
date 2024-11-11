#include <bits/stdc++.h>
using namespace std;
char s[4];
int que(long long int l, long long int r) {
  printf("%lld %lld\n", l, r);
  fflush(stdout);
  scanf(" %s", s);
  return s[0] == 'Y';
}
const long long int Z = 45;
int main() {
  long long int n, k;
  scanf("%lld%lld", &n, &k);
  long long int l = 1, r = n;
  srand(time(0));
  for (int i = 0; i < 10000; i++) {
    long long int p = (r + l) / 2;
    if (que(l, p)) {
      l = max(1ll, l - k);
      r = min(n, p + k);
    } else {
      l = max(1ll, p - k);
      r = min(n, r + k);
    }
    if (r - l + 1 <= Z) {
      int x = rand() % min(Z, r - l + 1);
      if (que(l + x, l + x)) return 0;
      l = max(1ll, l - k);
      r = min(n, r + k);
    }
  }
  return 0;
}
