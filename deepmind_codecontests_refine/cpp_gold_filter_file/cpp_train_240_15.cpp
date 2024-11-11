#include <bits/stdc++.h>
using namespace std;
int sol(long long a, long long b) {
  if (a > b) swap(a, b);
  if (a == 0 || b == 0) return 0;
  if (b % a == 0) return 1;
  int ret = !sol(a, b % a);
  if (ret) return 1;
  b = b / a;
  if (a & 1) return b % 2 == 0;
  b--;
  return b % (a + 1) == a || b % (a + 1) % 2 != 0;
}
int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    long long a, b;
    scanf("%I64d%I64d", &a, &b);
    puts(sol(a, b) ? "First" : "Second");
  }
  return 0;
}
