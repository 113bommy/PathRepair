#include <bits/stdc++.h>
using namespace std;
int n, i;
void retarded(int x, int y) {
  printf("%d %d\n", x, y);
  if (!--n) exit(0);
}
void fuck() {
  retarded(0, 0);
  while (++i) {
    retarded(i, 0);
    retarded(0, i);
    retarded(-i, 0);
    retarded(0, -i);
  }
}
int32_t main() {
  cin >> n;
  fuck();
  return 0;
}
