#include <bits/stdc++.h>
using namespace std;
int log_n;
int n;
int arr[1 << 20];
long long neg_rev[100];
long long rev[100];
int work(int arr[], int n, int num) {
  if (arr[0] >= num) return 0;
  if (arr[n - 1] < num) return n;
  int l = 0;
  int r = n - 1;
  while (l + 1 < r) {
    int mid = (l + r) / 2;
    if (arr[mid] < num)
      l = mid;
    else
      r = mid;
  }
  return r;
}
int work2(int arr[], int n, int num) {
  if (arr[0] > num) return n;
  if (arr[n - 1] <= num) return 0;
  int l = 0;
  int r = n - 1;
  while (l + 1 < r) {
    int mid = (l + r) / 2;
    if (arr[mid] < num)
      l = mid;
    else
      r = mid;
  }
  return n - r;
}
void init(int left, int right, int log_len) {
  if (log_len == 0) return;
  int mid = left + (1 << (log_len - 1));
  init(left, mid, log_len - 1);
  init(mid, right, log_len - 1);
  sort(arr + mid, arr + right);
  for (int i = left; i < mid; i++) {
    rev[log_len] += work(arr + mid, 1 << (log_len - 1), arr[i]);
    neg_rev[log_len] += work2(arr + mid, 1 << (log_len - 1), arr[i]);
  }
}
int main() {
  scanf("%d", &log_n);
  n = 1 << log_n;
  for (int i = 0; i < n; i++) scanf("%d", arr + i);
  init(0, n, log_n);
  int q;
  scanf("%d", &q);
  while (q--) {
    int ctrl;
    scanf("%d", &ctrl);
    for (int i = 0; i <= ctrl; i++) {
      swap(rev[i], neg_rev[i]);
    }
    long long ans = 0;
    for (int i = 0; i <= log_n; i++) ans += rev[i];
    printf("%I64d\n", ans);
  }
  return 0;
}
