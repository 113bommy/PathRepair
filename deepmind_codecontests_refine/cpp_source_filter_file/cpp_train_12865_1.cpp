#include <bits/stdc++.h>
void find_runs(int **arr, int col, int colnum);
int collapse(int *arr, int size);
int main(int argc, char *argv[]) {
  int n, m;
  int x;
  int i, j;
  int k;
  int l, r;
  int **arr;
  int *table;
  scanf("%d %d", &n, &m);
  arr = (int **)malloc(n * sizeof(int *));
  for (i = 0; i < n; i++) {
    arr[i] = (int *)malloc(m * sizeof(int));
  }
  table = (int *)malloc(n * sizeof(int));
  for (i = 0; i < n; i++) {
    for (j = 0; j < m; j++) {
      scanf("%d", &x);
      arr[i][j] = x;
    }
  }
  for (j = 0; j < m; j++) {
    find_runs(arr, j, n);
  }
  for (i = 0; i < n; i++) {
    table[i] = collapse(arr[i], m);
  }
  scanf("%d", &k);
  for (i = 0; i < k; i++) {
    scanf("%d %d", &l, &r);
    if (table[l] >= r) {
      printf("Yes\n");
    } else {
      printf("No\n");
    }
  }
}
void find_runs(int **arr, int col, int colnum) {
  int pdex;
  int i, j;
  pdex = 0;
  for (i = 1; i < colnum; i++) {
    if (arr[i - 1][col] >= arr[i][col]) {
      for (j = pdex; j < i; j++) {
        arr[j][col] = i;
      }
      pdex = i;
    }
  }
  for (j = pdex; j < i; j++) {
    arr[j][col] = i;
  }
}
int collapse(int *arr, int size) {
  int max = 0;
  int i;
  for (i = 0; i < size; i++) {
    if (arr[i] > max) {
      max = arr[i];
    }
  }
  return max;
}
