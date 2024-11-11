#include <bits/stdc++.h>
using namespace std;
bool solve(long long a, long long b) {
  if (a > b) swap(a, b);
  if (!a) return 0;
  if (!solve(a, b % a)) return 1;
  long long x = b / a;
  if (!(a & 1))
    return !((x % (a + 1)) & 1);
  else
    return !(x & 1);
}
int main() {
  int t;
  scanf("%d", &t);
  for (int it = 0; it < t; it++) {
    long long a, b;
    scanf("%I64d%I64d", &a, &b);
    if (a > b) swap(a, b);
    printf(solve(a, b) ? "First\n" : "Second\n");
  }
  return 0;
}
