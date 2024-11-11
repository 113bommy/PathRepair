#include <bits/stdc++.h>
using namespace std;
const int MAXN = 5e5 + 5;
void solve() {
  long long a;
  cin >> a;
  unsigned long long x = 1;
  for (int i = 0; i < 17; i++) {
    x = (x * 10 + a) % a;
  }
  x = (x * 45 + a) % a;
  x = (x * 18 + a) % a;
  long long res = 1;
  for (int i = 0; i < 18; i++) {
    res *= 10;
  }
  res--;
  if (x == a) {
    printf("1 %I64d", res);
    return;
  }
  x = a - x;
  printf("%I64d %I64d", x, x + res);
}
int main() {
  int t = 1;
  while (t--) {
    solve();
  }
  return 0;
}
