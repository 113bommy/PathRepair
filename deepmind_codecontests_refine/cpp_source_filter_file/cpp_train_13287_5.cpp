#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, a, b;
  cin >> n >> a >> b;
  int l = 1, r = 1000;
  while (l != r) {
    int x = (l + r + 1) / 2;
    int can = a / x + b / x;
    if (can >= n)
      l = x;
    else
      r = x - 1;
  }
  cout << l << '\n';
  return (0);
}
