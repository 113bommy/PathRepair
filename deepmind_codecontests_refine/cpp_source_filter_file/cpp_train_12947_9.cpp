#include <bits/stdc++.h>
int a[1000000];
int res[1000000];
int main(int argc, char const *argv[]) {
  int i, n, k, l, r;
  scanf("%d %d", &n, &k);
  for (i = 1; i <= n; i++) scanf("%d", &a[i]);
  for (i = 1; i <= n; i++) {
    if ((a[i - 1] == a[i + 1]) && (a[i] != a[i - 1]))
      res[a[i]] += 2;
    else if ((a[i - 1] != a[i + 1]) && (a[i] != a[i - 1]) && (a[i] != a[i + 1]))
      res[a[i]]++;
    else {
      if ((a[i] != a[i - 1]) && (a[i + 1] == a[i])) {
        l = a[i - 1];
      } else if ((a[i] == a[i - 1]) && (a[i + 1] != a[i])) {
        r = a[i - 1];
        if (l == r)
          res[a[i]] += 2;
        else
          res[a[i]]++;
      }
    }
  }
  int rs = res[1], index = 1;
  for (i = 1; i <= k; i++) {
    if (res[i] > rs) {
      index = i;
      rs = res[i];
    }
  }
  printf("%d\n", index);
  return 0;
}
