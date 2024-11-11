#include <bits/stdc++.h>
using namespace std;
template <typename T>
inline void read(T& x) {
  char c = getchar();
  bool f = false;
  for (x = 0; !isdigit(c); c = getchar()) {
    if (c == '-') {
      f = true;
    }
  }
  for (; isdigit(c); c = getchar()) {
    x = x * 10 + c - '0';
  }
  if (f) {
    x = -x;
  }
}
template <typename T, typename... U>
inline void read(T& x, U&... y) {
  read(x), read(y...);
}
const int N = 2e3 + 10;
const double PI = 3.1415926535897932384626433832795, eps = 1e-6;
int n;
double X[N], Y[N], Pa[N];
int main() {
  read(n);
  for (int i = 1; i <= n; ++i) scanf("%lf%lf", &X[i], &Y[i]);
  long long res = 0;
  for (int i = 1; i <= n; ++i) {
    int cnt = 0;
    for (int j = 1; j <= n; ++j)
      if (i != j) Pa[++cnt] = atan2(Y[j] - Y[i], X[j] - X[i]);
    sort(Pa + 1, Pa + cnt + 1);
    for (int j = 1, k = 1; j <= cnt && Pa[j] <= eps; ++j) {
      while (k != cnt && Pa[k + 1] <= Pa[j] + PI) ++k;
      res += 1ll * (k - j) * (k - j - 1) * (cnt - k + j - 1) *
             (cnt - k + j - 2) / 2;
    }
  }
  printf("%lld\n", res / 2);
  return 0;
}
