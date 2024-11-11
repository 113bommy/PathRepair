#include <bits/stdc++.h>
#pragma warning(disable : 4996)
int arr[100001][4];
int my_comp(const void *a, const void *b) {
  int *x = (int *)a, *y = (int *)b;
  return x[1] - y[1];
}
int my_comp_2(const void *a, const void *b) {
  int *x = (int *)a, *y = (int *)b;
  return x[2] - y[2];
}
int main() {
  int n, m, i, j, k;
  int curr_st_from = 1, curr_st_to = 0, curr_time = 0, curr_x = 0;
  scanf("%d %d", &n, &m);
  for (i = 1; i <= n; ++i) {
    scanf("%d %d", &arr[i][0], &arr[i][1]);
    arr[i][2] = i;
  }
  while (curr_st_from != n + 1) {
    curr_x = 0;
    k = 0;
    curr_st_to = (curr_st_from + m - 1 > n) ? n : curr_st_from + m - 1;
    curr_time =
        (arr[curr_st_to][0] > curr_time) ? arr[curr_st_to][0] : curr_time;
    qsort(arr[curr_st_from], curr_st_to - curr_st_from + 1, sizeof(int) * 4,
          my_comp);
    for (j = curr_st_from; j <= curr_st_to; ++j) {
      if (curr_x == arr[j][1]) {
        k++;
      } else {
        curr_time += (k == 0) ? 0 : k / 2 + 1;
        curr_time += arr[j][1] - curr_x;
        curr_x = arr[j][1];
        k = 1;
      }
      arr[j][3] = curr_time;
    }
    curr_time += curr_x;
    curr_x = 0;
    curr_time += (k == 0) ? 0 : k / 2 + 1;
    k = 0;
    curr_st_from = curr_st_to + 1;
  }
  qsort(arr[0], n, sizeof(int) * 4, my_comp_2);
  for (i = 1; i <= n; ++i) {
    printf("%d ", arr[i][3]);
  }
  return 0;
}
