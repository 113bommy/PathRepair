#include <bits/stdc++.h>
using namespace std;
int T;
long long a, b;
bool check(long long x, long long y) {
  if (x == 0 || y == 0) return false;
  if (x < y) swap(x, y);
  if (!check(y, x % y)) return true;
  return x / y % (y + 1) % 2 == 0;
}
int main() {
  scanf("%d", &T);
  while (T--) {
    scanf("%I64d%I64d", &a, &b);
    printf("%\n", check(a, b) ? "First" : "Second");
  }
  return 0;
}
