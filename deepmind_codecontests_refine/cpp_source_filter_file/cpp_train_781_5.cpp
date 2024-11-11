#include <bits/stdc++.h>
int n, k, q, i, j, kontrol, type, yer, id, t[150005], cvp[10];
void cikar();
int main() {
  scanf("%d %d %d", &n, &k, &q);
  for (i = 0; i < n; i++) scanf("%d", &t[i]);
  for (i = 0; i < q; i++) {
    scanf("%d %d", &type, &id);
    if (type == 1) {
      cvp[yer++] = id;
      if (yer > k) {
        cikar();
      }
    } else {
      kontrol = 0;
      for (j = 0; j < yer; j++)
        if (cvp[j] == id) kontrol = 1;
      if (kontrol)
        printf("YES\n");
      else
        printf("NO\n");
    }
  }
  return 0;
}
void cikar() {
  int i, mn = 1000000005, ind, a[10] = {0}, place = 0;
  for (i = 0; i < yer; i++) {
    if (t[cvp[i - 1]] < mn) {
      mn = t[cvp[i - 1]];
      ind = i;
    }
  }
  for (i = 0; i < yer; i++) {
    if (i != ind) a[place++] = cvp[i];
    cvp[i] = 0;
  }
  for (i = 0; i < 10; i++) cvp[i] = a[i];
  yer--;
  return;
}
