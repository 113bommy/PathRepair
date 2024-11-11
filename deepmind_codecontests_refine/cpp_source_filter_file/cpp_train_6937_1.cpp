#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, pos, l, r;
  cin >> n >> pos >> l >> r;
  int esquerda = l - 1;
  int direita = r + 1;
  int ans = 0;
  if (esquerda != 0 && direita != n) {
    ans = max(pos - l, l - pos) + r - l + 2;
    ans = min(ans, max(pos - r, r - pos) + r - l + 2);
  } else if (esquerda > 0)
    ans = max(pos - l, l - pos) + 1;
  else if (direita <= n)
    ans = max(pos - r, r - pos) + 1;
  cout << ans << endl;
  return 0;
}
