#include <bits/stdc++.h>
using namespace std;
const int Maxn = 1e6 + 2, Maxv = 1e7 + 2;
int top, prim[Maxv];
int notPrim[Maxv];
void getPrim() {
  for (int i = 2; i < Maxv; ++i) {
    if (!notPrim[i]) prim[top++] = i;
    for (int j = 0; j < top && prim[j] * i < Maxv; ++j) {
      notPrim[prim[j] * i] = i;
      if (i % prim[j] == 0) break;
    }
  }
}
int n, a[Maxn];
long long cnt[Maxv];
int large;
long long getSum(long long v, int p) {
  int ret = 0;
  while (v) {
    ret += v / p;
    v /= p;
  }
  return ret;
}
bool check(long long v) {
  for (int i = 0; i < top && prim[i] <= large; ++i) {
    int p = prim[i];
    if (getSum(v, p) < cnt[p]) return false;
  }
  return true;
}
int main() {
  getPrim();
  scanf("%d", &n);
  large = 0;
  long long r = 0;
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
    cnt[a[i]]++;
    large = max(large, a[i]);
    r += a[i];
  }
  for (int i = large - 1; i >= 1; --i) cnt[i] += cnt[i + 1];
  for (int i = large; i >= 1; --i) {
    if (notPrim[i]) {
      cnt[notPrim[i]] += cnt[i];
      cnt[i / notPrim[i]] += cnt[i];
      cnt[i] = 0;
    }
  }
  long long l = 1;
  while (l <= r) {
    long long mid = l + r >> 1;
    if (check(mid))
      r = mid - 1;
    else
      l = mid + 1;
  }
  printf("%I64d\n", l);
  return 0;
}
