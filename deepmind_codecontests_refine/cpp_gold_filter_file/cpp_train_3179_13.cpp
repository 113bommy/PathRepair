#include <bits/stdc++.h>
using namespace std;
int main() {
  int i, j, t;
  int n;
  int a[1005];
  cin >> n;
  for (i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }
  sort(a, a + n);
  int b[1005];
  b[0] = a[0];
  j = 1;
  int low = 1;
  int high = n - 1;
  int flag = 1;
  while (low <= high) {
    if (flag) {
      b[j++] = a[high--];
      flag = 0;
    } else {
      b[j++] = a[low++];
      flag = 1;
    }
  }
  flag = 1;
  for (i = 0; i < n - 1; i++) {
    if (i % 2 == 0) {
      if (b[i] > b[i + 1]) {
        flag = 0;
        break;
      }
    } else {
      if (b[i] < b[i + 1]) {
        flag = 0;
        break;
      }
    }
  }
  if (!flag) {
    printf("Impossible\n");
  } else {
    for (i = 0; i < n; i++) printf("%d ", b[i]);
    printf("\n");
  }
  return 0;
}
