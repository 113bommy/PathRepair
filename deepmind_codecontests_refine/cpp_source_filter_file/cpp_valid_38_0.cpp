#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
int a[N];
long long n, t;
int main() {
  scanf("%lld", &t);
  while (t--) {
    scanf("%lld", &n);
    long long x = n / 6, y = n % 6;
    long long t = 0;
    if (y == 5) {
      t = (x - 2) * 15 + 35;
    } else if (y >= 3 && y < 5) {
      t = (x - 1) * 15 + 25;
    } else if (y >= 1 && y < 3) {
      t = (x - 1) * 15 + 20;
    } else if (y == 0) {
      t = x * 15;
    }
    if (n <= 6) {
      t = 15;
    }
    printf("%lld\n", t);
  }
  return 0;
}
