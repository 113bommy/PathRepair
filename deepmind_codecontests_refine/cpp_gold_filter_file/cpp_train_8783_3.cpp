#include <bits/stdc++.h>
int a[1000001], s1[1000001], s2[1000001], p1[1000001], p2[1000001];
int n, t1, t2;
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%d", &a[i]);
  int t;
  scanf("%d", &t);
  while (t--) {
    int p;
    scanf("%d", &p);
    a[p - 1] = -a[p - 1];
  }
  bool ok = true;
  t1 = t2 = 0;
  for (int i = 0; i < n; i++) {
    if (a[i] > 0) {
      s1[t1] = a[i];
      p1[t1] = i;
      t1++;
    } else {
      a[i] = -a[i];
      s2[t2] = a[i];
      p2[t2] = i;
      t2++;
      while ((t2 > 0) && (t1 > 0)) {
        if (s1[t1 - 1] == s2[t2 - 1]) {
          t1--;
          t2--;
          a[p2[t2]] = -a[p2[t2]];
        } else {
          t1--;
          s2[t2] = s1[t1];
          p2[t2] = p1[t1];
          t2++;
        }
      }
      if (t2 > 0) ok = false;
    }
    if (!ok) break;
  }
  t2 = 0;
  while (t1 > 0) {
    if (t2 == 0) {
      t1--;
      s2[t2] = s1[t1];
      p2[t2] = p1[t1];
      t2++;
    } else if (s1[t1 - 1] == s2[t2 - 1]) {
      t1--;
      t2--;
      a[p2[t2]] = -a[p2[t2]];
    } else {
      t1--;
      s2[t2] = s1[t1];
      p2[t2] = p1[t1];
      t2++;
    }
  }
  if (t2 + t1 > 0) ok = false;
  if (!ok)
    printf("NO\n");
  else {
    printf("YES\n");
    for (int i = 0; i < n - 1; i++) printf("%d ", a[i]);
    printf("%d\n", a[n - 1]);
  }
  return 0;
}
