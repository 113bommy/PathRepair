#include <bits/stdc++.h>
using namespace std;
const long long Len = 1e5 + 5;
long long a, b, x, y, mula, mulb;
long long num[2][2];
long long qpow(long long a, long long b) {
  long long res = 1;
  while (b) {
    res = res * a;
    b = b >> 1;
    a = a * a;
  }
  return res;
}
void Print(long long numa, long long numb, long long A, long long B) {
  long long twoA = 0, twoB = 0, threeA = 0, threeB = 0;
  long long usea = A, useb = B;
  while (usea % 3 == 0) usea = usea / 3, threeA++;
  while (useb % 3 == 0) useb = useb / 3, threeB++;
  while (numb && usea * 3 <= A && threeA) {
    numb--;
    usea *= 3;
    threeA--;
  }
  while (numb && useb * 3 <= B && threeB) {
    numb--;
    useb *= 3;
    threeB--;
  }
  while (usea % 2 == 0) usea = usea / 2, twoA++;
  while (useb % 2 == 0) useb = useb / 2, twoB++;
  long long add = 0;
  while (numa && usea * 2 <= A && add < twoA + threeA) {
    add++;
    numa--;
    usea *= 2;
  }
  add = 0;
  while (numa && useb * 2 <= B && add < twoB + threeB) {
    add++;
    numa--;
    useb *= 2;
  }
  printf("%lld %lld\n", usea, useb);
}
signed main() {
  scanf("%lld %lld %lld %lld", &a, &b, &x, &y);
  mula = a * b;
  mulb = x * y;
  long long pre, A, B;
  pre = mula;
  while (pre % 2 == 0) num[0][0]++, pre /= 2;
  pre = mula;
  while (pre % 3 == 0) num[0][1]++, pre /= 3;
  pre = mulb;
  while (pre % 2 == 0) num[1][0]++, pre /= 2;
  pre = mulb;
  while (pre % 3 == 0) num[1][1]++, pre /= 3;
  A = mula, B = mulb;
  while (A % 2 == 0) A = A >> 1;
  while (A % 3 == 0) A = A / 3;
  while (B % 2 == 0) B = B >> 1;
  while (B % 3 == 0) B = B / 3;
  if (A != B) {
    puts("-1");
    return 0;
  }
  long long ans = 0;
  if (num[0][1] > num[1][1]) {
    num[0][0] += num[0][1] - num[1][1];
    ans += num[0][1] - num[1][1];
    num[0][1] = num[1][1];
    if (num[0][0] > num[1][0]) {
      printf("%lld\n", ans + num[0][0] - num[1][0]);
      num[0][0] = num[1][0];
      Print(num[0][0], num[0][1], a, b);
      Print(num[1][0], num[1][1], x, y);
    } else {
      printf("%lld\n", ans + num[1][0] - num[0][0]);
      num[1][0] = num[0][0];
      Print(num[0][0], num[0][1], a, b);
      Print(num[1][0], num[1][1], x, y);
    }
  } else {
    num[0][0] += num[1][1] - num[0][1];
    ans += num[1][1] - num[0][1];
    num[1][1] = num[0][1];
    if (num[0][0] > num[1][0]) {
      printf("%lld\n", ans + num[0][0] - num[1][0]);
      num[0][0] = num[1][0];
      Print(num[0][0], num[0][1], a, b);
      Print(num[1][0], num[1][1], x, y);
    } else {
      printf("%lld\n", ans + num[1][0] - num[0][0]);
      num[1][0] = num[0][0];
      Print(num[0][0], num[0][1], a, b);
      Print(num[1][0], num[1][1], x, y);
    }
  }
  return 0;
}
