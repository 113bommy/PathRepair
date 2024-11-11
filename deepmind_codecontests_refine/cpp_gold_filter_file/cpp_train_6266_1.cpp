#include <bits/stdc++.h>
using namespace std;
int n;
void solve() {
  int x = 2, y = 1;
  while (x < n && y < n) {
    x = x + y + 1;
    y = (x - y - 1) * 2 + 1;
  }
  printf("%d\n", n == x || n == y);
}
int main() {
  cin >> n;
  solve();
  return 0;
}
