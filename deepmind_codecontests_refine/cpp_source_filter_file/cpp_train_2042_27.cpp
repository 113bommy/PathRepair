#include <bits/stdc++.h>
using namespace std;
long long int cnt[1000005];
long long int sum[1000005];
inline void makecnt(int n, int a[]) {
  for (int i = 0; i < n; i++) cnt[a[i]]++;
  cnt[0] = 0;
  for (int i = 1; i < 1000005; i++) cnt[i] = cnt[i - 1] + cnt[i];
  return;
}
inline void makesum(int n, int a[]) {
  for (int i = 0; i < n; i++) sum[a[i]]++;
  for (int i = 1; i < 1000005; i++) sum[i] = sum[i - 1] + sum[i] * i;
  return;
}
inline long long int hudai(int g, long long int x, long long int y) {
  long long int ret = 0;
  for (int i = g; i < 1000005; i += g) {
    int l = i;
    int r = i - g + 1;
    int z = (x + y - 1) / y;
    int f = i - min(g, z);
    long long int d_cn = max(0ll, cnt[f] - cnt[r - 1]);
    long long int a_cn = cnt[l] - cnt[f];
    long long int s = sum[l] - sum[f];
    long long int tem = d_cn * x + (a_cn * i - s) * y;
    ret += tem;
  }
  return ret;
}
int main() {
  int n;
  long long int x, y;
  scanf("%d", &n);
  scanf("%lld %lld", &x, &y);
  int a[n + 5];
  for (int i = 0; i < n; i++) scanf("%d", &a[i]);
  makecnt(n, a);
  makesum(n, a);
  long long int ans = x * n;
  for (int i = 2; i < 1000005; i++) {
    ans = min(ans, hudai(i, x, y));
  }
  printf("%lld\n", ans);
  return 0;
}
