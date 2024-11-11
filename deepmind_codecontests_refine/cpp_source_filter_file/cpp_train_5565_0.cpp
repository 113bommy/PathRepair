#include <bits/stdc++.h>
using namespace std;
int n;
long long a[1000002];
long long fi[1000002];
long long fj[1000002];
long long prom[1000002];
map<long long, long long> cnt1, cnt2;
long long sum(long long r) {
  long long res = 0;
  for (; r >= 0; r = (r & (r + 1)) - 1) res += prom[r] * 1ll;
  return res;
}
void inc(long long i, long long vv) {
  for (; i <= n; i = (i | (i + 1))) prom[i] += vv;
}
long long F(long long l, long long r) {
  return 1ll * sum(r) - 1ll * sum(l - 1);
}
int main() {
  scanf("%d\n", &n);
  for (int i = 0; i < n; i++) scanf("%ld", &a[i]);
  for (int i = 0; i < n; i++) {
    cnt1[a[i]]++;
    fi[i] = cnt1[a[i]];
  }
  for (int i = n - 1; i >= 0; i--) {
    cnt2[a[i]]++;
    fj[i] = cnt2[a[i]];
  }
  long long res = 0;
  for (int i = n - 2; i >= 0; i--) {
    inc(fj[i + 1], 1);
    res += F(1, fi[i] - 1) * 1ll;
  }
  printf("%ld", res);
  return 0;
}
