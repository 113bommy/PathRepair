#include <bits/stdc++.h>
using namespace std;
int a, b;
void precalc() {}
bool read() {
  if (scanf("%d%d", &a, &b) < 2) {
    return false;
  }
  return true;
}
void solve() {
  int even = 0, odd = 0;
  if (!a && !b) {
    printf("NO\n");
    return;
  }
  for (int i = 1;; i++) {
    if (i % 2 == 1)
      odd++;
    else
      even++;
    if (even == a && odd == b) {
      printf("YES\n");
      return;
    }
    if (even > a || odd > b) break;
  }
  even = 0;
  odd = 0;
  for (int i = 2;; i++) {
    if (i % 2 == 1)
      odd++;
    else
      even++;
    if (even == a && odd == b) {
      printf("YES\n");
      return;
    }
    if (even > a || odd > b) break;
  }
  printf("NO\n");
}
int main() {
  precalc();
  while (read()) {
    solve();
  }
  return 0;
}
