#include <bits/stdc++.h>
using namespace std;
long long int rel_inv[25][2];
int arr[(1 << 20) + 5];
void merge_sort(int ss, int mid, int second, int d) {
  if (ss >= second) return;
  merge_sort(ss, (ss + mid) / 2, mid, d - 1);
  merge_sort(mid + 1, (mid + 1 + second) / 2, second, d - 1);
  int aux[second - ss + 1];
  int l = ss, r = mid + 1, i, j = 0;
  for (i = ss; i <= second; i++) {
    if (l > mid)
      aux[j++] = arr[r++];
    else if (r > second)
      aux[j++] = arr[l++];
    else if (arr[l] <= arr[r]) {
      aux[j++] = arr[l++];
    } else {
      rel_inv[d][0] += 1LL * (mid - l + 1);
      aux[j++] = arr[r++];
    }
  }
  l = ss, r = mid + 1, i, j = 0;
  for (i = ss; i <= second; i++) {
    if (l > mid)
      aux[j++] = arr[r++];
    else if (r > second)
      aux[j++] = arr[l++];
    else if (arr[l] >= arr[r]) {
      aux[j++] = arr[r++];
    } else {
      rel_inv[d][1] += 1LL * (second - r + 1);
      aux[j++] = arr[l++];
    }
  }
  for (int i = ss, j = 0; i <= second; i++) arr[i] = aux[j++];
}
int main() {
  int n, m, x;
  scanf("%d", &n);
  int size = 1 << n;
  for (int i = 1; i <= size; i++) scanf("%d", &arr[i]);
  merge_sort(1, (size + 1) / 2, size, n);
  scanf("%d", &m);
  while (m--) {
    scanf("%d", &x);
    long long int ans = 0;
    for (int i = 0; i <= x; i++) swap(rel_inv[i][0], rel_inv[i][1]);
    for (int i = 0; i <= n; i++) {
      ans += rel_inv[i][0];
    }
    printf("%lld\n", ans);
  }
}
