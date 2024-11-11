#include <bits/stdc++.h>
using namespace std;
const long long inf = 2e18 + 5;
vector<long long> vec;
void init() {
  for (long long i = 2; i <= 1e6; i++) {
    long long ret = i * i;
    for (int j = 3; j <= 63; j++) {
      if (inf / i < ret) break;
      ret *= i;
      if (ret > ((long long)sqrt(ret)) * ((long long)sqrt(ret)))
        vec.push_back(ret);
    }
  }
  sort(vec.begin(), vec.end());
  unique(vec.begin(), vec.end()) - vec.begin();
}
int main() {
  init();
  int t;
  scanf("%d", &t);
  while (t--) {
    long long l, r;
    scanf("%lld%lld", &l, &r);
    long long ans = (upper_bound(vec.begin(), vec.end(), r) - vec.begin()) -
                    (lower_bound(vec.begin(), vec.end(), l) - vec.begin());
    printf("%lld\n", ans + (long long)sqrt(r) - (long long)sqrt(l - 1));
  }
  return 0;
}
