#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  scanf("%d", &n);
  int n1 = n / 10;
  int n2 = n % 10;
  if (n1 < 2) {
    if (n == 0) printf("zero");
    if (n == 1) printf("one");
    if (n == 2) printf("two");
    if (n == 3) printf("three");
    if (n == 4) printf("four");
    if (n == 5) printf("five");
    if (n == 6) printf("six");
    if (n == 7) printf("seven");
    if (n == 8) printf("eight");
    if (n == 9) printf("nine");
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
  } else if (n1 > 1) {
    if (n1 == 2) printf("twenty");
    if (n1 == 3) printf("thirty");
    if (n1 == 4) printf("forty");
    if (n1 == 5) printf("fifty");
    if (n1 == 6) printf("sixty");
    if (n1 == 7) printf("seventy");
    if (n1 == 8) printf("eighty");
    if (n1 == 9) printf("ninety");
    if (n2 != 0) printf("-");
    if (n2 == 1) printf("one");
    if (n2 == 2) printf("two");
    if (n2 == 3) printf("three");
    if (n2 == 4) printf("four");
    if (n2 == 5) printf("five");
    if (n2 == 6) printf("six");
    if (n2 == 7) printf("seven");
    if (n2 == 8) printf("eight");
    if (n2 == 9) printf("nine");
  }
  return 0;
}
