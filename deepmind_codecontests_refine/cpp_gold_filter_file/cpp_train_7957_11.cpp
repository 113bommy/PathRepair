#include <bits/stdc++.h>
int partition(int a[], int low, int high);
void quicksort(int a[], int low, int high);
int main() {
  char s[1001];
  int i, len, a[26], k;
  long int sum = 0;
  scanf("%s", s);
  len = strlen(s);
  scanf("%d", &k);
  for (i = 0; i < 26; i++) scanf("%d", &a[i]);
  for (i = 0; i < len; i++) sum = sum + ((i + 1) * a[s[i] - 97]);
  if (k == 0)
    printf("%ld", sum);
  else {
    quicksort(a, 0, 25);
    for (i = 0; i < k; i++) {
      sum = sum + ((len + 1) * a[0]);
      len += 1;
    }
    printf("%ld", sum);
  }
  return 0;
}
void quicksort(int a[], int low, int high) {
  int j;
  if (low < high) {
    j = partition(a, low, high);
    quicksort(a, low, j);
    quicksort(a, j + 1, high);
  }
}
int partition(int a[], int low, int high) {
  int temp, down, up, x;
  x = a[low];
  down = low - 1;
  up = high + 1;
  while (1) {
    do {
      down++;
    } while (a[down] > x);
    do {
      up--;
    } while (a[up] < x);
    if (down < up) {
      temp = a[down];
      a[down] = a[up];
      a[up] = temp;
    } else {
      temp = a[low];
      a[low] = a[up];
      a[up] = temp;
      return up;
    }
  }
}
