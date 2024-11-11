#include <bits/stdc++.h>
using namespace std;
int main() {
  int n = 0;
  scanf("%d", &n);
  if (n == 3)
    printf("1");
  else if (n == 4)
    printf("4");
  else if (n == 5)
    printf("9");
  else if (n == 6)
    printf("16");
  else {
    long long int result =
        ((long long int)2 * ((long long int)n - (long long int)2)) +
        (((long long int)n - (long long int)3) - (long long int)1);
    for (int I = 3; I < n; I++) {
      result =
          result + (((long long int)I - (long long int)1) - (long long int)2);
      result =
          result + ((long long int)n - ((long long int)I + (long long int)1));
    }
    printf("%I64d", result);
  }
  return 0;
}
