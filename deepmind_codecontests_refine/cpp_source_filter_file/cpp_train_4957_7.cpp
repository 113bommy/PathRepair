#include <bits/stdc++.h>
using namespace std;
const int N = 1234567;
int t[N];
int at[N];
int main() {
  int n, T;
  scanf("%d %d", &n, &T);
  for (int i = 0; i < n; i++) {
    scanf("%d", t + i);
  }
  int ans = 0;
  int cur = 0;
  for (int last = 0; last < n && last < T; last++) {
    if (t[last] <= T - 1) {
      cur++;
      int pos = last + 1 + ((T - 1) - t[last]);
      if (pos < n) {
        at[pos]++;
      }
    }
    cur -= at[last];
    ans = max(ans, cur);
  }
  printf("%d\n", ans);
  return 0;
}
