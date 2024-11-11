#include <bits/stdc++.h>
using namespace std;
long long a, b, x;
bool solve(long long a, long long b) {
  if (a > b) swap(a, b);
  x = b - a;
  if (b < x) return false;
  b -= 2 * x;
  a -= x;
  return a % 3 == 0;
}
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    scanf("%lld %lld", &a, &b);
    if (solve(a, b))
      printf("YES\n");
    else
      printf("NO\n");
  }
}
