#include <bits/stdc++.h>
using namespace std;
int m, n;
int sum(int bs, int n) {
  int s = 0;
  while (n) {
    s += n % bs;
    n /= bs;
  }
  return s;
}
int gcd(int a, int b) {
  if (a % b == 0) return b;
  return gcd(b, a % b);
}
int main() {
  int t, tc, x, y, z;
  int i, j, l, h;
  char ch;
  cin >> n;
  int total = 0;
  for (i = 2; i < n; i++) total += sum(i, n);
  x = total;
  y = n - 2;
  int g = gcd(x, y);
  x /= g;
  y /= g;
  printf("%d/%d\n", x, y);
  return 0;
}
