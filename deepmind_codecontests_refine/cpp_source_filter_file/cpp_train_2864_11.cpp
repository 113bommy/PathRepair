#include <bits/stdc++.h>
using namespace std;
int n, q, i, a[100100], d[100100], l, r, s1[100100], s2[100100], k, j;
long long ans;
int main() {
  scanf("%d%d", &n, &q);
  for (i = 0; i < n; i++) scanf("%d", &a[i]);
  for (i = 1; i < n; i++) {
    d[i] = abs(a[i] - a[i - 1]);
  }
  d[n] = 2147483647;
  d[0] = 2147483647;
  for (i = 1; i < n; i++) {
    if (d[i - 1] > d[i])
      s1[i] = 1;
    else {
      k = s1[i - 1];
      int j = i;
      while (1) {
        s1[i] += k;
        j -= k;
        if (d[j - 1] > d[i]) break;
        k = s1[j - 1];
      }
      s1[i]++;
    }
  }
  for (i = n - 1; i >= 1; i--) {
    if (d[i + 1] >= d[i])
      s2[i] = 1;
    else {
      k = s2[i + 1];
      j = i;
      while (1) {
        s2[i] += k;
        j += k;
        if (d[j + 1] >= d[i]) break;
        k = s2[j + 1];
      }
      s2[i]++;
    }
  }
  for (i = 0; i < q; i++) {
    scanf("%d%d", &l, &r);
    ans = 0;
    for (j = l; j < r; j++) {
      ans += (long long)d[j] *
             (long long)(((s1[j]) > (j - l + 1) ? (j - l + 1) : (s1[j]))) *
             (long long)(((s2[j]) > (r - j) ? (r - j) : (s2[j])));
    }
    printf("%d\n", ans);
  }
}
