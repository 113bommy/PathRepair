#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 50;
const int inf = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
long long a, b, c, cnt = 0;
int main() {
  cin >> a >> b >> c;
  if (a > b) swap(a, b);
  if (b >= c) {
    printf("0\n");
    return 0;
  }
  if (a <= 0 && b <= 0 && b < c) {
    printf("-1\n");
    return 0;
  }
  if (a <= 0 && b > 0) {
    cnt = (-a) / b + 1;
    a += cnt * b;
  }
  while (b < c) {
    b += a;
    a = b - a;
    cnt++;
  }
  printf("%I64d\n", cnt);
  return 0;
}
