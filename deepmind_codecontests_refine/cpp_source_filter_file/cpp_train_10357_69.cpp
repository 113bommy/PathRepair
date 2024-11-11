#include <bits/stdc++.h>
int n, a, b;
int main() {
  scanf("%d", &n);
  a = n / 10;
  b = n % 10;
  if (a == 1) {
    if (n == 10) printf("ten");
    if (n == 11) printf("eleven");
    if (n == 12) printf("twelve");
    if (n == 13) printf("thirteen");
    if (n == 14) printf("fourteen");
    if (n == 15) printf("fifteen");
    if (n == 16) printf("sixteen");
    if (n == 17) printf("seventeen");
    if (n == 18) printf("eighteen");
    if (n == 19) printf("nineteen");
  }
  if (a == 2) printf("twenty");
  if (a == 3) printf("thirty");
  if (a == 4) printf("fourty");
  if (a == 5) printf("fifty");
  if (a == 6) printf("sixty");
  if (a == 7) printf("seventy");
  if (a == 8) printf("eighty");
  if (a == 9) printf("ninety");
  if (b == 1 && a != 1 && a != 0) printf("-one");
  if (b == 2 && a != 1 && a != 0) printf("-two");
  if (b == 3 && a != 1 && a != 0) printf("-three");
  if (b == 4 && a != 1 && a != 0) printf("-four");
  if (b == 5 && a != 1 && a != 0) printf("-five");
  if (b == 6 && a != 1 && a != 0) printf("-six");
  if (b == 7 && a != 1 && a != 0) printf("-seven");
  if (b == 8 && a != 1 && a != 0) printf("-eight");
  if (b == 9 && a != 1 && a != 0) printf("-nine");
  if (b == 1 && a == 0) printf("one");
  if (b == 2 && a == 0) printf("two");
  if (b == 3 && a == 0) printf("three");
  if (b == 4 && a == 0) printf("four");
  if (b == 5 && a == 0) printf("five");
  if (b == 6 && a == 0) printf("six");
  if (b == 7 && a == 0) printf("seven");
  if (b == 8 && a == 0) printf("eight");
  if (b == 9 && a == 0) printf("nine");
  if (a == 0 && b == 0) printf("zero");
  return 0;
}
