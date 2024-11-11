#include <bits/stdc++.h>
using namespace std;
string a;
int n, sum1, sum2, up1, up2;
int main() {
  cin >> n >> a;
  for (int i = 0; i < n / 2; i++) {
    if (a[i] == '?')
      up1++;
    else
      sum1 += a[i] - '0';
  }
  for (int i = n / 2; i < n; i++) {
    if (a[i] == '?')
      up2++;
    else
      sum2 += a[i] - '0';
  }
  if (up1 >= up2) {
    int d = up1 - up2;
    if (sum1 > sum2) {
      printf("Monocarp");
      return 0;
    }
    if ((sum2 - sum1) % 9 == 0 && (sum2 - sum1) / 9 == d) {
      printf("Bicarp");
      return 0;
    }
    printf("Monocarp");
    return 0;
  }
  int d = up2 - up1;
  if (sum2 > sum1) {
    printf("Monocarp");
    return 0;
  }
  if ((sum1 - sum2) % 9 == 0 && (sum1 - sum2) / 9 == d) {
    printf("Bicarp");
    return 0;
  }
  printf("Monocarp");
  return 0;
}
