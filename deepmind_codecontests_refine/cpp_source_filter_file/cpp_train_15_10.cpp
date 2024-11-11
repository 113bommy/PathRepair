#include <bits/stdc++.h>
using namespace std;
struct BIT {
  int n, N_MAX;
  vector<long long> v;
  BIT(int n) {
    this->n = n + 100;
    N_MAX = n;
    v.assign(n + 110, 0);
  }
  void upd(int p, int x) {
    while (p <= n) v[p] += x, p += p & -p;
  }
  long long que(int p) {
    long long ans = 0;
    while (p) ans += v[p], p -= p & -p;
    return ans;
  }
  long long quep(int p) { return que(p) - que(p - 1); }
  long long bit_search(long long s) {
    long long sum = 0, pos = 0;
    for (int i = 21; i >= 0; i--)
      if (pos + (1 << i) <= N_MAX && sum + v[pos + (1 << i)] <= s) {
        pos += (1 << i);
        sum += v[pos];
      }
    return pos + 1;
  }
};
int main() {
  int n;
  scanf("%d", &n);
  BIT bit(n);
  vector<long long> v(n + 1), ans(n + 1);
  for (int i = 1; i <= n; i++) scanf("%d", &v[i]), bit.upd(i, i);
  for (int i = n; i; i--) {
    int p = bit.bit_search(v[i]);
    ans[i] = p;
    bit.upd(p, -p);
  }
  for (int i = 1; i <= n; i++) printf("%lld ", ans[i]);
  printf("\n");
  return 0;
}
