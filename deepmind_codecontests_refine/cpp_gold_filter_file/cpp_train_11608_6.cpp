#include <bits/stdc++.h>
using namespace std;
int a[200000];
int l[2000000], r[2000000];
int cnt[2000000];
int main() {
  int n;
  while (scanf("%d", &n) != EOF) {
    memset(l, -1, sizeof l);
    memset(r, -1, sizeof r);
    memset(cnt, 0, sizeof cnt);
    int maxCnt = 0;
    for (int i = 0; i < n; i++) {
      scanf("%d", &a[i]);
      cnt[a[i]]++;
      maxCnt = max(maxCnt, cnt[a[i]]);
      if (l[a[i]] == -1) {
        l[a[i]] = r[a[i]] = i;
      }
      l[a[i]] = min(l[a[i]], i);
      r[a[i]] = max(r[a[i]], i);
    }
    int ansl = -1, ansr = -1;
    for (int i = 0; i < 2000000; i++) {
      if (cnt[i] != maxCnt) continue;
      if (ansl == -1) {
        ansl = l[i];
        ansr = r[i];
      } else {
        if (ansr - ansl <= r[i] - l[i]) continue;
        ansl = l[i];
        ansr = r[i];
      }
    }
    printf("%d %d\n", ansl + 1, ansr + 1);
  }
  return 0;
}
