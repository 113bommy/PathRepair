#include <bits/stdc++.h>
using namespace std;
struct I {
  long long lo, hi;
  I(long long lo, long long hi) : lo(lo), hi(hi) {}
  long long len() { return hi - lo + 1LL; }
};
I square_range(long long lo, long long hi) {
  long long mostlo = (long long)ceil(sqrt(lo - 0.5));
  long long mosthi = (long long)floor(sqrt(hi + 0.5));
  if (lo < 0) mostlo = 0;
  return I(mostlo, mosthi);
}
const long long SUP = 5000000;
long long cnt[SUP * 2 + 2000];
void add_interval(I is) {
  assert(is.lo <= is.hi);
  cnt[is.lo + SUP]++;
  cnt[is.hi + SUP + 1]--;
}
int main() {
  long long N, M;
  while (cin >> N >> M) {
    memset((cnt), (0LL), sizeof(cnt));
    long long res = 0;
    for (long long b = (1); b <= (long long)(N); ++b) {
      I is = square_range(b * b - M, b * b - 1);
      res += (min(b * b, M) - is.len()) * 2LL;
      if (is.len() > 0) {
        I is1 = is, is2 = is;
        is1.hi += -b, is1.lo += -b;
        is2.hi += +b, is2.lo += +b;
        is2.hi = -is2.hi, is2.lo = -is2.lo;
        swap(is2.hi, is2.lo);
        add_interval(is1);
        add_interval(is2);
      }
    }
    long long su = 0;
    for (long long j = (0); j <= (long long)(2 * SUP); ++j) {
      su += cnt[j];
      if (su > 0) res++;
    }
    cout << res << endl;
  }
}
