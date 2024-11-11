#include <bits/stdc++.h>
using namespace std;
int n, num[500005];
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) scanf("%d", &num[i]);
  num[n + 1] = num[n];
  int st = 0, ed, cnt = 1;
  int ans = 0;
  for (int i = 1; i <= n; ++i) {
    if (num[i] != num[i + 1]) {
      if (st == 0) st = i;
      cnt++;
    } else if ((st != 0 && num[i] == num[i + 1]) || (st != 0 && i == n)) {
      ed = i;
      if (cnt % 2 == 0) {
        if (num[st] == 1) {
          for (int i = st; i <= st + cnt / 2 - 1; ++i) num[i] = 1;
          for (int i = st + cnt / 2; i <= cnt; ++i) num[i] = 0;
        } else if (num[st] == 0) {
          for (int i = st; i <= st + cnt / 2 - 1; ++i) num[i] = 0;
          for (int i = st + cnt / 2; i <= ed; ++i) num[i] = 1;
        }
        ans = max(cnt / 2 - 1, ans);
        cnt = 1;
        st = 0;
      } else {
        for (int i = st; i <= ed; ++i) num[i] = num[st];
        ans = max(cnt / 2, ans);
        cnt = 1;
        st = 0;
      }
    }
  }
  printf("%d\n", ans);
  for (int i = 1; i <= n; ++i) printf("%d ", num[i]);
  return 0;
}
