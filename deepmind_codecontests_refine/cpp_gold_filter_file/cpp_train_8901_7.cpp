#include <bits/stdc++.h>
int seg[] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
int cal(int x) {
  int sum = 0;
  while (x) {
    sum += seg[x % 10];
    x /= 10;
  }
  return sum;
}
int main() {
  int a, b, sum = 0;
  scanf("%d%d", &a, &b);
  for (int i = a; i <= b; i++) sum += cal(i);
  printf("%d\n", sum);
  return 0;
}
