#include <bits/stdc++.h>
using namespace std;
const int modd = 1e9 + 7;
int n, sum, x;
long long ans;
long long a, b, c;
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &x);
    if (x == 1) sum++;
  }
  ans = 1;
  for (int i = sum + 1; i <= n; i++) ans = ans * i % modd;
  if (sum >= 2) {
    a = b = 1;
    for (int i = 2; i <= sum; i++) {
      c = b + a * (i - 1);
      c %= modd;
      a = b;
      b = c;
    }
  }
  ans = ans * c % modd;
  printf("%I64d\n", ans);
  return 0;
}
