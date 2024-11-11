#include <bits/stdc++.h>
using namespace std;
const int N = 500005;
int arr[N];
int main() {
  int n, k;
  scanf("%d %d", &n, &k);
  long long sum = 0;
  for (int i = 1; i <= n; i++) {
    scanf("%d", arr + i);
    sum += arr[i];
  }
  sort(arr + 1, arr + 1 + n);
  int l1 = (sum) / n, r1 = (sum + (n - 1)) / n;
  int l = 0, r = l1;
  int ansl = 0, ansr = 0;
  while (l <= r) {
    long long cnt = 0;
    int mid = (l + r) >> 1;
    for (int i = 1; i <= n; i++) {
      if (arr[i] <= mid) cnt += (mid - arr[i]);
    }
    if (cnt <= k)
      ansl = mid, l = mid + 1;
    else
      r = mid - 1;
  }
  l = l1, r = 1e9;
  while (l <= r) {
    long long cnt = 0;
    int mid = (l + r) >> 1;
    for (int i = 1; i <= n; i++) {
      if (arr[i] > mid) cnt += (arr[i] - mid);
    }
    if (cnt <= k)
      ansr = mid, r = mid - 1;
    else
      l = mid + 1;
  }
  printf("%d", ansr - ansl);
}
