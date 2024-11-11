#include <bits/stdc++.h>
using namespace std;
int a[3][400000], n;
void swap(int &a, int &b) {
  int t = a;
  a = b;
  b = t;
}
void quicksort(int l, int h, int x) {
  if (l < h) {
    int i = l, j = h, k = a[x][rand() % (h - l + 1) + l];
    do {
      while (a[x][i] < k) i++;
      while (a[x][j] > k) j--;
      if (i <= j) {
        if (i < j) {
          swap(a[0][i], a[0][j]);
          swap(a[1][i], a[1][j]);
          swap(a[2][i], a[2][j]);
        }
        i++;
        j--;
      }
    } while (i <= j);
    quicksort(l, j, x);
    quicksort(i, h, x);
  }
}
void enter() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[0][i]);
    a[1][i] = i;
  }
  a[0][n] = 1000000001;
  quicksort(0, n - 1, 0);
  int x = a[0][0];
  int i = 0;
  while (i < n) {
    a[2][i] = x;
    if (a[0][i] == a[0][i + 1]) {
      x++;
    } else {
      if (x < a[0][i + 1])
        x = a[0][i + 1];
      else
        x++;
    }
    i++;
  }
  quicksort(0, n - 1, 1);
  for (int i = 0; i < n - 1; i++) printf("%d ", a[2][i]);
  printf("%d", a[2][n - 1]);
}
int main() {
  enter();
  return 0;
}
