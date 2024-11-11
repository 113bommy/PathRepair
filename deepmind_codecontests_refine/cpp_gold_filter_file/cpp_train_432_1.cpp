#include <bits/stdc++.h>
void merging(long long arr[], long long start, long long mid, long long end);
void sort(long long arr[], long long start, long long end) {
  long long mid;
  if (end - start + 1 > 1) {
    mid = (start + end) / 2;
    sort(arr, start, mid);
    sort(arr, mid + 1, end);
    merging(arr, start, mid, end);
  }
}
void merging(long long arr[], long long start, long long mid, long long end) {
  long long len1, len2, i, j, k;
  len1 = mid - start + 1;
  len2 = end - mid - 1 + 1;
  long long right[len2], left[len1];
  for (i = 0; i < len1; i++) {
    left[i] = arr[i + start];
  }
  for (i = 0; i < len2; i++) {
    right[i] = arr[i + mid + 1];
  }
  i = 0;
  j = 0;
  k = start;
  while ((i < len1) && (j < len2)) {
    if (left[i] > right[j]) {
      arr[k] = right[j];
      j++;
      k++;
    } else {
      arr[k] = left[i];
      i++;
      k++;
    }
  }
  if (i == len1) {
    while (j < len2) {
      arr[k] = right[j];
      j++;
      k++;
    }
  } else {
    while (i < len1) {
      arr[k] = left[i];
      i++;
      k++;
    }
  }
}
long long gcd(long long a, long long b) {
  if (a == b)
    return a;
  else if (a == 0)
    return b;
  else if (b == 0)
    return a;
  else
    return gcd(b, a % b);
}
int main() {
  long long n;
  scanf("%I64lld", &n);
  long long a[200005];
  for (int i = 0; i < n; i++) {
    scanf("%I64lld", &a[i]);
  }
  sort(a, 0, n - 1);
  long long cor[200005], l = 0;
  for (long long int i = 0; i < n - 1; i++) {
    if (a[i] != a[i + 1]) {
      cor[l] = a[i];
      l++;
    }
  }
  {
    cor[l] = a[n - 1];
    l++;
  }
  long long min[200005];
  for (long long int i = 0; i < l - 1; i++) {
    min[i] = cor[i + 1] - cor[i];
  }
  long long mini = cor[1] - cor[0];
  for (int i = 0; i < l - 1; i++) {
    mini = gcd(min[i], mini);
  }
  long long nop = 0;
  for (long long int i = 0; i < n; i++) {
    nop = nop + (a[n - 1] - a[i]) / mini;
  }
  printf("%I64lld %I64lld\n", nop, mini);
  return 0;
}
