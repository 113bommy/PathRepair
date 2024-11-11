#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 10;
int n;
int a[maxn];
int cnt[maxn];
int inc[maxn], d[maxn];
int cnt_inc, cnt_d;
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    cnt[a[i]]++;
    if (cnt[a[i]] == 3) {
      printf("NO\n");
      return 0;
    }
  }
  printf("Yes\n");
  for (int i = 0; i <= 200000; i++) {
    if (cnt[i] == 1) {
      inc[cnt_inc + 1] = i;
      cnt_inc++;
    }
    if (cnt[i] == 2) {
      d[cnt_d + 1] = i;
      inc[cnt_inc + 1] = i;
      cnt_inc++;
      cnt_d++;
    }
  }
  printf("%d\n", cnt_inc);
  for (int i = 1; i <= cnt_inc; i++) {
    printf("%d ", inc[i]);
  }
  printf("\n%d\n", cnt_d);
  for (int i = cnt_d; i > 0; i--) {
    printf("%d ", d[i]);
  }
  return 0;
}
