#include <bits/stdc++.h>
using namespace std;
int main() {
  set<long long> power;
  for (long long x = 2; x <= (int)1e9; x *= 2) {
    power.insert(x);
  }
  int n;
  scanf("%d", &n);
  map<long long, int> cnt;
  for (int i = 1; i <= n; i++) {
    long long tmp;
    scanf("%I64d", &tmp);
    cnt[tmp]++;
  }
  int ans = 0;
  for (auto i : cnt) {
    long long x = i.first;
    bool ok = false;
    for (long long p : power) {
      if (p <= x) continue;
      if (p - x == x) {
        if (cnt[x] > 1) {
          ok = true;
          break;
        }
      } else {
        if (cnt.count(p - x)) {
          ok = true;
          break;
        }
      }
    }
    if (!ok) ans += i.second;
  }
  printf("%d\n", ans);
  return 0;
}
