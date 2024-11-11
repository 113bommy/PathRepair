#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int r, b, x, y;
  cin >> r >> b;
  for (int a = 0; a < r + b; a++) cin >> x >> y;
  printf(r <= b ? "Yes" : "No");
  return 0;
}
