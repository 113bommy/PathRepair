#include <bits/stdc++.h>
using namespace std;
int _I() {
  int x;
  scanf("%d", &x);
  return x;
}
struct node {
  int h, a, s;
  node() {}
  node(int x, int y, int z) {
    h = x;
    a = y;
    s = z;
  }
};
void solve() {
  int n = _I();
  int k = _I();
  printf("%d ", (n == k || k == 0) ? 0 : 1);
  if (n / 3 <= k) {
    int x = n - k;
    printf("%d\n", k == 0 ? k : x);
  } else
    printf("%d\n", 2 * k);
}
int main() {
  solve();
  return 0;
}
