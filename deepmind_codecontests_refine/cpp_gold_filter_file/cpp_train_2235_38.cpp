#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b;
  while (scanf("%d%d", &a, &b) != EOF) {
    int max = 0;
    int number1 = a, number2 = b;
    int number, c = 0, count = 0;
    while (number1) {
      if (number1 % 10 > max) max = number1 % 10;
      number1 /= 10;
    }
    while (number2) {
      if (number2 % 10 > max) max = number2 % 10;
      number2 /= 10;
    }
    max++;
    while (a && b) {
      number = a % 10 + b % 10 + c;
      c = number / max;
      count++;
      a /= 10;
      b /= 10;
    }
    while (a) {
      number = a % 10 + c;
      c = number / max;
      count++;
      a /= 10;
    }
    while (b) {
      number = b % 10 + c;
      c = number / max;
      count++;
      b /= 10;
    }
    while (number >= max) {
      number -= max;
      count++;
    }
    printf("%d\n", count);
  }
  return 0;
}
