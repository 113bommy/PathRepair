#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  int arr[n];
  for (int i = 0; i < n; i++) {
    scanf("%d", &arr[i]);
  }
  sort(arr, arr + n);
  reverse(arr, arr + n);
  int lo = 1;
  int hi = n;
  int ans = -1;
  while (lo < hi) {
    int mid = (lo + hi) / 2;
    int cnt = 0;
    int k = 0;
    bool selesai = false;
    for (int i = 0; i < n; i += mid) {
      for (int j = i; j < i + mid; j++) {
        if (j >= n) break;
        if (arr[j] - k <= 0) continue;
        cnt += (arr[j] - k);
        if (cnt >= m) {
          hi = mid;
          ans = mid;
          selesai = true;
          break;
        }
      }
      k++;
      if (selesai) break;
    }
    if (!selesai) {
      lo = mid + 1;
    }
  }
  printf("%d\n", ans);
}
