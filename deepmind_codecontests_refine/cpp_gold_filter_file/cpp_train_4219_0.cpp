#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  int arr[n];
  for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
  sort(arr, arr + n);
  int cnt = 0;
  for (int i = n - 1; i >= 0; i--) {
    m -= arr[i];
    cnt++;
    if (m <= 0) break;
  }
  printf("%d\n", cnt);
  return 0;
}
