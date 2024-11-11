#include <bits/stdc++.h>
void solve() {
  int P;
  scanf("%d", &P);
  int a, b;
  a = P - 1;
  b = (P - 1) / 2;
  printf("%d %d\n", b, a);
}
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    solve();
  }
}
