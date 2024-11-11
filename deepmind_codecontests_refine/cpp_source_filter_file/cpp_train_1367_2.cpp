#include <bits/stdc++.h>
using namespace std;
template <typename T>
inline bool chkmin(T &a, const T &b) {
  return b < a ? a = b, 1 : 0;
}
template <typename T>
inline bool chkmax(T &a, const T &b) {
  return a < b ? a = b, 1 : 0;
}
const int oo = 0x3f3f3f3f;
const int maxn = 100100;
int n;
long long a[maxn + 5];
char ty[maxn + 5];
long long ans = 0;
int main() {
  scanf("%d", &n);
  for (int i = (0), i_end_ = (n); i < i_end_; ++i) scanf("%lld", a + i);
  scanf("%s", ty);
  long long cnt = 0, reserve = 0;
  bool flag = 0;
  for (int i = (0), i_end_ = (n); i < i_end_; ++i) {
    if (!flag) {
      if (ty[i] == 'W') {
        reserve = cnt;
        flag = 1;
        cnt = 0;
      } else if (ty[i] == 'G') {
        ans += a[i] * 3;
        cnt += a[i];
      } else if (ty[i] == 'L') {
        long long res = a[i];
        long long tmp = min(res, cnt);
        ans += tmp * 3;
        cnt -= tmp;
        res -= tmp;
        ans += res * 6;
      }
    }
    if (flag) {
      if (ty[i] == 'W') {
        ans += a[i] * 2;
        cnt += a[i];
      } else if (ty[i] == 'L') {
        long long res = a[i];
        long long tmp = min(res, cnt);
        ans += tmp * 2;
        cnt -= tmp;
        res -= tmp;
        tmp = min(res, reserve);
        ans += tmp * 3;
        reserve -= tmp;
        res -= tmp;
        ans += res * 4;
      } else if (ty[i] == 'G') {
        long long res = a[i];
        long long tmp = min(res, cnt);
        ans += tmp * 2;
        cnt -= tmp;
        res -= tmp;
        ans += res * 3;
        reserve += a[i];
      }
    }
  }
  printf("%lld\n", ans);
  return 0;
}
