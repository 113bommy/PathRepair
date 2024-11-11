#include <bits/stdc++.h>
using namespace std;
void print_digit(int a);
void print_dahai(int a);
int main() {
  int d;
  scanf("%d", &d);
  if (d < 10) {
    print_digit(d);
    return 0;
  }
  if (9 < d && d < 20) {
    switch (d) {
      case 10:
        printf("ten");
        break;
      case 11:
        printf("eleven");
        break;
      case 12:
        printf("twelve");
        break;
      case 13:
        printf("thirteen");
        break;
      case 14:
        printf("fourteen");
        break;
      case 15:
        printf("fifteen");
        break;
      case 16:
        printf("sixteen");
        break;
      case 17:
        printf("seventeen");
        break;
      case 18:
        printf("eighteen");
        break;
      case 19:
        printf("nineteen");
        break;
    }
    return 0;
  } else {
    int a = floor(d / 10);
    print_dahai(a);
    int b = d % 10;
    if (b != 0) {
      printf("-");
      print_digit(b);
    }
  }
  return 0;
}
void print_digit(int a) {
  switch (a) {
    case 0:
      printf("zero");
      break;
    case 1:
      printf("one");
      break;
    case 2:
      printf("two");
      break;
    case 3:
      printf("three");
      break;
    case 4:
      printf("four");
      break;
    case 5:
      printf("five");
      break;
    case 6:
      printf("six");
      break;
    case 7:
      printf("seven");
      break;
    case 8:
      printf("eight");
      break;
    case 9:
      printf("nine");
      break;
  }
  return;
}
void print_dahai(int a) {
  switch (a) {
    case 0:
      break;
    case 2:
      printf("twenty");
      break;
    case 3:
      printf("thirty");
      break;
    case 4:
      printf("forty");
      break;
    case 5:
      printf("fivty");
      break;
    case 6:
      printf("sixty");
      break;
    case 7:
      printf("seventy");
      break;
    case 8:
      printf("eighty");
      break;
    case 9:
      printf("ninety");
      break;
  }
  return;
}
