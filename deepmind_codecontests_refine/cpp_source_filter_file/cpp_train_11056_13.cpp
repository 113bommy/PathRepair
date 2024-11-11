#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long x, y;
  scanf("%lld %lld", &x, &y);
  for (int step = 0; step < 41; ++step) {
    if (x >= y) {
      puts("YES");
      return;
    }
    x -= x % 2;
    x *= 3;
    x /= 2;
  }
  puts("NO");
}
int main() {
  int qq;
  scanf("%d", &qq);
  while (qq--) solve();
  return 0;
}
