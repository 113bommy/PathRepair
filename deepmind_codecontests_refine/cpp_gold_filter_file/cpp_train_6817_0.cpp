#include <bits/stdc++.h>
using namespace std;
const int inf = 1 << 30;
const long long Inf = 1ll << 60ll;
namespace io {
char buf[(1 << 23)], *p1 = buf, *p2 = buf, c;
int f;
template <typename T>
T read() {
  T x = 0;
  f = 0;
  c = (p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, (1 << 23), stdin), p1 == p2)
           ? EOF
           : *p1++);
  while (!isdigit(c))
    (c == '-') && (f = 1),
        c = (p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, (1 << 23), stdin),
                          p1 == p2)
                 ? EOF
                 : *p1++);
  while (isdigit(c))
    x = x * 10 + (c & 15),
    c = (p1 == p2 &&
                 (p2 = (p1 = buf) + fread(buf, 1, (1 << 23), stdin), p1 == p2)
             ? EOF
             : *p1++);
  return f ? -x : x;
}
}  // namespace io
int r, s, p;
double dp[101][101][101], ansR, ansS, ansP;
int main() {
  r = io::read<int>();
  s = io::read<int>();
  p = io::read<int>();
  dp[r][s][p] = 1.0;
  for (int R = r; ~R; --R) {
    for (int S = s; ~S; --S) {
      for (int P = p; ~P; --P) {
        int tot = R * S + S * P + P * R;
        if (R && S) dp[R][S - 1][P] += dp[R][S][P] * R * S / tot;
        if (S && P) dp[R][S][P - 1] += dp[R][S][P] * S * P / tot;
        if (P && R) dp[R - 1][S][P] += dp[R][S][P] * P * R / tot;
        if (R && !S && !P) ansR += dp[R][S][P];
        if (!R && S && !P) ansS += dp[R][S][P];
        if (!R && !S && P) ansP += dp[R][S][P];
      }
    }
  }
  printf("%.12lf %.12lf %.12lf\n", ansR, ansS, ansP);
  return 0;
}
