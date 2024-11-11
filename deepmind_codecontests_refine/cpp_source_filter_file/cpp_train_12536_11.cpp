#include <bits/stdc++.h>
using namespace std;
int read() {
  int x;
  scanf("%d", &x);
  return x;
}
int readln() {
  int x;
  scanf("%d\n", &x);
  return x;
}
const int MAX_N = 2 * int(1e5) + 5;
long long c[2];
int main() {
  int n = read();
  long long ans = 0;
  c[0] = c[1] = 0;
  for (int i = 1; i <= n; ++i) {
    int x = read();
    if (x == 1) ans += c[0];
    ++c[x];
  }
  printf("%lld\n", ans);
  return 0;
}
