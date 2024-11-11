#include <bits/stdc++.h>
int main() {
  int n, m;
  int arr[1005] = {0};
  scanf("%d %d", &n, &m);
  int val;
  int mini = 1005;
  for (int i = 0; i < 1005; i++) {
    arr[i] = 0;
  }
  for (int i = 0; i < m; i++) {
    scanf("%d", &val);
    arr[val] += 1;
  }
  for (int i = 0; i < n; i++) {
    if (arr[val] < mini) {
      mini = arr[val];
    }
  }
  printf("%d\n", mini);
  return 0;
}
