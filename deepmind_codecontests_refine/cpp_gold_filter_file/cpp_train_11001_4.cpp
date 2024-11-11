#include <bits/stdc++.h>
int main() {
  int x, sum = 0, sub, counter = 0, i;
  scanf("%d", &x);
  while (sum != x) {
    sub = x - sum;
    if (sub >= 100) {
      i = sub / 100;
      sum = i * 100;
      counter = counter + i;
    } else if (sub >= 20) {
      i = sub / 20;
      sum = sum + i * 20;
      counter = counter + i;
    } else if (sub >= 10) {
      sum = sum + 10;
      counter++;
    } else if (sub >= 5) {
      sum = sum + 5;
      counter++;
    } else if (sub >= 1) {
      sum++;
      counter++;
    }
  }
  printf("%d", counter);
}
