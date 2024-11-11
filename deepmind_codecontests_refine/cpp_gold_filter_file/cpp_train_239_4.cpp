#include <bits/stdc++.h>
using namespace std;
int solve(long long a, long long b) {
  if (a == 0 || b == 0) return 0;
  if (a > b) swap(a, b);
  if (solve(a, b % a) == 0) return 1;
  long long k = (b / a - 1) % (a + 1);
  return k & 1 || k == a;
  return 0;
}
int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    long long a, b;
    scanf("%lld%lld", &a, &b);
    printf(solve(a, b) ? "First\n" : "Second\n");
  }
  return 0;
}
