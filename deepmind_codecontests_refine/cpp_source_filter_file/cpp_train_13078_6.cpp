#include <bits/stdc++.h>
int a[500];
int temp1[500];
int temp2[500];
int sum[500];
void merge(int l, int mid, int r) {
  int i, j, k;
  for (i = l; i <= mid; i++) temp1[i - l] = a[i];
  temp1[i - l] = 10000000;
  for (j = mid + 1; j <= r; j++) temp2[j - mid - 1] = a[j];
  temp2[j - mid - 1] = 1000000;
  i = 0;
  j = 0;
  k = l;
  while (k <= r) {
    if (temp1[i] < temp2[j]) {
      a[k] = temp1[i];
      i++;
    } else {
      a[k] = temp2[j];
      j++;
    }
    k++;
  }
}
void sorti(int l, int r) {
  if (l >= r) return;
  int mid = (l + r) / 2;
  sorti(l, mid);
  sorti(mid + 1, r);
  merge(l, mid, r);
}
int main() {
  int n;
  scanf("%d", &n);
  int i, j, k;
  for (i = 1; i <= n; i++) scanf("%d", &a[i]);
  int left = 0, right = 0;
  for (i = 1; i <= n; i++) {
    sum[i] = sum[i - 1] + a[i];
  }
  int val, val1;
  int ans = 360;
  for (i = 1; i <= n; i++) {
    for (j = i + 1; j <= n; j++) {
      val1 = (sum[j] - sum[i - 1]);
      val = 360 - val1;
      val = val > val1 ? (val - val1) : (val1 - val);
      ans = ans > val ? val : ans;
    }
  }
  printf("%d\n", ans);
  return 0;
}
