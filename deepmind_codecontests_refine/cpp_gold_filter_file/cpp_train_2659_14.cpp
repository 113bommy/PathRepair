#include <bits/stdc++.h>
int main() {
  int n, h;
  scanf("%d %d", &n, &h);
  int width = n;
  int temp;
  for (int i = 0; i < n; i++) {
    scanf("%d", &temp);
    if (temp > h) {
      width += 1;
    }
  }
  printf("%d", width);
}
