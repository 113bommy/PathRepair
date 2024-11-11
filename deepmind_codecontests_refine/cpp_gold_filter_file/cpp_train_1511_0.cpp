#include <bits/stdc++.h>
using namespace std;
const int MAXW = 5000000;
int n, cnt[MAXW];
int main(void) {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    int w;
    scanf("%d", &w);
    ++cnt[w];
  }
  int ans = 0;
  for (int t = 0; t < 5000000; ++t) {
    while (cnt[t] >= 2) {
      cnt[t + 1] += 1;
      cnt[t] -= 2;
    }
    if (cnt[t]) ++ans;
  }
  printf("%d\n", ans);
  return 0;
}
