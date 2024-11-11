#include <bits/stdc++.h>
using namespace std;
using namespace std;
const long long N = 0 ? 15 : 500005;
int n, a[N];
int dp[N][2][2];
pair<int, int> pre[N][2][2];
int main(int argc, const char *argv[]) {
  int t;
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &n);
    for (int(i) = (1); (i) <= (long long)(n); (i)++) scanf("%d", &a[i]);
    for (int(i) = (0); (i) <= (long long)(1); (i)++)
      for (int(j) = (0); (j) <= (long long)(1); (j)++) dp[0][i][j] = -1e9;
    a[0] = 1e9;
    for (int(i) = (1); (i) <= (long long)(n); (i)++) {
      for (int(pos) = (0); (pos) <= (long long)(1); (pos)++) {
        for (int(sign) = (0); (sign) <= (long long)(1); (sign)++) {
          int &ans = dp[i][pos][sign];
          ans = 1e9;
          int z = sign ? a[i] : -a[i];
          for (int(psig) = (0); (psig) <= (long long)(1); (psig)++)
            for (int(ppos) = (0); (ppos) <= (long long)(1); (ppos)++) {
              int x = psig ? a[i - 1] : -a[i - 1];
              int y = dp[i - 1][ppos][psig];
              if (ppos) {
                swap(x, y);
              }
              if (z > x && !pos) {
                if (ans > y) {
                  ans = y;
                  pre[i][pos][sign] = {ppos, psig};
                }
              } else if (z > y && pos) {
                if (ans > x) {
                  ans = x;
                  pre[i][pos][sign] = {ppos, psig};
                }
              }
            }
        }
      }
    }
    int pos = -1, sign = -1;
    for (int(p) = (0); (p) <= (long long)(1); (p)++)
      for (int(second) = (0); (second) <= (long long)(1); (second)++)
        if (dp[n][p][second] != 1e9) {
          pos = p;
          sign = second;
        }
    if (pos == -1) {
      printf("NO\n");
      continue;
    }
    for (long long(i) = (n); (i) >= (1); --(i)) {
      a[i] = sign ? a[i] : -a[i];
      pair<int, int> nxt = pre[i][pos][sign];
      pos = nxt.first;
      sign = nxt.second;
    }
    printf("YES\n");
    for (int(i) = (1); (i) <= (long long)(n); (i)++) printf("%d ", a[i]);
    printf("\n");
  }
  return 0;
}
