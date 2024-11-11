#include <bits/stdc++.h>
using namespace std;
const int INF = ~0U >> 1;
const double eps = 1e-6;
const int MAXN = 110000;
int m, nums;
int f[1100][11][10];
char s[20];
int main() {
  scanf("%s", s);
  for (int i = 0; i < 10; i++)
    if (s[i] == '1') nums |= (1 << i);
  scanf("%d", &m);
  memset(f, -1, sizeof f);
  f[0][0][0] = 0;
  f[0][0][1] = 0;
  for (int step = 0; step < m; step++)
    for (int diff = 0; diff < 10; diff++)
      for (int last = 0; last < 10; last++) {
        if (-1 == f[step][diff][last]) continue;
        for (int k = diff; k < 10; k++)
          if ((nums & (1 << k)) && k != last) {
            f[step + 1][k + 1 - diff][k] = last;
          }
      }
  int ok = 0, diff, last;
  for (diff = 0; diff <= 10 && !ok; diff++)
    for (last = 0; last < 10 && !ok; last++)
      if (f[m][diff][last] != -1) {
        ok = 1;
        diff--;
        last--;
      }
  if (!ok) {
    puts("NO");
  } else {
    puts("YES");
    vector<int> ans;
    for (int i = m; i >= 1; i--) {
      ans.push_back(last + 1);
      int new_diff = (last + 1) - diff;
      last = f[i][diff][last];
      diff = new_diff;
    }
    for (int i = ans.size() - 1; i >= 0; i--) printf("%d ", ans[i]);
    printf("\n");
  }
  return 0;
}
