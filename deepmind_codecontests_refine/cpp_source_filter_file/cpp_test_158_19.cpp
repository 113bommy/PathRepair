#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    static int xx[10], ans[10000];
    static char s[10][10000 + 1];
    int n, m, ansv;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) scanf("%d", &xx[i]);
    for (int i = 0; i < n; i++) scanf("%s", s[i]);
    ansv = 0;
    memset(ans, 0, m * sizeof *ans);
    for (int b = 0; b < 1 << n; b++) {
      static int kk[10000];
      int sum = 0, cnt;
      vector<int> ii(m);
      for (int i = 0; i < n; i++)
        if (b >> i & 1)
          sum += xx[i];
        else
          sum -= xx[i];
      for (int h = 0; h < m; h++) {
        int k = 0;
        for (int i = 0; i < n; i++)
          if (s[i][h] == '1') {
            if (b >> i & 1)
              k--;
            else
              k++;
          }
        kk[h] = k, ii[h] = h;
      }
      sort(ii.begin(), ii.end(), [&](int i, int j) { return kk[i] < kk[j]; });
      cnt = 1;
      for (int h : ii) sum += kk[h] * cnt++;
      if (sum > ansv) {
        ansv = sum;
        cnt = 1;
        for (int h : ii) {
          ans[h] = cnt++;
        }
      }
    }
    for (int h = 0; h < m; h++) printf("%d ", ans[h]);
    printf("\n");
  }
  return 0;
}
