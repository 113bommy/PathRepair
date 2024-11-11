#include <bits/stdc++.h>
using namespace std;
int dir1[8][2] = {1, 2, 2, 1, 2, -1, 1, -2, -1, 2, -2, 1, -1, -2, -2, -1};
int dir2[4][2] = {1, 0, 0, 1, -1, 0, 0, -1};
int dir3[8][2] = {1, 0, 0, 1, -1, 0, 0, -1, 1, 1, 1, -1, -1, 1, -1, -1};
int gcd(int x, int y) { return y == 0 ? x : gcd(y, x % y); }
bool Isleap(int year) {
  if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0) return true;
  return false;
}
bool isPrime(int x) {
  if (x == 1)
    return false;
  else if (x == 2)
    return true;
  for (int i = 2; i <= sqrt(x * 1.0); ++i) {
    if (x % i == 0) return false;
  }
  return true;
}
int sqr(int x) { return x * x; }
int main() {
  int n;
  while (~scanf("%d", &n)) {
    printf("%d\n", 6 * n * (n - 1) - 1);
  }
  return 0;
}
