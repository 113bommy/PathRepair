#include <bits/stdc++.h>
int main() {
  int number, c, d = 0, e = 0;
  char month[20];
  scanf("%s", &month);
  scanf("%d", &number);
  if (strcmp(month, "January") == 0) {
    d = 1;
  } else if (strcmp(month, "February") == 0) {
    d = 2;
  } else if (strcmp(month, "March") == 0) {
    d = 3;
  } else if (strcmp(month, "April") == 0) {
    d = 4;
  } else if (strcmp(month, "May") == 0) {
    d = 5;
  } else if (strcmp(month, "June") == 0) {
    d = 6;
  } else if (strcmp(month, "July") == 0) {
    d = 7;
  } else if (strcmp(month, "August") == 0) {
    d = 8;
  } else if (strcmp(month, "September") == 0) {
    d = 9;
  } else if (strcmp(month, "October") == 0) {
    d = 10;
  } else if (strcmp(month, "November") == 0) {
    d = 11;
  } else if (strcmp(month, "December") == 0) {
    d = 12;
  }
  if (number % 12 == 0) {
    printf("%s", month);
  } else if (number > 12) {
    number = number % 12;
    e = number + d;
    if (e > 12) {
      e = e % 12;
    }
  } else if (number < 12) {
    e = number + d;
    if (e > 12) {
      e = e % 12;
    }
  }
  if (e == 1) {
    printf("January");
  } else if (e == 2) {
    printf("February");
  } else if (e == 3) {
    printf("March");
  } else if (e == 4) {
    printf("April");
  } else if (e == 5) {
    printf("May");
  } else if (e == 6) {
    printf("June");
  } else if (e == 7) {
    printf("July");
  } else if (e == 8) {
    printf("August");
  } else if (e == 9) {
    printf("September");
  } else if (e == 10) {
    printf("October");
  } else if (e == 11) {
    printf("November");
  } else if (e == 12) {
    printf("December");
  }
  return 0;
}
