#include <bits/stdc++.h>
using namespace std;
int MAX(int a, int b) { return (a > b) ? a : b; }
double MAX(double a, double b) { return (a > b) ? a : b; }
int MIN(int a, int b) { return (a < b) ? a : b; }
int GCD(int a, int b) { return b ? GCD(b, a % b) : a; }
unsigned long long int GCD(unsigned long long int a, unsigned long long int b) {
  return b ? GCD(b, a % b) : a;
}
int LCM(int a, int b) { return a / GCD(a, b) * b; }
void swop(double &a, double &b) {
  double c = a;
  a = b;
  b = c;
}
void swop(int &a, int &b) {
  a = a ^ b;
  b = a ^ b;
  a = a ^ b;
}
long long int u(long long int a) {
  if (a >= 0) return a;
  return a * (-1);
}
int main() {
  int t, i, r;
  unsigned long long int a1 = 0, a2 = 0, b1 = 0, b2 = 0, x, y;
  scanf("%d", &t);
  for (i = 0; i < t; i++) {
    cin >> r >> x >> y;
    if (r == 1) {
      a1 += x;
      a2 += y;
    } else {
      b1 += x;
      b2 += y;
    }
  }
  if (a1 >= a2) {
    printf("LIVE\n");
  } else {
    printf("DEAD");
  }
  if (b1 >= b2) {
    printf("LIVE");
  } else {
    printf("DEAD");
  }
  return 0;
}
