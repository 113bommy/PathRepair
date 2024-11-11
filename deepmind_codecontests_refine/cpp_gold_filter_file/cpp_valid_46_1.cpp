#include <bits/stdc++.h>
using namespace std;
clock_t startTime, endTime;
const long long INF_ll = 1e18;
const int INF_int = 0x3f3f3f3f;
void read(){};
template <typename _Tp, typename... _Tps>
void read(_Tp& x, _Tps&... Ar) {
  x = 0;
  char c = getchar();
  bool flag = 0;
  while (c < '0' || c > '9') flag |= (c == '-'), c = getchar();
  while (c >= '0' && c <= '9')
    x = (x << 3) + (x << 1) + (c ^ 48), c = getchar();
  if (flag) x = -x;
  read(Ar...);
}
template <typename T>
inline void write(T x) {
  if (x < 0) {
    x = ~(x - 1);
    putchar('-');
  }
  if (x > 9) write(x / 10);
  putchar(x % 10 + '0');
}
void rd_test() {}
void Time_test() {}
int vec[300000];
int main() {
  int n;
  read(n);
  for (int i = 1; i <= n; i++) {
    read(vec[i]);
  }
  long long ans = 0;
  int len = n;
  if (len % 2 == 1) len--;
  for (int i = 1; i <= len; i += 2) {
    long long sum = vec[i];
    long long L = 0;
    for (int j = i + 1; j <= len; j++) {
      if (j % 2 == 1)
        L += vec[j];
      else {
        long long R = vec[j];
        long long k = min(L, R);
        if (k) {
          R -= k;
          L -= k;
          if (L == 0) ans++;
        }
        if (R > 0) {
          long long k = min(R, sum);
          R -= k;
          sum -= k;
          ans += k;
        }
        if (R > 0) break;
      }
    }
  }
  printf("%lld\n", ans);
}
