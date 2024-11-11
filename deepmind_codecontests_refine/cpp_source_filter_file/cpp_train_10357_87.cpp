#include <bits/stdc++.h>
using namespace std;
int a[102];
bool print1(int x) {
  if (x == 0) {
    return false;
  }
  switch (x) {
    case 1:
      printf("ten");
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
  return true;
}
void print2(int x) {
  switch (x) {
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
}
void solve() {
  int n;
  scanf("%d", &n);
  if (n == 0) {
    printf("zero");
  }
  if (n >= 11 && n < 20) {
    n = n % 10;
    switch (n) {
      case 1:
        printf("eleven");
        break;
      case 2:
        printf("twelve");
        break;
      case 3:
        printf("thirteen");
        break;
      case 4:
        printf("fourteen");
        break;
      case 5:
        printf("fifteen");
        break;
      case 6:
        printf("sixteen");
        break;
      case 7:
        printf("seventeen");
        break;
      case 8:
        printf("eighteen");
        break;
      case 9:
        printf("nineteen");
        break;
    }
    return;
  }
  print1(n / 10);
  if (n % 10 > 0 && n / 10 > 0) {
    printf("-");
  }
  print2(n % 10);
}
int main() {
  solve();
  return 0;
}
