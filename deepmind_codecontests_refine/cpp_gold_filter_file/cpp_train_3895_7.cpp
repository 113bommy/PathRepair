#include <bits/stdc++.h>
using namespace std;
using LL = long long;
bool test(int a, int b, int n, int m) {
  LL x = a * LL(n);
  if (x < b) return max(a, b - a * n) <= m;
  return test(b % a, a, (x + a + b % a) / b - 1, m);
}
int main() {
  int cs, a, n, p, h;
  scanf("%d", &cs);
  while (cs--) {
    scanf("%d%d%d%d", &a, &n, &p, &h);
    a %= p;
    puts((a * LL(n) < p ? a <= h : test(a, p, n, h)) ? "YES" : "NO");
  }
}
