#include <bits/stdc++.h>
using namespace std;
int n, num[233];
long long a;
int check(long long mid) {
  int mmin = mid, ret = num[0] - mid;
  for (int i = 1; i < 233; ++i) {
    ret = max(ret, 0);
    if (i & 1)
      ret += num[i];
    else {
      ret += (num[i] - mmin);
      mmin = min(mmin, num[i]);
    }
  }
  return !ret;
}
inline int id(long long x) {
  int ret = 0;
  while ((1LL << ret) < x) ++ret;
  if ((1 << ret) == x) return ret << 1;
  return (ret << 1) - 1;
}
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%I64d", &a);
    ++num[id(a)];
  }
  int left = 1, right = num[0], res = -1;
  while (left <= right) {
    int mid = (left + right) >> 1;
    if (check(mid)) {
      res = mid;
      right = mid - 1;
    } else
      left = mid + 1;
  }
  if (res == -1)
    puts("-1");
  else
    for (int i = res; i <= num[0]; ++i)
      printf("%d%c", i, i == num[0] ? '\n' : ' ');
  return 0;
}
