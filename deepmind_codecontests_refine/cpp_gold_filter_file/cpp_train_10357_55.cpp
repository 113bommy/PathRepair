#include <bits/stdc++.h>
using namespace std;
int main() {
  int s, i, j;
  scanf("%d", &s);
  if (s < 10) {
    if (s == 0)
      printf("zero");
    else if (s == 1)
      printf("one");
    else if (s == 2)
      printf("two");
    else if (s == 3)
      printf("three");
    else if (s == 4)
      printf("four");
    else if (s == 5)
      printf("five");
    else if (s == 6)
      printf("six");
    else if (s == 7)
      printf("seven");
    else if (s == 8)
      printf("eight");
    else if (s == 9)
      printf("nine");
  } else if (s < 20) {
    i = s % 10;
    if (i == 0)
      printf("ten");
    else if (i == 1)
      printf("eleven");
    else if (i == 2)
      printf("twelve");
    else if (i == 3)
      printf("thirteen");
    else if (i == 4)
      printf("fourteen");
    else if (i == 5)
      printf("fifteen");
    else if (i == 6)
      printf("sixteen");
    else if (i == 7)
      printf("seventeen");
    else if (i == 8)
      printf("eighteen");
    else if (i == 9)
      printf("nineteen");
  } else {
    i = s % 10;
    j = s / 10;
    if (j == 2)
      printf("twenty");
    else if (j == 3)
      printf("thirty");
    else if (j == 4)
      printf("forty");
    else if (j == 5)
      printf("fifty");
    else if (j == 6)
      printf("sixty");
    else if (j == 7)
      printf("seventy");
    else if (j == 8)
      printf("eighty");
    else if (j == 9)
      printf("ninety");
    if (i != 0) {
      if (i == 1)
        printf("-one");
      else if (i == 2)
        printf("-two");
      else if (i == 3)
        printf("-three");
      else if (i == 4)
        printf("-four");
      else if (i == 5)
        printf("-five");
      else if (i == 6)
        printf("-six");
      else if (i == 7)
        printf("-seven");
      else if (i == 8)
        printf("-eight");
      else if (i == 9)
        printf("-nine");
    }
  }
  return 0;
}
