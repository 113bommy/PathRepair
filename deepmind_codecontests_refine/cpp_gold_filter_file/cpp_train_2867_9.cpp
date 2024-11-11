#include <bits/stdc++.h>
int graph[2500][2500];
int arr[50000];
int arr1[25000];
int main() {
  int a, b, c, d;
  scanf("%d%d", &a, &b);
  int x, y, x1, y1;
  scanf("%d%d%d%d", &x, &y, &x1, &y1);
  if (a == 4) {
    printf("-1");
    return 0;
  }
  graph[x][y1] = 1;
  graph[y1][x] = 1;
  int k = 2, z = 0;
  int i;
  arr[0] = x;
  arr[1] = y1;
  for (i = 1; i <= a; i++) {
    if (i != y && i != x1 && i != x && i != y1) arr[k++] = i;
  }
  for (i = 0; i < k - 1; i++) {
    graph[arr[i]][arr[i + 1]] = 1;
    graph[arr[i + 1]][arr[i]] = 1;
  }
  arr[k++] = x1;
  arr[k++] = y;
  arr1[z++] = arr[k - 2];
  arr1[z++] = arr[k - 1];
  for (i = k - 3; i >= 2; i--) {
    arr1[z++] = arr[i];
  }
  arr1[z++] = arr[0];
  arr1[z++] = arr[1];
  graph[y][x1] = 1;
  graph[x1][y] = 1;
  int cnt = k - 1;
  for (i = 0; i < z - 1; i++) {
    if (graph[arr1[i]][arr1[i + 1]] == 0) {
      cnt++;
    }
  }
  if (cnt > b) {
    printf("-1");
    return 0;
  }
  for (i = 0; i < k; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
  for (i = 0; i < z; i++) {
    printf("%d ", arr1[i]);
  }
}
