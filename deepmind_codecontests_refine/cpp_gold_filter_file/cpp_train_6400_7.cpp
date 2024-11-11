#include <bits/stdc++.h>
using namespace std;
inline int gi() {
  char tmp = getchar();
  int ans = 0, flag = 1;
  while (!isdigit(tmp)) {
    if (tmp == '-') flag = -1;
    tmp = getchar();
  }
  while (isdigit(tmp)) {
    ans = ans * 10 + tmp - '0';
    tmp = getchar();
  }
  return ans * flag;
}
inline void in(int &x) { x = gi(); }
inline void in2(int &x, int &y) { in(x), in(y); }
inline void in3(int &x, int &y, int &z) { in(x), in(y), in(z); }
inline void in4(int &x, int &y, int &z, int &a) { in3(x, y, z), in(a); }
inline int smax(int &x, int y) { return x = max(x, y); }
inline int smin(int &x, int y) { return x = min(x, y); }
const int inf = 2147483647;
const int N = 5e5 + 100;
map<int, int> Lst;
int cnt = 0;
int L[N], R[N], F[22][N], Log[N], all;
int A[N];
int Query(int l, int r) {
  int d = Log[r - l + 1];
  return min(F[d][l], F[d][r - (1 << d) + 1]);
}
signed main() {
  int n = gi(), m = gi();
  memset(F, 127, sizeof F);
  for (int i = (int)(1); i <= (int)(n); ++i) {
    int x = gi();
    int lst = Lst[x];
    if (lst > L[cnt]) {
      L[++cnt] = lst;
      R[cnt] = i;
      F[0][cnt] = i - lst;
    }
    Lst[x] = i;
  }
  Log[0] = -1;
  for (int i = (int)(1); i <= (int)(cnt); ++i) Log[i] = Log[i >> 1] + 1;
  for (int j = (int)(1); j <= (int)(21); ++j) {
    for (int i = (int)(1); i <= (int)(cnt); ++i) {
      if (i + (1 << j) > cnt + 1) break;
      F[j][i] = min(F[j - 1][i], F[j - 1][i + (1 << (j - 1))]);
    }
  }
  for (int i = (int)(1); i <= (int)(m); ++i) {
    int x, y;
    in2(x, y);
    int l, r;
    l = lower_bound(L + 1, L + cnt + 1, x) - L;
    r = upper_bound(R + 1, R + cnt + 1, y) - R - 1;
    if (l <= r)
      printf("%d\n", Query(l, r));
    else
      puts("-1");
  }
  return 0;
}
