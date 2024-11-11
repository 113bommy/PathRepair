#include <bits/stdc++.h>
int main() {
  int n;
  scanf("%d", &n);
  if (n == 2) {
    printf("1\n");
  }
  if (n == 3) {
    printf("1  2\n");
    printf("2 11\n");
  }
  if (n == 4) {
    printf("1  2  3\n");
    printf("2 10 12\n");
    printf("3 12 21\n");
  }
  if (n == 5) {
    printf("1  2  3  4\n");
    printf("2  4 11 13\n");
    printf("3 11 14 22\n");
    printf("4 13 22 31\n");
  }
  if (n == 6) {
    printf("1  2  3  4  5\n");
    printf("2  4 10 12 14\n");
    printf("3 10 13 20 23\n");
    printf("4 12 20 24 32\n");
    printf("5 14 23 32 41\n");
  }
  if (n == 7) {
    printf("1  2  3  4  5  6\n");
    printf("2  4  6 11 13 15\n");
    printf("3  6 12 15 21 24\n");
    printf("4 11 15 22 26 33\n");
    printf("5 13 21 26 34 42\n");
    printf("6 15 24 33 42 51\n");
  }
  if (n == 8) {
    printf("1  2  3  4  5  6  7\n");
    printf("2  4  6 10 12 14 16\n");
    printf("3  6 11 14 17 22 25\n");
    printf("4 10 14 20 24 30 34\n");
    printf("5 12 17 24 31 36 43\n");
    printf("6 14 22 30 36 44 52\n");
    printf("7 16 25 34 43 52 61\n");
  }
  if (n == 9) {
    printf("1  2  3  4  5  6  7  8\n");
    printf("2  4  6  8 11 13 15 17\n");
    printf("3  6 10 13 16 20 23 26\n");
    printf("4  8 13 17 22 26 31 35\n");
    printf("5 11 16 22 27 33 38 44\n");
    printf("6 13 20 26 33 40 46 53\n");
    printf("7 15 23 31 38 46 54 60\n");
    printf("8 17 26 35 44 53 60 71\n");
  }
  if (n == 10) {
    printf("1  2  3  4  5  6  7  8  9\n");
    printf("2  4  6  8 10 12 14 16 18\n");
    printf("3  6  9 12 15 18 21 24 27\n");
    printf("4  8 12 16 20 24 28 32 36\n");
    printf("5 10 15 20 25 30 35 40 45\n");
    printf("6 12 18 24 30 36 42 48 54\n");
    printf("7 14 21 28 35 42 49 56 63\n");
    printf("8 16 24 32 40 48 56 64 72\n");
    printf("9 18 27 36 45 54 63 72 81\n");
  }
}
