#include <bits/stdc++.h>
using namespace std;
using INT = long long;
int calc(int a, int n, int p) {
  int k = (INT)a * n / p;
  if (k == 0) return max(a, p - a * n);
  if (p / a * a - a > a * n % p) k--;
  return calc(a - p % a, k, a);
}
int main() {
  int T;
  cin >> T;
  while (T--) {
    int a, n, p, h;
    scanf("%d %d %d %d", &a, &n, &p, &h);
    a %= p;
    if ((INT)a * n <= p) {
      if (a <= h)
        puts("YES");
      else
        puts("NO");
      continue;
    }
    if (calc(a, n, p) <= h)
      puts("YES");
    else
      puts("NO");
  }
}
