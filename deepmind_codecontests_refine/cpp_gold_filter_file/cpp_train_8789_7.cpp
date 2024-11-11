#include <bits/stdc++.h>
int arr[1000111];
int main() {
  int n, m;
  long long min, max, mid;
  long long a;
  long long dist = 0;
  bool var = false;
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
  min = arr[0];
  mid = arr[n / 2];
  max = arr[n - 1];
  for (int i = 0; i < n / 2; i += m) {
    dist += (mid - arr[i]) * 2;
  }
  for (int i = n - 1; i >= n / 2; i -= m) {
    dist += (arr[i] - mid) * 2;
  }
  printf("%I64d", dist);
  return 0;
}
