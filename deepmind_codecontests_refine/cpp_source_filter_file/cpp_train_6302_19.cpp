#include <bits/stdc++.h>
int main() {
  int n;
  scanf("%d", &n);
  int arr[1001], j = 1;
  for (int i = 0; i < 400; i++) {
    if (j < 10)
      arr[i] = j;
    else if (j >= 10 && j <= 99) {
      arr[i] = (j - j % 10) / 10;
      arr[i + 1] = j % 10;
      i = i + 1;
    } else if (j >= 100 && j <= 400) {
      arr[i] = (j - j % 100) / 100;
      arr[i + 1] = (j % 100 - j % 10) / 10;
      arr[i + 2] = j % 10;
      i = i + 2;
    }
    j++;
  }
  printf("%d", arr[n - 1]);
}
