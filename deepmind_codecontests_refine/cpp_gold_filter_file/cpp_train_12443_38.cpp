#include <bits/stdc++.h>
using namespace std;
template <typename T>
class heap : public priority_queue<T, vector<T>, greater<T> > {};
const int n = 1 << 20;
int main(void) {
  long long s, x;
  scanf("%lld%lld", &s, &x);
  long long mask[2];
  mask[0] = x & (n - 1);
  mask[1] = x >> 20;
  vector<long long> v[2];
  v[0].resize(2 * n + 47, 0);
  v[1].resize(2 * n + 47, 0);
  for (int i = 0; i < 2; ++i) {
    for (int j = 0; j < n; ++j) {
      int other = j ^ mask[i];
      ++v[i][j + other];
    }
  }
  unsigned long long ans = 0;
  for (int i = 0; i < 2 * n; ++i) {
    long long rem = s - i;
    if (rem < 0 || rem % n) continue;
    rem >>= 20;
    ans += 1LL * v[0][i] * v[1][rem];
  }
  if (s == x) ans -= 2;
  printf("%llu\n", ans);
}
