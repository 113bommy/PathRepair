#include <bits/stdc++.h>
int main() {
  int a[1001], n, i = 0, j, temp;
  char ch[1001];
  for (i = 0; i < 1000; i++) {
    a[i] = 1;
  }
  scanf("%d", &n);
  scanf("%s", &ch);
  temp = n;
  for (i = 0; i <= n - 1; i++) {
    if (ch[i] == 'L' && a[i] <= a[i + 1]) {
      a[i] = a[i + 1] + 1;
      for (j = i; j >= 0; j--) {
        if (a[j] >= a[j - 1] && ch[j - 1] == 'L') {
          a[j - 1] = a[j] + 1;
        }
        if (a[i] >= a[j - 1] && ch[j - 1] == '=') {
          a[j - 1] = a[j];
        }
      }
    }
    if (ch[i] == 'R' && a[i + 1] <= a[i]) {
      a[i + 1] = a[i] + 1;
    }
    if (ch[i] == '=') {
      a[i + 1] = a[i];
    }
  }
  for (i = 0; i < temp; i++) printf("%d ", a[i]);
}
