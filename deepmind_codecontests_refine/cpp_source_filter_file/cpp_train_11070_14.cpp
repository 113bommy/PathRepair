#include <bits/stdc++.h>
int suit[110000];
int city[110000];
int n, c;
long long max(long long x, long long y) { return x > y ? x : y; }
int Getdays(long long x) {
  long long sum = 0;
  for (int i = 1; i <= n; i++) {
    if (1. * x * suit[i] > 1LL * city[i] * c + 1LL * city[i] * 100)
      return c + 1000LL;
    sum += 1 + suit[i] * x / city[i];
  }
  return sum;
}
long long search_Left(long long l, long long r) {
  while (l < r) {
    long long mid = (l + r + 1) / 2;
    long long days = Getdays(mid);
    if (days > c)
      r = mid - 1;
    else
      l = mid;
  }
  return l;
}
long long search_Right(long long l, long long r) {
  while (l < r) {
    long long mid = (l + r) / 2;
    long long days = Getdays(mid);
    if (days < c)
      l = mid + 1;
    else
      r = mid;
  }
  return l;
}
int main() {
  while (scanf("%d%d", &n, &c) != EOF) {
    int maxn = 0;
    bool flag = 1;
    for (int i = 1; i <= n; i++) {
      scanf("%d%d", &suit[i], &city[i]);
      flag &= !suit[i];
    }
    if (flag) {
      if (c == n)
        puts("-1");
      else
        puts("0");
      continue;
    }
    long long limit = 2000000000000000000LL;
    long long left = search_Left(1, limit);
    if (Getdays(left) != c) {
      puts("0");
      continue;
    }
    long long right = search_Right(1, limit);
    printf("%I64d\n", max(left - right + 1, 0LL));
  }
  return 0;
}
