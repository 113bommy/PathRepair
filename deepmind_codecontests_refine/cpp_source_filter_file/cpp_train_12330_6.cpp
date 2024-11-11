#include <bits/stdc++.h>
int arr[100005], first, vilable;
char op, id;
int main() {
  int n, m;
  int onNum = 0;
  int sum;
  while (~scanf("%d%d", &n, &m)) {
    memset(arr, 0, sizeof(arr));
    onNum = 0;
    sum = 0;
    for (int i = 0; i < m; i++) {
      getchar();
      scanf("%c %d", &op, &id);
      if (i == 0) {
        first = id;
        vilable = 1;
      }
      if (op == '+') {
        if (id != first && arr[first] == -1) vilable = 0;
        arr[id] = 1;
        onNum++;
      } else {
        if (arr[id] == 1) onNum--;
        if (id != first && arr[id] == 0) {
          first = id;
          vilable = 1;
        }
        if (id == first && onNum > 0) {
          vilable = 0;
        }
        arr[id] = -1;
      }
    }
    if (vilable) arr[first] = 0;
    for (int i = 1; i <= n; i++) {
      if (arr[i] == 0) sum++;
    }
    printf("%d\n", sum);
    for (int i = 1; i <= n; i++) {
      if (arr[i] == 0) printf("%d ", i);
    }
    printf("\n");
  }
  return 0;
}
