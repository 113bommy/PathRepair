#include <bits/stdc++.h>
using namespace std;
long long int a, b, hasil = 0;
int main() {
  scanf("%lld %lld", &a, &b);
  if (a < b) {
    printf("0\n");
  } else if (a == b) {
    printf("Infinity\n");
  } else {
    long long int temp = a - b;
    long long int batas = (long long int)sqrt((double)temp);
    for (long long int i = 1; i <= batas; i++) {
      if (a % i == b) {
        hasil++;
      }
      if (temp / i != i && (a % (temp / i) == b)) {
        hasil++;
      }
    }
    printf("%lld\n", hasil);
  }
  return 0;
}
