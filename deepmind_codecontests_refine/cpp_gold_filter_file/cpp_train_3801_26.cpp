#include <bits/stdc++.h>
using namespace std;
set<pair<long long, long long> > s;
set<pair<long long, long long> >::iterator it;
int main() {
  long long xx;
  scanf("%I64d", &xx);
  xx *= 6;
  long long m = 0;
  while (++m < 2000000) {
    long long x = xx;
    if (x % m || x % (m + 1)) continue;
    x /= m, x /= m + 1;
    x += m - 1;
    if (x % 3) continue;
    long long n = x / 3;
    if (n < m) break;
    s.insert(make_pair(m, n));
    s.insert(make_pair(n, m));
  }
  printf("%d\n", s.size());
  for (it = s.begin(); it != s.end(); it++)
    printf("%I64d %I64d\n", it->first, it->second);
}
