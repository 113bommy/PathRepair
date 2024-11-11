#include <bits/stdc++.h>
using namespace std;
int main() {
  long long k;
  char n[100010];
  scanf("%lld", &k);
  scanf("%s", n);
  long long sum = 0LL, count[10];
  fill(count, count + 10, 0LL);
  long long i = 0;
  while (i < strlen(n)) {
    sum = sum + n[i] - 48;
    count[n[i] - 48]++;
    i++;
  }
  long long change = 0LL;
  if (k > sum) {
    i = 0LL;
    while (sum != k) {
      if (k - sum >= count[i] * (9LL - i) && i != 9) {
        change = change + count[i];
        sum = sum + (9LL - i) * count[i];
      } else if (k - sum <= count[i] * (9LL - i) && i != 9) {
        change = change + ceil(((double)k - sum) / (9 - i));
        sum = k;
      }
      i++;
    }
    printf("%lld", change);
  } else
    printf("0");
  return 0;
}
