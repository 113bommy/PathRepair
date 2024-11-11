#include <bits/stdc++.h>
void sort(int a[], int begin, int mid, int end) {
  int i = begin, j = mid + 1, k = 0, temp[end - begin + 1];
  while (i <= mid && j <= end) {
    if (a[i] <= a[j])
      temp[k++] = a[i++];
    else
      temp[k++] = a[j++];
  }
  for (; i <= mid; ++i) temp[k++] = a[i];
  for (; j <= end; ++j) temp[k++] = a[j];
  for (i = 0; i < k; ++i) a[begin + i] = temp[i];
}
void partition(int a[], int begin, int end) {
  if (begin == end) return;
  int mid = (begin + end) / 2;
  partition(a, begin, mid);
  partition(a, mid + 1, end);
  sort(a, begin, mid, end);
}
int main() {
  int n;
  scanf("%d", &n);
  unsigned long long s = 0;
  int i, a[n + 1];
  for (i = 1; i <= n; ++i) scanf("%d", &a[i]);
  partition(a, 1, n);
  for (i = 1; i <= n - 1; ++i) s = s + (a[i] * 1LL) * (i + 1);
  s = s + a[n] * n;
  printf("%I64d\n", s);
  return 0;
}
