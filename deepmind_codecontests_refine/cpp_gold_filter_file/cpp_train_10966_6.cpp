#include <bits/stdc++.h>
using namespace std;
int xx[] = {0, 0, 1, -1, 1, -1, 1, -1};
int yy[] = {1, -1, 0, 0, 1, -1, -1, 1};
inline long long MAX(long long a, long long b) { return (a > b) ? a : b; }
inline long long MIN(long long a, long long b) { return (a > b) ? b : a; }
inline double dis(double ax, double ay, double bx, double by) {
  return ((ax - bx) * (ax - bx) + (ay - by) * (ay - by));
}
long long pwr(long long x, long long n) {
  if (n == 0) return 1;
  if (n == 1) return x;
  long long a = pwr(x, n / 2);
  a = a * a;
  if (n % 2) a *= x;
  return a;
}
int main() {
  int kase, kas = 0, a, b, n, k;
  scanf("%d %d", &k, &n);
  a = n / k;
  b = n % k;
  if (a > 2)
    printf("0\n");
  else {
    if (n % k == 0 && a == 2)
      printf("%d\n", k);
    else
      printf("%d\n", k - b);
  }
  return 0;
}
