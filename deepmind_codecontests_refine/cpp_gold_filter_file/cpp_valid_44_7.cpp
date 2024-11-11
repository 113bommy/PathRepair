#include <bits/stdc++.h>
using namespace std;
inline void solve() {
  int c, d;
  scanf("%d%d", &c, &d);
  if (c == d) {
    puts(!c ? "0" : "1");
    return;
  }
  if ((c + d) % 2) {
    puts("-1");
    return;
  }
  puts("2");
}
int main() {
  int tt;
  scanf("%d", &tt);
  for (int t = 0; t < tt; ++t) {
    solve();
  }
  return 0;
}
