#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, a, b, c, t;
  long long arr[100005];
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%I64d", &arr[i]);
  }
  int now = 0;
  int temp[2] = {0, 0};
  temp[0] = arr[n - 1];
  for (int i = n - 2; i >= 0; i--) {
    arr[i] += temp[now];
    arr[i] -= temp[(now + 1) % 2];
    now = (now + 1) % 2;
    temp[now] += arr[i];
  }
  for (int i = 0; i < n; i++) {
    printf("%I64d", arr[i]);
    if (i + 1 < n)
      printf(" ");
    else
      printf("\n");
  }
  return 0;
}
