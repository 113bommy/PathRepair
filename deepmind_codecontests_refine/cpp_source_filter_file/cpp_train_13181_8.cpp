#include <bits/stdc++.h>
using namespace std;
int cnt[25];
int n, k;
int main() {
  while (~scanf("%d%d", &n, &k)) {
    memset(cnt, 0, sizeof(cnt));
    for (int i = 0; i < n; i++) {
      int cur = 0;
      for (int j = 0; j < k; j++) {
        int tp;
        scanf("%d", &tp);
        cur += tp;
        cur *= 2;
      }
      cnt[cur]++;
    }
    int ans = 0;
    for (int i = 0; i < 16; i++) {
      for (int j = 0; j < 16; j++) {
        if (cnt[i] != 0 && cnt[j] != 0 && (i & j) == 0) {
          ans = 1;
          break;
        }
      }
      if (ans == 1) break;
    }
    if (ans == 1)
      printf("YES\n");
    else
      printf("NO\n");
  }
}
