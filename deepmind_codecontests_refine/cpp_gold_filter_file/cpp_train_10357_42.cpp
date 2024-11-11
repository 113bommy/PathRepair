#include <bits/stdc++.h>
int main() {
  int s;
  scanf("%d", &s);
  if (s > 10 && s < 20) {
    if (s % 11 == 0) {
      printf("eleven");
    }
    if (s % 12 == 0) {
      printf("twelve");
    }
    if (s % 13 == 0) {
      printf("thirteen");
    }
    if (s % 14 == 0) {
      printf("fourteen");
    }
    if (s % 15 == 0) {
      printf("fifteen");
    }
    if (s % 16 == 0) {
      printf("sixteen");
    }
    if (s % 17 == 0) {
      printf("seventeen");
    }
    if (s % 18 == 0) {
      printf("eighteen");
    }
    if (s % 19 == 0) {
      printf("nineteen");
    }
  } else {
    if (s == 0) {
      printf("zero");
    } else {
      if (s == 10) {
        printf("ten");
      }
      if (s / 10 == 2) {
        printf("twenty");
      }
      if (s / 10 == 3) {
        printf("thirty");
      }
      if (s / 10 == 4) {
        printf("forty");
      }
      if (s / 10 == 5) {
        printf("fifty");
      }
      if (s / 10 == 6) {
        printf("sixty");
      }
      if (s / 10 == 7) {
        printf("seventy");
      }
      if (s / 10 == 8) {
        printf("eighty");
      }
      if (s / 10 == 9) {
        printf("ninety");
      }
      if (s > 10 && s % 10 != 0) {
        printf("-");
      }
      if (s % 10 == 1) {
        printf("one");
      }
      if (s % 10 == 2) {
        printf("two");
      }
      if (s % 10 == 3) {
        printf("three");
      }
      if (s % 10 == 4) {
        printf("four");
      }
      if (s % 10 == 5) {
        printf("five");
      }
      if (s % 10 == 6) {
        printf("six");
      }
      if (s % 10 == 7) {
        printf("seven");
      }
      if (s % 10 == 8) {
        printf("eight");
      }
      if (s % 10 == 9) {
        printf("nine");
      }
    }
  }
}
