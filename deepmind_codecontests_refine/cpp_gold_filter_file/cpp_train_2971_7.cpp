#include <bits/stdc++.h>
using namespace std;
int main() {
  int arr[6];
  for (int(n) = 0; n < (int)6; n++) {
    scanf("%d", &arr[n]);
    ;
  }
  long long a = 1;
  long long b = 1;
  for (int m = 0; m < 3; m++) {
    a *= arr[2 * m];
    b *= arr[2 * m + 1];
  }
  if (a > 0 && b > a) {
    puts("Ron");
    return 0;
  }
  if (arr[3] != 0) {
    for (int n = 0; n < 6; n += 2) {
      if (arr[n] == 0) {
        int start = n + 1;
        while (start != 3) {
          if (arr[start] == 0) {
            break;
          }
          start = (start + 1) % 6;
        }
        if (start == 3) {
          puts("Ron");
          return 0;
        }
      }
    }
  }
  puts("Hermione");
  return 0;
}
