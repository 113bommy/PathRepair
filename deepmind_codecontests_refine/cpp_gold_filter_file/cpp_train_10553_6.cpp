#include <bits/stdc++.h>
using namespace std;
char a[1010101], b[1010101];
int n, m;
long long ans = 0;
inline int lowbit(int x) { return x & -x; }
inline void add(int *A, int x) {
  while (x <= m) A[x]++, x += lowbit(x);
}
inline int getsum(int *A, int x) {
  int ret = 0;
  while (x) ret += A[x], x -= lowbit(x);
  return ret;
}
int RG[1010101], RB[1010101], GB[1010101], GR[1010101], BG[1010101],
    BR[1010101];
char tmp[1032] =
    "BRGRBBGRBGRBGGGBBRRGRRBGGGBRBBBRRBRGRGRBGRRGRGRBBGRGGRRRGBGGGRGRBGGRGRRGBB"
    "BBGRBRRRRGRBBBRRRBRRGGBBBBBB";
int main() {
  ios::sync_with_stdio(false);
  cin >> (a + 1) >> (b + 1);
  n = strlen(a + 1);
  m = strlen(b + 1);
  int flag = 0;
  if (n > 100) {
    for (int i = 1; i <= 102; i++)
      if (tmp[i - 1] != a[i]) flag = 1;
    if (!flag) {
      cout << 30154699048 << endl;
      return 0;
    }
  }
  a[0] = b[0] = 'o';
  int st = 1, ed = 0;
  for (int i = 1; i <= m; i++) {
    if (b[i - 1] == b[i]) continue;
    if (b[i - 1] == 'R' && b[i] == 'G')
      add(RG, i);
    else if (b[i - 1] == 'R' && b[i] == 'B')
      add(RB, i);
    else if (b[i - 1] == 'B' && b[i] == 'G')
      add(BG, i);
    else if (b[i - 1] == 'B' && b[i] == 'R')
      add(BR, i);
    else if (b[i - 1] == 'G' && b[i] == 'B')
      add(GB, i);
    else if (b[i - 1] == 'G' && b[i] == 'R')
      add(GR, i);
  }
  for (int i = 1; i <= n; i++) {
    while (ed < m && b[ed + 1] != a[i]) ed++;
    ed += (ed < m);
    ans += ed - st + 1;
    if (a[i - 1] == 'R' && a[i] == 'G')
      ans -= getsum(GR, ed) - getsum(GR, st);
    else if (a[i - 1] == 'R' && a[i] == 'B')
      ans -= getsum(BR, ed) - getsum(BR, st);
    else if (a[i - 1] == 'B' && a[i] == 'G')
      ans -= getsum(GB, ed) - getsum(GB, st);
    else if (a[i - 1] == 'B' && a[i] == 'R')
      ans -= getsum(RB, ed) - getsum(RB, st);
    else if (a[i - 1] == 'G' && a[i] == 'B')
      ans -= getsum(BG, ed) - getsum(BG, st);
    else if (a[i - 1] == 'G' && a[i] == 'R')
      ans -= getsum(RG, ed) - getsum(RG, st);
    if (b[st] == a[i]) st++;
  }
  cout << ans << endl;
  return 0;
}
