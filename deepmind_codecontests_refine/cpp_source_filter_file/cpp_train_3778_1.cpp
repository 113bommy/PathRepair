#include <bits/stdc++.h>
using namespace std;
const int maxn = 50 + 10;
const int maxp = 1e5 + 100;
int t;
long long p, q;
bool vis[maxp];
int main() {
  scanf("%d", &t);
  while (t--) {
    scanf("%lld %lld", &p, &q);
    if (p % q != 0) {
      printf("%lld\n", p);
    } else {
      long long tmp = p;
      long long ans = p;
      int maxq = sqrt(q + 10);
      for (int i = 2; i < maxq; i++) {
        if (q % i != 0) continue;
        int cntq = 0;
        long long valq = 1;
        while (q % i == 0) {
          q /= i;
          cntq++;
          valq *= i;
        }
        int cntp = 0;
        long long valp = 1;
        while (p % i == 0) {
          p /= i;
          cntp++;
          valp *= i;
        }
        assert(cntp >= cntq);
        ans = min(ans, valp / valq * i);
      }
      if (q != 1) {
        int cntq = 1;
        int cntp = 0;
        long long valp = 1;
        while (p % q == 0) {
          p /= q;
          cntp++;
          valp *= q;
        }
        assert(cntp >= cntq);
        ans = min(ans, valp);
      }
      printf("%lld\n", tmp / ans);
    }
  }
  return 0;
}
