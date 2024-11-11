#include <bits/stdc++.h>
using namespace std;
long long n, p, k;
unordered_map<long long, long long> ma;
int main() {
  while (scanf("%I64d%64d%64d", &n, &p, &k) != EOF) {
    ma.clear();
    for (int i = 0; i < n; ++i) {
      long long a;
      scanf("%I64d", &a);
      long long tmp =
          ((((a * a) % p) * ((a * a) % p)) % p - (k * a) % p + p) % p;
      while (tmp < 0) tmp += p;
      ma[tmp]++;
    }
    long long ans = 0;
    for (auto it : ma) ans += it.second * (it.second - 1);
    printf("%I64d\n", ans);
  }
  return 0;
}
