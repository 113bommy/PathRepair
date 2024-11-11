#include <bits/stdc++.h>
using namespace std;
class ac_machine {
  long long int range(long long int L, long long int R) {
    long long int r = 1ll * rand() * rand();
    long long int w = R - L + 1;
    return L + r % w;
  }
  int ask(long long int l, long long int r) {
    char res[8];
    printf("%lld %lld\n", l, r);
    fflush(stdout);
    scanf("%s", res);
    if ('B' == res[0]) return -1;
    if (l == r && 'Y' == res[0]) return -1;
    return ('Y' == res[0]);
  }

 public:
  int ac(void) {
    long long int n, k;
    scanf("%lld%lld", &n, &k);
    long long int l = 1, r = n;
    while (l < r) {
      if ((r - l + 1ll) <= (k * 4)) {
        long long int pos = range(l, r);
        assert(l <= pos && pos <= r);
        int res = ask(pos, pos);
        if (-1 == res) return 0;
        l = max(1ll, l - k);
        r = min(n, r + k);
      } else {
        long long int mid = (l + r) >> 1;
        int res = ask(l, mid);
        if (-1 == res) return 0;
        if (res) {
          l = max(1ll, l - k);
          r = min(n, mid + k);
        } else {
          l = max(1ll, mid + 1 - k);
          r = min(n, r + k);
        }
      }
    }
    ask(l, l);
    return 0;
  }
};
int main(void) {
  srand(time(NULL));
  return (new ac_machine())->ac();
}
