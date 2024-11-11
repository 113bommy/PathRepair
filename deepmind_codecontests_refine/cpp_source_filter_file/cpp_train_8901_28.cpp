#include <bits/stdc++.h>
int solution(int arg, int arg1) {
  int ret = 0;
  int i;
  int rem;
  int number;
  for (i = arg; i <= arg1; ++i) {
    number = i;
    while (number) {
      rem = number % 10;
      switch (rem) {
        case 0:
          ret += 6;
          break;
        case 1:
          ret += 2;
          break;
        case 2:
          ret += 5;
          break;
        case 3:
          ret += 5;
          break;
        case 4:
          ret += 4;
          break;
        case 5:
          ret += 5;
          break;
        case 6:
          ret += 6;
          break;
        case 7:
          ret += 3;
          break;
        case 8:
          ret += 7;
          break;
        case 9:
          ret += 9;
          break;
      }
      number = number / 10;
    }
  }
  return ret;
}
int main() {
  int a, b;
  int sol;
  scanf("%d", &a);
  scanf("%d", &b);
  sol = solution(a, b);
  printf("%d \n", sol);
  return 0;
}
