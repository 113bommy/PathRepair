#include <bits/stdc++.h>
using namespace std;
int n, a[200000], b[200000];
long long apref[200000], bpref[200000];
int binarySearch(long long arr[], int l, int r, long long key) {
  int mid = 0;
  while (l <= r) {
    mid = (l + r) / 2;
    if (arr[mid] == key)
      return mid;
    else if (key < arr[mid])
      r = mid - 1;
    else
      l = mid + 1;
  }
  return -1;
}
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
    b[n - i - 1] = a[i];
    if (i == 0) {
      apref[0] = a[0];
    } else
      apref[i] = apref[i - 1] + a[i];
  }
  bpref[0] = b[0];
  for (int i = 1; i < n; i++) {
    bpref[i] = bpref[i - 1] + b[i];
  }
  long long cnt = 0, maxsum = 0;
  for (int i = 0; i < n; i++) {
    cnt = binarySearch(bpref, 0, n - 2 - i, apref[i]);
    if (cnt != -1 && i + cnt + 2 <= n) maxsum = max(maxsum, apref[i]);
  }
  cout << maxsum;
  return 0;
}
