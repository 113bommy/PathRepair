#include <bits/stdc++.h>
using namespace std;
const int N = 2000010;
int n, ans = 0, a[N], cnt[N], sqrtn, his[2 * N], q[N];
int main() {
  scanf("%d", &n);
  sqrtn = (int)trunc(sqrt(n));
  int maxCnt = 0, x = 1;
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
    cnt[a[i]]++;
    if (cnt[a[i]] > maxCnt) {
      maxCnt = cnt[a[i]];
      x = a[i];
    }
  }
  for (int i = 0; i <= 2 * n; i++) his[i] = -1;
  for (int i = 1; i <= n; i++) {
    if (i != x && cnt[i] > sqrtn) {
      int now = n, r = 0;
      q[r++] = now;
      his[now] = 0;
      for (int j = 0; j < n; j++) {
        if (a[j] == i) q[r++] = ++now;
        if (a[j] == x) q[r++] = --now;
        if (his[now] == -1)
          his[now] = j + 1;
        else {
          ans = max(ans, j - his[now] + 1);
        }
      }
      for (int j = 0; j < r; j++) his[q[j]] = -1;
    }
  }
  for (int len = 1; len <= sqrtn; len++) {
    int l = 0, num = 0;
    for (int i = 1; i <= n; i++) cnt[i] = 0;
    for (int i = 0; i < n; i++) {
      cnt[a[i]]++;
      if (cnt[a[i]] == len) num++;
      if (cnt[a[i]] > len) {
        while (true) {
          if (cnt[a[l]] == len) num--;
          cnt[a[l]]--;
          l++;
          if (a[l - 1] == a[i]) break;
        }
      }
      if (num > 1) ans = max(ans, i - l + 1);
    }
  }
  printf("%d\n", ans);
  return 0;
}
