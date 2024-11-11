#include <bits/stdc++.h>
int main() {
  int n;
  long long s;
  scanf("%d %I64d", &n, &s);
  if (s > (1LL * n * (n + 1)) / 2 || s < 1LL * 2 * n - 1) {
    printf("NO");
    return 0;
  }
  int l = 1, r = n;
  while (l < r) {
    int m = (l + r) / 2;
    long long min = 0LL, sum = 1LL;
    if (m == 1)
      min = (long long)n * (n + 1);
    else {
      int h = 1;
      long long v = 1LL;
      while (sum < (long long)n) {
        min += v * h++;
        v *= (long long)m;
        sum += v;
      }
      min += (n + v - sum) * h;
    }
    if (min < s)
      r = m;
    else if (min > s)
      l = m + 1;
    else {
      l = m;
      break;
    }
  }
  int p = n;
  int h = 2;
  int bc = l;
  int lim = bc;
  long long sum = (1LL * n * (n + 1)) / 2;
  int *cnt = (int *)malloc(sizeof(int) * (n + 1));
  for (int i = 1; i <= n; ++i) cnt[i] = 1;
  while (sum > s) {
    int c = (sum - p + h + 1 <= s) ? ((int)(s - sum) + p) : h;
    if (++cnt[c] == lim) ++h, lim *= bc;
    sum = sum - p + c;
    --cnt[p--];
  }
  int *pos = (int *)malloc(sizeof(int) * (n + 1));
  int *res = (int *)malloc(sizeof(int) * (n + 1));
  pos[1] = 1;
  for (int i = 2; i <= n; ++i) pos[i] = pos[i - 1] + cnt[i - 1];
  int i = 2, a = 2;
  while (i <= n && cnt[i] != 0) {
    int j = pos[i - 1];
    int c = bc;
    for (int k = 0; k < cnt[i]; ++k) {
      res[a++] = j;
      if (--c == 0) {
        c = bc;
        ++j;
      }
    }
    ++i;
  }
  printf("YES\n");
  printf("%d", res[2]);
  for (int x = 3; x <= n; ++x) printf(" %d", res[x]);
}
