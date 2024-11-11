#include <bits/stdc++.h>
int dif[1000000];
int temp[1000000];
int arr[1000000];
int main() {
  int n;
  scanf("%d", &n);
  int min;
  for (int i = 0; i < n; ++i) {
    scanf("%d", &arr[i]);
  }
  min = arr[0];
  for (int i = 1; i < n; ++i) {
    if (min > arr[i]) {
      min = arr[i];
    }
  }
  int mindex = 0;
  int count = 0;
  int j = 0;
  for (int i = 0; i < n; ++i) {
    if (arr[i] == min) {
      temp[j] = i;
      j++;
    }
  }
  for (int i = 0; i < j - 1; ++i) {
    dif[i] = temp[i + 1] - temp[i];
  }
  int a = dif[0];
  for (int i = 0; i < j - 1; ++i) {
    if (a > dif[i]) {
      a = dif[i];
    }
  }
  printf("%d\n", a);
}
