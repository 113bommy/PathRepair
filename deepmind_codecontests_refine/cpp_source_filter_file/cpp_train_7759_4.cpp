#include <bits/stdc++.h>
using namespace std;
pair<long long, long long> best;
long long my_pow(long long x) { return x * x * x; }
void rec(long long m, long long steps, long long subtracted) {
  if (m == 0) {
    best = max(best, make_pair(steps, subtracted));
    return;
  }
  long long x = 1;
  while (my_pow(x + 1) <= m) ++x;
  rec(m - my_pow(x), steps + 1, subtracted + my_pow(x));
  if (x - 1 >= 0)
    rec(my_pow(x) - 1 - my_pow(x - 1), steps + 1, subtracted + my_pow(x - 1));
}
int main() {
  long long m;
  scanf("%lld", &m);
  rec(m, 0, 0);
  printf("%lld %lldn", best.first, best.second);
  return 0;
}
