#include <bits/stdc++.h>
using namespace std;
long long max(long long a, long long b) {
  if (a > b) {
    return a;
  } else {
    return b;
  }
}
long long min(long long a, long long b) {
  if (a < b) {
    return a;
  } else {
    return b;
  }
}
long long a[5001], b[5001];
int typ[5001], l[5001], r[5001], me[5001], mn;
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  for (int i = (1); i <= (m); i++)
    scanf("%d%d%d%d", &typ[i], &l[i], &r[i], &me[i]);
  for (int i = (1); i <= (n); i++) {
    long long dif = 0, res = 1000000000LL;
    for (int j = (1); j <= (m); j++) {
      if ((l[j] <= i) && (r[j] >= i)) {
        if (typ[j] == 1) {
          dif += me[j];
        } else {
          res = min(res, me[j] - dif);
        }
      }
    }
    if (res < -1000000000) {
      printf("NO\n");
      return 0;
    }
    a[i] = res;
    b[i] = a[i];
  }
  for (int i = (1); i <= (m); i++) {
    if (typ[i] == 1) {
      for (int j = (l[i]); j <= (r[i]); j++) {
        a[j] += me[i];
      }
    } else {
      long long maxi = a[l[i]];
      for (int j = (l[i]); j <= (r[i]); j++) maxi = max(maxi, a[j]);
      if (maxi != me[i]) {
        printf("NO\n");
        return 0;
      }
    }
  }
  printf("YES\n");
  for (int i = (1); i <= (n); i++) printf("%I64d ", b[i]);
  puts("");
  return 0;
}
