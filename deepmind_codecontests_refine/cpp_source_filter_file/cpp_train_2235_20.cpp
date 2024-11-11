#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, temp, len(0), maks(0), dum;
  scanf("%d %d", &a, &b);
  if (a < b) {
    temp = a;
    a = b;
    b = temp;
  }
  temp = a;
  while (temp != 0) {
    if ((temp % 10) > maks) maks = temp % 10;
    temp /= 10;
  }
  temp = b;
  while (temp != 0) {
    if ((temp % 10) > maks) maks = temp % 10;
    temp /= 10;
  }
  ++maks;
  while (a != 0) {
    dum = (a % 10) + (b % 10);
    temp = 0;
    a /= 10;
    b /= 10;
    if (dum >= maks) temp = 1;
    ++len;
  }
  if (temp != 0) ++len;
  printf("%d\n", len);
  return 0;
}
